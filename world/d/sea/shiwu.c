// Room: /u/rainy/sea/shiwu.c
inherit ROOM;

void create ()
{
  set ("short", "石屋");
  set ("long", @LONG

花园尽头出现一座石屋，屋乃巨石砌成，暗淡光下看起来相当的
朴实及厚实。门外左右有龟形石兽(statue)护卫，双眼中似乎有
光彩流动不止。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "status" : "石兽的头部好象可以扭动(turn)。\n",
]));

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"huayuan5",
  "north" : __DIR__"huayuan6.c",
  "west" : __DIR__"yidao.c",
]));
  set("close",1);
//      
        set("water", 1);
//  
  setup();
}

void init()
{
	add_action("do_turn", "turn");
}
int do_turn(string arg)
{
	object me,inside; 
	me=this_player();

        if ( !arg || ((arg != "statue") ))
                return notify_fail("你要扭动什么？\n");
	message_vision("$N轻轻扭动石兽的头部，只听「咔咔」几声响……\n", me);


	if( !(inside=find_object(__DIR__"wunei")))
		inside=load_object(__DIR__"wunei");

	if( inside=find_object(__DIR__"wunei")) {
		if( this_object()->query("close")) {
			set("exits/enter",__DIR__"wunei");
			inside->set("exits/out",__DIR__"shiwu");
			message("vision", "石屋的门轻轻的开了。\n", this_object());
			message("vision", "石屋的门轻轻的开了。\n", inside);
			set("close",0);
			return 1;
		}
                delete("exits/enter");
                inside->delete("exits/out");
                message("vision", "石屋的门轻轻的关上了。\n", this_object());
                message("vision", "石屋的门轻轻的关上了。\n", inside);
                set("close",1);
                return 1;
	}
}
