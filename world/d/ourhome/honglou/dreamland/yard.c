
//空地.c 寻水灵珠
inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
一块小小的空地，一个漂亮的小女孩正在这里玩。
LONG);
   set("exits", ([
      "west" : __DIR__"xiaolu",
   ]));
   set("objects", ([
   __DIR__"npc/girl" : 1,
   ]));
   setup();
   replace_program(ROOM);
}
