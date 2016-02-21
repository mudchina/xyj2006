// gate.c

inherit ROOM;

void create()
{
  set ("short", "高家大门");
  set ("long", @LONG

这里便是高家的大门口．北面一对黑木做的大门半开着，门上贴着一
对门神．门左右摆着一对张牙舞爪的石狮，倒是清源县运来的正品．
看门的老余头正打着瞌睡．听人讲高家近来有祸事，整个院子静悄
悄的．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"zhyuan",
"east" : __DIR__"lu2",
"west" :__DIR__"road1",
]));

set("objects", ([
                __DIR__"npc/laoyu": 1 ]) );
        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


