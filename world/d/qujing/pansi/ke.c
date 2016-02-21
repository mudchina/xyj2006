// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "客房");
  set ("long", @LONG

客房供客人休息，南墙有一排纸窗，山鸟啾啭之声从窗外传进
来。窗下有几把宽椅，东墙有一小供桌放着一铜炉，北面通向
茶房。

LONG);

  set("exits", ([
        "north"    : __DIR__"cha",
      ]));
  setup();
}

