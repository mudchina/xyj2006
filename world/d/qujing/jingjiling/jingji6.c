#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "荆棘岭");
  set ("long", @LONG

岭上荆棘丫叉，薜箩牵绕。下面虽是有道路的痕迹，左右却都是
荆辞棘针，除是蛇虫伏地而游，方可过去。周围人烟稀少，空山
但闻鸟语猿啼不绝。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/hunter" : 2,
]));

  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 2 */
    "eastdown" : __DIR__"jingji5",
]));

  setup();
}

void init()
{
  add_action("do_clean", "bo");
  add_action("do_clean", "clean");
  add_action("do_clean", "push");
  add_action("do_clean", "pushaside");
}
int do_clean(string arg)
{	int i;
	object ob=this_object();
	object me=this_player();
	object obj;
        if(!arg || arg != "jingji" )
                return notify_fail("你要干什么？\n");
	
        if(query("clean"))
                return notify_fail("周围已经没有荆棘了。\n");

	if((int)me->query("kee") <50)
                return notify_fail("你太累了，歇歇吧！\n");

	if(!(obj = me->query_temp("weapon")) ){
		message_vision("$N想用手去扯那荆棘，却扎了满手鲜血！\n", me);
		return 1;
	} else {
		message_vision("$N挥舞手中$n，小心的去拨开那堆堆荆棘。\n", me, obj);
		me->receive_damage("kee", 50);
		i=(int)me->query_str();
		ob->set("coe",(int)ob->query("coe") + i );
		
		if( i < 30 ){	
			tell_room(environment(me), "结果只拨开几枝小刺。\n"); 
		}
		else if (i < 50 ) { 
			tell_room(environment(me), "结果拨倒一片荆棘。\n");
		}
		else if (i < 100 ) {
			tell_room(environment(me), "只见荆棘被推的不住后退。\n");
                }
		else tell_room(environment(me), "只见荆棘如潮水般退后。\n");
	}
	
	if( (int)ob->query("coe") > 1000 ) {
		tell_room(environment(me), "荆棘被推到两旁，闪出一条道路。\n\n");
		me->set_temp("obstacle/jingji/clean_6", 1);
		call_out("done", 1);
	}
	return 1;
}
int done()
{
	set("long", @LONG

岭上荆棘丫叉，薜箩牵绕。下面有一条道路的痕迹，左右的荆刺
棘针已被推到一旁，小心行过却是无碍。周围人烟稀少，空山但
闻鸟语猿啼不绝。
LONG);
	set("clean", 1);
	set("coe", 0);
	set("exits/northwest", __DIR__"jingji7");
	return 1;
}
