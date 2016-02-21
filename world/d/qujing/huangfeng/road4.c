//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "乡间小路");
  set ("long", @LONG

逐渐，你把山庄抛在了身后，此时，你站在一棵参天古木下，旁边
有一位老者在乘凉，还不时的看看你。
LONG);

  set("exits", ([
        "west"  : __DIR__"shanlu1",
        "east"  : __DIR__"road3",
      ]));
  set("outdoors","hfd");
  set("objects", ([
	__DIR__"npc/old":1,
   ]));
  setup();
}
