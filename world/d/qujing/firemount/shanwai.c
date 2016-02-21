// created by snowcat on 4/11/1997
// room: shanwai

inherit ROOM;
inherit "/std/dird.c";
int check_move(object me, string arg);

void create ()
{
  set ("short", "山外小路");
  set ("long", @LONG

你突然到了火焰山的西北面，东南面是红通通的火焰山顶。空气中
有一种强烈的糊味，热得让人难以忍受。北方有一条小径，通向山
下阴凉处。

LONG);

  set("exits", ([
        "northdown"  : __DIR__"hongyan",
        "southeast"  : __DIR__"huoyan",
     ]));
  set("outdoors", "firemount");

  setup();
}

void init()
{
add_action("do_look", "look");
}

int do_look(string arg)
{
if (arg=="southeast") {
	if (this_player()->query("obstacle/firemount")=="done")
		set("exits/southeast", __DIR__"nofire");
	else set("exits/southeast", __DIR__"huoyan");
	}
return this_player()->force_me("look "+arg);
}

int valid_leave(object me, string dir)
{
  if ( dir=="southeast" ) {
	if (me->query("obstacle/firemount")!="done") {
		set("exits/southeast", __DIR__"huoyan");
		me->set_temp("burnt_in_mount",0);
		me->set_temp("fanned_in_mount",0);
		me->set_temp("fan_times_in_mount",0);
		}
	else {
		set("exits/southeast", __DIR__"nofire");
		}
	return check_move(me, dir);
	// mon 4/11/98 modified this to prevent Illegal move error.
	}
return ::valid_leave(me, dir);
}


int check_move(object me, string arg)
{
	string dest, mout, min, dir;
	object env, obj;
	mapping exit;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");

	if( me->query_temp("no_move") )
		return notify_fail("你被定住了，哪里动得了！\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}

	dest = exit[arg];
	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

	dir = cdir(arg);

	if( me->is_fighting() ) {
		mout = "往" + dir + "落荒而逃了。\n";
		min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	} else {
		mout = "往" + dir + "离开。\n";
		min = "走了过来。\n";
	}

	if( !wizardp(me) || !me->query("env/invisibility") )
		message( "vision", me->name() + mout, environment(me), ({me}) );
	if( me->move(obj,1) ) {
	    // move silently so only see room once.
	    // mon 4/11/98
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") )
			message( "vision", me->name() + min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}


