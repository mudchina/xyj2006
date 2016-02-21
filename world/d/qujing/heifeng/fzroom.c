//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "方丈室");
  set ("long", @LONG

这里是方丈修行的地方，这个寺院的方丈就是金池和尚，屋中的桌子
上放着羊脂玉的盘子，还有一把白金壶儿，三个法蓝镶金的茶盅，看
起来很不象一个出家人的修行的地方。
LONG);

  set("exits", ([
        "north": __DIR__"dadian",
      ]));
  set("objects", ([
        __DIR__"npc/jinchi":1,
        ]));
  setup();

}
void init()
{
        add_action("do_push","knock");
 }

int do_push(string arg)
{
        object me = this_player();

        if( !arg || arg != "wall" )
                return notify_fail("你要敲什么？\n");

        if( me->query("obstacle/hf") == "done" )
                return notify_fail("你敲了半天的墙，也没有发现什么。\n");

        set("exits/south", __DIR__"backroom");
        message_vision(HIC"$N轻轻往墙上一敲，忽然墙向一侧移动，这里竟然还有一个房间。\n"NOR,me);
        remove_call_out("close");
        call_out("close", 3, me);
        return 1;
}
void close()
{
        object room = load_object("/d/qujing/heifeng/fzroom");
        message("vision","忽然墙自动的合拢了。\n", room);
        room->delete("exits/south");
}


