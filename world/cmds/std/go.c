//2001 by lestat
// go.c
#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/std/valid_move.h";

mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"enter":		"里",
	"out":			"外",
]);


mapping reverse_dir=([
	"north":		"南面",
	"south":		"北面",
	"east":	    	"西面",
	"west":	    	"东面",
	"northup":		"南边",
	"southup":		"北边",
	"eastup":		"西边",
	"westup":		"东边",
	"northdown":	"南边",
	"southdown":	"北边",
	"eastdown":		"西边",
	"westdown":		"东边",
	"northeast":	"西南方向",
	"northwest":	"东南方向",
	"southeast":	"西北方向",
	"southwest":	"东北方向",
	"up":			"下面",
	"down":	    	"上面",
	"enter":		"外面",
	"out":	    	"里面",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg, int silent)
{
    	mixed dest;
	string ridemsg, mout, min, dir,msg, blk, gud, skill, face, thing_msg,dir1,str,str1;
	object env, obj, ridee, blocker, thing;
	mapping block;
	mapping exit;
	object *f_obs, *ob;
	int valid;
    int count = 0, my_dex, i,n,i_env,i_obj;
	if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if(!valid_move(me)) return 0;

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}

	dest = exit[arg];
    dest = env->query("exits/"+arg);
	if (dest && objectp(dest))
	    obj = dest;
	else if( !(obj = load_object(dest)) )
	        return notify_fail("你要去的区域还没有连通。\n");
	else if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

	valid=(int)env->valid_leave(me, arg);
	if( !valid ) return 0;
	if(valid>1) return 1;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name()+"踏着一朵祥云";
        else  
          ridemsg = "";

        if(ridee && !valid_move(ridee)) 
           return notify_fail("你的座骑走动不了。\n");
           
if(me->is_ghost()&&domain_file(base_name(environment(me)))!="death")
 {              
 	        write(BLU"突然间阴风阵阵，你耳边响起一阵空洞而又阴森的声音:‘回来哟，回来哟!’\n"NOR);
		write(HIW"一阵白雾将你裹了起来，你又回到了鬼门关\n"NOR);
                me->move("/d/death/gate");
                return 1;
 }

//以下是关于白天和黑夜显示的区别

	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;
	if( !undefinedp(reverse_dir[arg]) )
		dir1="从"+reverse_dir[arg];
	else dir1="不知道从哪里";

	n=NATURE_D->night();
	i_env=(int)env->query("outdoors");
	i_obj=(int)obj->query("outdoors");
	
	if (!n) i=1;
	if (!i_env && !i_obj) i=1;
	if (n && i_env && !i_obj) i=2;
	if (n && ! i_env && i_obj) i=3;
	if (n && i_env && i_obj ) i =4;
	if( me->is_fighting() ) 
	{str="跌跌撞撞地跑了过来，模样有些狼狈。\n";
	 str1="往" + dir + env->query("short") +"落荒而逃了。\n";
	}else
		{str=dir1+env->query("short") +"走了过来。\n";str1="往" + dir + "离开。\n";}

	if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "身着" + thing->query("name");
		else
			thing_msg = "全身一丝不挂地";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->query("name");
	if ( me->query("race") == "野兽")
		{
			mout = me->name() + "呼地往" + dir + "一窜就消失了。\n";
			min = me->name() + "从" + dir + env->query("short") + "呼地窜了出来，警惕地四周张望着。\n";
		}
		else
		{
if (ridee = me->ride())
			{
	if( ridee && ridee->query("bird") ) {
     str="骑着"+ridee->name()+dir1+env->query("short") +"飞了过来。\n";
     str1="骑着"+ridee->name()+"往" + dir  + "飞去。\n";
	}else{

	str="骑着"+ridee->name()+dir1+env->query("short") +"一路疾驰而来。\n";
	str1="骑着"+ridee->name()+"往" + dir + "疾驰而去。\n";
	}
	switch( i)
	{	case 1 : 
		mout = me->name() + str1;
		min = me->name() + thing_msg +str;
		break;
		case 2 :
		if(me->query("gender") == "女性")
		{
		mout = "一条倩影" + str1;
		min =  me->name() + thing_msg + str;
		}
		else
		{
		mout = "一条黑影"  +str1;
		min  = me->name() + thing_msg +str;
		}
		break;	
		case 3 :
		if(me->query("gender") == "女性")
		{
		mout = me->name() + str1;
		min =  "一条倩影" + thing_msg + str;
		}
		else
		{
		mout = me->name() + str1;
		min  = "一条黑影" + thing_msg + str;
		}
		break;
		case 4 :
			if(me->query("gender") == "女性")
		{
		mout = "一条倩影" + str1;
		min =  "一条倩影" + thing_msg + str;
		}
		else
		{
		mout = "一条黑影" + str1;
		min  = "一条黑影" + thing_msg + str;
		}
	}
		}
			else
			{

	switch( i)
	{	case 1 : 
		mout = me->name() + str1;
		min = me->name() + thing_msg + str;
		break;
		case 2 :
		if(me->query("gender") == "女性")
		{
		mout = "一条倩影" + str1;
		min =  me->name() + thing_msg + str;
		}
		else
		{
		mout = "一条黑影" + str1;
		min  = me->name() + thing_msg + str;
		}
		break;	
		case 3 :
		if(me->query("gender") == "女性")
		{
		mout = me->name() + str1;
		min =  "一条倩影" + thing_msg + str;
		}
		else
		{
		mout = me->name() + str1;
		min  = "一条黑影" + thing_msg + str;
		}
		break;
		case 4 :
			if(me->query("gender") == "女性")
		{
		mout = "一条倩影" + str1;
		min =  "一条倩影" + thing_msg + str;
		}
		else
		{
		mout = "一条黑影" + str1;
		min  = "一条黑影" + thing_msg + str;
		}
	}
		}
		}
//////////////////////白天黑夜限定结束
		if( !wizardp(me) || !me->query("env/invisibility") )
	{
	    	if (environment(me) && environment(me)->query("no_look"))
				message( "vision", "一个模糊的影子" +  mout, environment(me), ({me}) );
		else
	message( "vision", mout, environment(me), ({me}) );
			}
		if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") ) {
	    			if (environment(me) && environment(me)->query("no_look"))
		    			message( "vision", "一个模糊的影子" +  min, environment(me), ({me}) );
				else
		message( "vision", min, environment(me), ({me}) );
				}
		me->set_temp("pending", 0);
		if (env != obj)
			all_inventory(env)->follow_me(me, arg);
//		if (ridee)
//			tell_object (me,"你"+min);
		/////////////杀人犯通缉
		if (userp(me) && me->query_condition("no_pk_time") &&
		me->query_temp("rumor_time")+10<time() &&
		  MISC_D->find_place(environment(me))!=
		me->query_temp("last_place"))
		{ 
		  me->set_temp("last_place",MISC_D->find_place(environment(me)));
		  msg="听说官府通缉杀人犯"+HIW+me->query("name")+HIM+"最近在"+HIC+me->query_temp("last_place")+HIM+"附近出没。\n";
		CHANNEL_D->do_channel(this_object(),"rumor",msg);
		me->set_temp("rumor_time",time());
			}
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	if (environment(me) && environment(me)->query("no_flee")) return;
	tell_object(me, "看来该找机会逃跑了．．．\n");
        if( me->query_temp("no_move") ) {
          tell_object (me, "可你被定住了，逃不掉！\n");
          return;
        }

	if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
	   tell_object(me, "你逃跑失败。\n");
	   return;
	}

	main(me, directions[random(sizeof(directions))], 0);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}

