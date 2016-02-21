// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yuan.c

#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "后园");
	set ("long", @LONG

黄风洞的后园怪石遍地，荒草连天，满眼的古木枯藤。园中心的
空地上立有一根铁柱(zhuzi)，高有数丈。

LONG);

      set("item_desc", ([ /* sizeof() == 1 */
  		"zhuzi" : "铁柱通体黝黑，细看才发现柱身上刻着“定风柱”三个小字。
立于庭中，另一端被树木的枝叶遮住。透过枝叶的缝隙，你
看到似乎有什么东西在闪闪发光。
",
]));
       set("exits", 
	([ //sizeof() == 1
	"south":__DIR__"yuandoor",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", __DIR__);

	setup();
}

void init()
{
  add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object wugang;
  object me=this_player();
 
  if( (!arg) || !((arg == "zhuzi") || (arg == "定风柱")))
    return notify_fail("爬什么？\n");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*20/100);
    return notify_fail("你气喘嘘嘘，突然一个失手，跌了下来！\n");
}
  if ((int)me->query_skill("dodge", 1)<50)
        {
	  message_vision("$N试着往柱上爬去，但柱上光溜溜的没个着手之处。不得以又滑了下来。\n", me);
        }
      else
        {
	  message_vision("$N打起精神，手脚并用，顺着柱子爬了上去。\n", me);
          me->move(__DIR__"zhuzitop.c");
        }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}
