// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "前洞");
  set ("long", @LONG

前洞里有天然石桥石亭，溪水从石桥下流过，两边石壁上挂下
来无数藤蔓。石亭边长着一些矮小的花草灌木，南边有路通向
洞外，东北边有一通道。

LONG);

  set("exits", ([
        "south"   : __DIR__"hukou",
        "northeast"   : __DIR__"houdong",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 3,
        __DIR__"npc/yaowang"  : 1,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object wang = present ("yao wang",this_object());

  if (wang &&
      living (wang) &&
      dir == "northeast")
    return notify_fail ("妖王对你喝道：哪里逃！\n");
  return ::valid_leave(who,dir);
}

