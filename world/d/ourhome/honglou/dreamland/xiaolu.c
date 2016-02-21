
//小路.c 寻水灵珠
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
一条小路，看来经常有人走。
LONG);
set("outdoors",1);
   set("exits", ([
      "northwest" : __DIR__"shangu2",
      "east" : __DIR__"yard",
   ]));
   setup();
   replace_program(ROOM);
}
