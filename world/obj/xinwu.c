//token.c
// modified 8-13-97 pickle
 
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;
#include <ansi.h>

#define SYN_CREATE  "指令格式：\tcreate <山洞名称> (<山洞代号>) for <洞主>。\n例：\t\tcreate 水帘洞 (shuilian dong) for wukong\n"

void create()
{
    set_name("镇洞之宝", ({ "zhendong bao", "token", "bao", "zhendong" }) );
    set("unit", "个");
    set("leader_title", "洞主");
    seteuid(getuid());
}

string short()
{
    string guild;
 
    if( stringp(query("short")) || !stringp(guild = query("guild_name")) )
        return ::short();
    else
        return ::short();
}

string long()
{
    if( stringp(query("long")) )
        return ::long();
    else if ( stringp(query("guild_id"))) return @TEXT
这是一个已经解开封印的镇洞之宝，你可以用如下指令创造属于你自己的山洞：

    modify/xiugai	修改信物的外观、山洞名称等等。
    assign/zhiding	将洞主的位置传给别人。
    dismiss/jiesan	永久解散这个山洞。

TEXT
    ;
    else return @TEXT

这是一个用来让玩家建立山洞时所用的镇洞之宝。
持有此宝之人就是本洞之洞主，具有招募新成员、
开除原有成员、以及更改成员称号等权力及任务。
此宝会自动储存。

在建立新洞之前必须先有一名巫师解除封印，并且
选择第一任洞主（create/jianli）。

TEXT
    ;
}
void init()
{
    if( !environment()->is_character() ) {
	message_vision("$N发出一阵耀眼的光芒，然后消失了。\n", this_object());
	destruct(this_object());
    } else {
	add_action("do_create", "create");
	add_action("do_create", "jianli");
	add_action("do_assign", "assign");
	add_action("do_assign", "zhiding");
	add_action("do_modify", "modify");
	add_action("do_modify", "xiugai");
	add_action("do_dismiss", "dismiss");
	add_action("do_dismiss", "jiesan");
    }
}

string query_autoload() { return query("guild_name"); }

string query_save_file() { return DATA_DIR + "guild/" + query("guild_id"); }

void autoload(string name)
{
    if( !restore() ) {
        if( environment() ) environment()->delete("family");
        destruct(this_object());
    }

}

int do_create(string arg)
{
    int i;
    string guild_id, guild_name, player_name;
    object me=this_player(), guild_leader;

    if( query("unsealed") )
        return notify_fail( query("name") + "的封印已经被解开了。\n");
 
    if( !wizardp(me) )
        return notify_fail(
            "只有巫师能解除此物封印。如果你要创立一个新的山洞，请\n"
            "先找一位巫师做担保人，请他（她）为你解除封印。\n");
 
    if(!arg) return notify_fail(SYN_CREATE);
 
    if( sscanf(arg, "%s (%s) for %s", guild_name, guild_id, player_name)!=3)
	return notify_fail(SYN_CREATE);

    for(i=0; i<strlen(guild_id); i++)
	if( (guild_id[i] < 'a' || guild_id[i] > 'z') && guild_id[i] != '_')
        return notify_fail("<山洞代号>必须由小写英文字母或 '_' 组成。\n");

    if (!objectp(guild_leader=present(player_name, environment(me)))
     || !living (guild_leader))
	return notify_fail("这里没有 "+player_name+"。\n");

    set("guild_id", guild_id);
    set("guild_name", guild_name);
    set("unsealed", 1);
    set("leader", player_name); 

    if(file_size(query_save_file() + __SAVE_EXTENSION__)>=0 )
	restore();
    else {
	log_file("GUILD", 
	    sprintf("%s（%s）于%s（%s）\n\t创"+HIG+"%s（%s）"+NOR+"，"
		    "有"+HIY+"%s（%s）"+NOR+"在场为证。\n\n",
	    guild_leader->query("name"), guild_leader->query("id"),
	    NATURE_D->game_time(), ctime(time()),
	    guild_name, guild_id,
	    me->query("name"), me->query("id")));
	    save();
	    message_vision(HIY"恭喜$N成立了"+guild_name+"("+guild_id+")！\n"NOR, guild_leader);
    }
 
    return 1;
}

int do_assign(string arg)
{
    object ob;
    mapping family;
    string assign_msg;
    object me=this_player();
 
    if( !arg || !objectp(ob = present(arg, environment(me)))
    || !living(ob) ) 
        return notify_fail("你要将洞主之位传给谁？\n");
 
    family = me->query("family");
 
    if( wizardp(me) || (
        mapp(family) && family["family_name"]==(string)query("guild_name")
        && (string)me->query("id")==(string)query("leader")))
    {
        // If this is a new guild, create its family.
        if( !query("leader") )
            ob->create_family(query("guild_name"));
        else {
            family = ob->query("family");
            if( !mapp(family) || (family["family_name"]!=(string)query("guild_name")) )
                return notify_fail( ob->name() + "并不是" + query("guild_name") + "的一员。\n");
        }
        ob->assign_apprentice( query("leader_title"), -1 );
        set("leader", ob->query("id"));
        if( stringp(assign_msg = query("assign_msg")) )
            message_vision(assign_msg, me, ob);
        else
            message_vision(
                "\n$N将" + query("guild_name") + "的" + query("name") + "交给了$n。\n"
                "\n今后$p就是" + query("guild_name") + "的洞主了。\n\n", me, ob);
        move(ob);
        write("Ok.\n");
        return 1;
    } else
        return notify_fail("你没有这种权力。\n");
}

int do_modify(string arg)
{
    string prop, str;
    if( !query("guild_id") ) return 0;
     if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
        return notify_fail("指令格式：modify <项目> <讯息>\n");
    switch(prop) {
        case "name":
        case "long":
        case "short":
        case "assign_msg":
        case "leader_title":
            set(prop, str);
            save();
            write("Ok.\n");
            break;
        default:
            write("你能修改的项目只有：name, short, long, assign_msg, leader_title。\n");
    }
    return 1;
}

int do_dismiss(string arg)
{
    if( !query("guild_id") ) return 0;
 
    rm(query_save_file() + __SAVE_EXTENSION__);
    write( query("guild_name") + "被解散了。\n");
    log_file("GUILD", 
        sprintf("%s（%s）于%s（%s）\n\t解散%s（%s）。\n",
        this_player()->query("name"), this_player()->query("id"),
        NATURE_D->game_time(), ctime(time()),
        query("guild_name"), query("guild_id")));
    destruct(this_object());
    return 1;
}
