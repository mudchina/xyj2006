// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "斋室");
  set ("long", @LONG

这里原为迎客栈的雅室，因客栈主人近来施财求雨，已将此雅
室改为供远道而来的客人稍事休息的地方。屋子里有一木桌和
一木床。
    
LONG);

  set("exits", ([
        "south"    : __DIR__"zhaizhan",
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  set("objects", ([
        __DIR__"obj/xifan"    : 1,
        __DIR__"obj/xiaocai"    : 1,
      ]));
  setup();
}

