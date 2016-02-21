
//shangu.c 寻水灵珠
inherit ROOM;
void create()
{
        set("short", "山谷");
        set("long", @LONG
这是一个开满鲜花的山谷，到处都是蝴蝶和蜜蜂。远处似乎传来轰轰的水声，
好象有个瀑布。
LONG);
   set("exits", ([
      "south" : __DIR__"shangu2",
      "north" : __DIR__"dreamland",
   ]));
   setup();
   replace_program(ROOM);
}
