//Cracked by Roath
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
	"out":			"外",
	"enter":		"里",
	"left": 		"左",
	"right":		"右",
]);

void create() { seteuid(getuid()); }

// follow will have silent=2, so as to reduce the CPU load.
int main(object me, string arg, int silent)
{
    	mixed dest;
	string ridemsg, mout, min, dir, blk, gud, skill, face, thing_msg;//后五个
	object env, obj, ridee, blocker, thing;//后两个
	mapping block;//新增
	mapping exit;
	int valid;

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

        // snowcat 12/20/97
        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
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
	if( me->is_fighting() ) {
		mout = ridemsg + "往" + dir + "落荒而逃了。\n";
		min = ridemsg + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	} else {
		//Jiz. 02/11
		if( ridee && ridee->query("bird") ) {
			mout = ridemsg+ "往" + dir + "飞去。\n";
			min = ridemsg+ "飞了过来。\n";
		} else {
 		 	mout = ridemsg+ "往" + dir + "离开。\n";
			min = ridemsg+ "走了过来。\n";
		}
	}

/*	if( !wizardp(me) || !me->query("env/invisibility") )
	{
	    	if (environment(me) && environment(me)->query("no_look"))
		    	message( "vision", "一个模糊的影子" +  mout, environment(me), ({me}) );
		else
			message( "vision", me->name() + mout, environment(me), ({me}) );
	}
	if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") ) {
	    			if (environment(me) && environment(me)->query("no_look"))
		    			message( "vision", "一个模糊的影子" +  min, environment(me), ({me}) );
				else
					message( "vision", me->name() + min, environment(me), ({me}) );
		}
		me->set_temp("pending", 0);
		// added by snowcat, to fix the bug of recursive move of mutual follow + move to same room 
		if (env != obj)
			all_inventory(env)->follow_me(me, arg);
		if (ridee)
			tell_object (me,"你"+min);
		return 1;
	}

	return 0;*/
	if( wizardp(me) && me->query("env/invisibility") && (wiz_level(me) >= wiz_level(env)))
	{
		mout = "";
		min = "";
	}
	else
	{
/*		face="的";
		if (me->query("gender")=="女性")
		{
			if (me->query("per") >= 30) face ="娇艳绝伦" + face;
			if ((me->query("per") >= 28) && (me->query("per") < 30)) face= "清丽绝俗" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "风情万种" + face;
			if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "容色秀丽" + face;
			if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "面目姣好" + face;
			if (me->query("str") <= 16) face = "亭亭玉立" + face;
			if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "体态轻盈"+ face;
			if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
		}
		else
		{
			if (me->query("per") >= 30) face= "玉树临风般" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 30)) face="英俊潇洒" + face;
			if ((me->query("per") >= 22) && (me->query("per") < 26)) face="仪表堂堂" + face;
			if (me->query("str") >=23) face = "身材壮硕" + face;
			if ((me->query("str") >= 20) && (me->query("str") < 23)) face= "膀大腰圆"+ face;
			if ((me->query("per")<22) && (me->query("str")<20) || !userp(me)) face = "";
		}*/
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "身着" + thing->query("name");
		else
			thing_msg = "全身一丝不挂地";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->query("name");
		if ( me->query("race") == "野兽")
		{
			mout = me->name() + "呼地往" + dir + "一窜就消失了。\n";
			min = me->name() + "呼地窜了出来，警惕地四周张望着。\n";
		}
		else
		{

			if (ridee = me->ride())//if ( me->query_temp("is_riding"))
			{
				mout = me->name()+"骑着"+ridee->name()+"向" + dir + "疾驰而去。\n";
				min = me->name() + thing_msg + "骑着"+ridee->name()+"一路疾驰而来。\n";
			}
			else
			{
				mout = me->name() + "往" + dir + "离开。\n";
				min = me->name() + thing_msg + "走了过来。\n";
			}
		}
	}
	
	message( "vision", mout, environment(me), ({me}) );
/*	if( me->move(obj) ) {
//		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
//		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);}
//		return 1;*/
		if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );

/*		if( !wizardp(me) || !me->query("env/invisibility") ) {
	    			if (environment(me) && environment(me)->query("no_look"))
		    			message( "vision", "一个模糊的影子" +  min, environment(me), ({me}) );
				else
					message( "vision", me->name() + min, environment(me), ({me}) );
		}*/
		me->set_temp("pending", 0);
		// added by snowcat, to fix the bug of recursive move of mutual follow + move to same room 
		if (env != obj)
			all_inventory(env)->follow_me(me, arg);
//		if (ridee)
//			tell_object (me,"你"+min);
		return 1;//添@@@@@@@22
	}

	return 0;////为止
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
