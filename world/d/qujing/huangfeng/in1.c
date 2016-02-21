//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

整个洞不是很大，几个小妖在讨论着什么，显的很吵，而正对着
你的不是别人，正是黄风老魔。
LONG);

  set("exits", ([
        "north"   : __DIR__"in2",
        "southup": __DIR__"dongkou",
      ]));
      set("objects",([
        __DIR__"npc/yaojing.c":2,
      ]));
  setup();
}
