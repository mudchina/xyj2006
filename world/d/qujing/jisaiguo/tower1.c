#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "琉璃塔一层");
  set ("long", @LONG

峥嵘倚汉，突兀凌空，名唤五色琉璃塔。层层门上琉璃灯，有尘
无火，步步檐前白玉栏，积诟飞虫。塔心里，佛座上，香烟尽绝，
窗棂外，神面前，蛛网牵蒙。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/kusu" : 1,
//]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower2",
]));

  setup();
}
void init()
{
  add_action("do_shao", "shao");
  add_action("do_knock", "knock");
  add_action("do_knock", "qiao");
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

	if((int)me->query("kee") <50)
		return notify_fail("你太累了，歇歇吧！\n");

	message_vision("$N挥舞着大扫帚扫起地来，卷起大片的灰尘。\n", me);
	write("灰尘散开后，塔内的样子真是大变样了。\n");
	message_vision("$N抹了一把汗，得意的笑了笑。\n", me);
	me->receive_damage("kee", 30);
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


int do_knock(string arg)
{
        object me;

        me=this_player();

        if( !arg || (arg != "men" && arg != "door" && arg != "门" ) )
                return notify_fail("你要敲什么？\n");       
        call_out("open_up", 1);
        return 1; 
}

void open_up()
{
        object uproom; 

        if( !(uproom = find_object(__DIR__"baodian")) )
                uproom = load_object(__DIR__"baodian");

        if( uproom = find_object(__DIR__"baodian") ) 
        {
                set("exits/out", __DIR__"baodian");
                uproom->set("exits/enter", __FILE__);
		message("vision", "小门被人打开了。\n", uproom);
		message("vision", "小门被人打开了。\n", this_object());
        }

        call_out("close_up", 100);
}

void close_up()
{
        object uproom;

        if( !query("exits/out") ) return;
	message("vision", "小门被人关上了。\n", this_object());


        if( uproom = find_object(__DIR__"baodian") ) 
        {
		message("vision", "小门被人关上了。\n", uproom);
                uproom->delete("exits/enter");
        }

        delete("exits/out");
}


