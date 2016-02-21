//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "草丛");
  set ("long", @LONG

这里到处都是草，有的草(grass)比人还要高，人在其间根本
看不到外面。听说这些草从里面经常会出现一些野兽什么的。
LONG);

  set("exits", ([
        "northeast": __DIR__"lakeside3",
      ]));
  setup();
}

void init()
{
     add_action("do_push","push");
}

int do_push(string arg)
{
        object me=this_player();
        if( ! arg || arg !="grass" )
                return notify_fail("你要推开什么?\n");
        
        set("exits/down",__DIR__"cave");
        remove_call_out("close");
        call_out("close", 5, me);
        tell_object(me,"你推开一丛杂草，意外发现了一个地方。\n");
        return 1;
}
void close(object room)
{
        message("vision","风一吹，又把出口堵上了。\n", room);
        room->delete("exits/down");
}

