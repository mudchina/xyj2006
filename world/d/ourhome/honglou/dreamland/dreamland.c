
//小路寻水灵珠
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
到处都是模模糊糊的，好象在睡梦中似的。四周静悄悄的，偶尔传来
几声乌鸦的叫声。
LONG
        );
   set("exits", ([ 
      "south" : __DIR__"shangu",
   ]));

   setup();
   replace_program(ROOM);
}
