// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "马栈");
  set ("long", @LONG

马栈为远道而来的客人准备了休息躺椅，栈里十分宽敞。墙角有一
栓马柱，还有一些空空的马槽架在屋子里，专为在此落脚的客人们
提供方便。

LONG);

  set("exits", ([ 
    "south" : __DIR__"tian3",
    "north" : __DIR__"beixia6",
  ]));
  set("objects", ([
    __DIR__"npc/horse" : 1,
  ]));
  setup();
}
