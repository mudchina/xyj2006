// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "军营");
  set ("long", @LONG

木制的军营里戒备森严，门廊里有一列士兵盔甲一身贝插彩旗
整齐站立，目不斜视。营内隐约可听见战马嘶鸣，不时有铜鼓
声传来。

LONG);

  set("exits", ([
        "south"    : __DIR__"gongmen",
      ]));
  set("objects", ([
         __DIR__"npc/junshi"    : 6,
      ]));
  setup();
}

