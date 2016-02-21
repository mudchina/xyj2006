// suit.c
// 巫师工作服，有很多越权的地方
// 如由此服而发生的问题本站概不负责。

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
//inherit F_CLEAN_UP;
inherit F_COMMAND;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);
string inputstr,verb;
int main(object me, string arg);

void create()
{
       seteuid(getuid());
       set_name(HIW"巫师工作服"NOR,({"wizard suit","suit" }));
       set("long",@LONG
※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※  命  令  ※    用       法   ※    说        明    ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※bianxing  ※bianxing <id>     ※给人做变性手术      ※
※xing      ※xing <id>         ※让某人苏醒          ※
※hun       ※hun  <id>         ※让某人晕倒          ※
※feng      ※feng <id>         ※封冻某人            ※
※jiefeng   ※jiefeng <id>      ※解封某人            ※
※age       ※age <id> <s>      ※修改年龄            ※
※level     ※level <id>        ※查看人物的战斗力    ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※
LONG
       );
       if(clonep())
           set_default_object(__FILE__);
       else{
           set("unit","件");
           seteuid(geteuid());
           set("material", "cloth");
           set("armor_prop/armor", 10000);
           set("no_get",1);
           set("no_drop",1);
           }
       setup();
}
// 命令直待
void init()
{
       if( wizardp(environment()) ) {
       add_action("xing","xing");
       add_action("hun","hun");
       add_action("bx","bianxing");
       add_action("fengplayer","feng");
       add_action("nicks","nicks");
       add_action("jiefengplayer","jiefeng");
       add_action ("age", "age");              
       this_player()->set_temp("heat",1);
      }
}


// AGE 年龄
int age(string str)
{
        object me,target;
        string name;
        int level;
        me=this_player();
        if(!str) return notify_fail("age sb 增加的年纪.\n");
        if(sscanf(str,"%s %d",name,level)==2)   {
        if(!(target=present(name,environment(me))))
                return notify_fail("没儿没有这么个人。\n");
        target->add("mud_age",86400*level);
        target->add("age",level);
        write("修改"+WHT+target->query("name")+NOR+"，年纪增加"+HIR+(string)level+NOR+"岁。\n",this_object());
        return 1;
        }
        else
        return notify_fail("age sb. 增加的年纪。\n");
}

// 把人封住
int fengplayer (string str)
{
  object ob;
  if(str=="kittt") return notify_fail("你是不是想死啊！\n");
  if (!str) return notify_fail("feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  tell_object(ob,"你的眼睛突然一片模糊，好象有人蒙住你了...\n");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "<失去知觉中>" NOR);      
  return 1;    
}
// 把人解封
int jiefengplayer (string str)
{
  object ob;
  if (!str) return notify_fail("jiefeng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"有人很你说道：“恭喜发财”，你终于可以...\n");
  return 1;
}
//  XING 使人苏醒
int xing (string str)
{
  object who;
  if (!str) return notify_fail ("xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("没有"+str+"呀？\n");}
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
// HUN 使人昏倒
int hun (string str)
{
  object who;
  if (!str) return notify_fail ("你疯了，把自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("没有"+str+"呀？\n");}
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}
//  BX 变性手术
int bx(string arg)
{
  object bxid,me;
  me=this_player();
  if(arg=="kittt") return notify_fail("你奶奶的想死啊！\n");
  if (arg!=NULL_VALUE){
    bxid = LOGIN_D->find_body(arg);
    if (!bxid) return notify_fail("在网上好象没这个人呀！\n");
    }
  if (arg) {
    if(arg=="kittt") return notify_fail("你想死啊！\n");
    if(bxid->query("gender")=="女性") bxid->set( "gender", "男性" );
    else bxid->set( "gender", "女性" );
    message("shout", HIM "【谣言】某人：听说"+me->query("name")+"成功的对" 
    +bxid->query("name")+"进行了一次变性手术。\n" NOR,users());
    bxid->save();
    return 1;
  }
}

// nicks修改
int nicks(string arg)
{
        string dest;
        object me;
        me = this_player();
        if( !arg ) return help(me);     
        if(sscanf(arg,"-title %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("这个功能只能由巫师使用。\n");
                if(wiz_level(me)<wiz_level("(arch)")&&(dest!="me"&&dest!=me->query("id")))
                        return notify_fail("你的权限不够进行这个操作。\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("命令失败。\n");
        }
        if(sscanf(arg,"-name %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("这个功能只能由巫师使用。\n");
                if(wiz_level(me)<wiz_level("(arch)")&&(dest!="me"&&dest!=me->query("id")))
                        return notify_fail("你的权限不够进行这个操作。\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("命令失败。\n");
        }  
        if(sscanf(arg,"-id %s,%s",dest,arg)==2)
        {
                if(wiz_level(me)<wiz_level("(arch)"))
                        return notify_fail("这个操作只能由天神执行。\n");
                return wiz_set(dest,arg,"id",0)?1:notify_fail("命令失败。\n");
        }
        if(sscanf(arg,"-nick %*s")==1)
                sscanf(arg,"-nick %s",arg);
        if(sscanf(arg,"%s,%s",dest,arg)==2)
        {
                if(wiz_level(me)<wiz_level("(apprentice)"))
                        return notify_fail("这个操作只能由小巫以上级别的巫师执行。\n");
                return wiz_set(dest,arg,"nickname",1)?1:notify_fail("命令失败。\n");
        }
        if( strlen(replace_color(arg,0)) > 70 )
                return notify_fail("绰号太长了，请你想一个短一点的、响亮一点的。\n");
        return wiz_set("me",arg,"nickname",1)?1:notify_fail("命令失败。\n");
        write("Ok.\n");
        return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
        object ob,me;
        me=this_player(1);
        if(str1=="me")
                ob=this_player(1);
        else
                if(!objectp(ob=present(str1,environment(me))))
                        if(!objectp(ob=find_player(str1)))
                                if(!objectp(ob=find_living(str1)))
                                {
                                        tell_object(me,"不能发现操作对象("+str1+")！\n");
                                        return 0;
                                }
        if(wiz_level(me)<wiz_level(ob))
        {
                tell_object(me,"你的权限不够！\n");
                return 0;
        }
        if((prop=="title"&&wizardp(me))||prop=="nickname")
                if(str2=="cancel")
                {
                        ob->delete(prop);
                        message_vision("$N的"+prop+"被清除了。\n",ob);
                        return 1;
                }
        str2=replace_color(str2,color_flag);
        message_vision("$N的"+prop+"被设定为:"+str2+"\n",ob);
        ob->set(prop,str2);
        return 1;
}

string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}
int query_autoload()
{
   if (wizardp(this_player())) return 1;
   else return 0;
}
