// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大堂");
  set ("long", @LONG

大堂四周窗明几净，正中有一紫木长寿仙椅，一嵌玉兰石长
案。堂的东侧有一高高的青鼎，西边有一排雕花木柜。堂北
则通向门外。

LONG);

  set("exits", ([
        "north"   : __DIR__"fumen",
      ]));
  set("objects", ([
        __DIR__"npc/guan"   : 2,
        __DIR__"npc/fuling"   : 1,
      ]));

  setup();
}


