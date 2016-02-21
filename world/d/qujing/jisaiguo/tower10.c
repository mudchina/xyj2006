#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "琉璃塔十层");
  set ("long", @LONG

峥嵘倚汉，突兀凌空，名唤五色琉璃塔。层层门上琉璃灯，有尘
无火，步步檐前白玉栏，积诟飞虫。塔心里，佛座上，香烟尽绝，
窗棂外，神面前，蛛网牵蒙。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/kusu" : 1,
//]));
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tower9",
  "up" : __DIR__"tower11",
]));

  setup();
}
void init()
{
  add_action("do_shao", "shao");
}
int do_shao(string arg)
{
	object me=this_player();
	
	if(!arg && arg != "di" && arg!="floor")
		return notify_fail("你要扫什么？\n");

	if(!present("broom", me))
		return notify_fail("没扫地的家伙怎么行？\n");

	if(query("clean"))
		return notify_fail("地下够干净了，不用扫了！\n");

	if((int)me->query("kee") <20)
		return notify_fail("你太累了，歇歇吧！\n");

	message_vision("$N挥舞着大扫帚扫起地来。\n", me);
	write("结果卷起的灰蒙了你一脸。\n");
	message_vision("$N抹了一把汗，得意的笑了笑。\n", me);
	me->receive_damage("kee", 15);
	me->add_temp("clean_floor", 1);
	
	if((int)me->query_temp("clean_floor") > 13){
		me->delete_temp("clean_floor");
	}
	set("clean", 1);
	call_out("regenerate", 800);
	set("long", @LONG

峥嵘倚汉，突兀凌空，名唤五色琉璃塔。梯转如穿窟，门开似出
笼。宝瓶影射天边月，金择声传海上风。但见那虚檐拱斗，绝顶
留云作成巧石穿花凤，造就浮屠绕雾龙，远迢可望千里外，高登
似在九霄中。
LONG);

	return 1;
}
int regenerate()
{
  set ("long", @LONG
                
峥嵘倚汉，突兀凌空，名唤五色琉璃塔。层层门上琉璃灯，有尘
无火，步步檐前白玉栏，积诟飞虫。塔心里，佛座上，香烟尽绝，
窗棂外，神面前，蛛网牵蒙。
LONG);  

        set("clean", 0);
        return 1;
}

