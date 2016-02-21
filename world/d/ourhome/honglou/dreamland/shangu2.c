
//shangu2.c 寻水灵珠
inherit ROOM;
void create()
{
        set("short", "山谷");
        set("long", @LONG
到处是鲜花绿树，你仿佛置身于花的海洋，远处的轰轰声更大了。
LONG
        );
   set("exits", ([
      "north" : __DIR__"shangu",
      "southwest" : __DIR__"shuitan",
      "southeast" : __DIR__"xiaolu",
      "west" : __DIR__"xiaowu",
   ]));
   setup();
   replace_program(ROOM);
}
