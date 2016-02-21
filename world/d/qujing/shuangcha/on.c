//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/on.c

inherit ROOM;

void create ()
{
  set ("short", "山岭");
  set ("long", @LONG

到了这，你觉得整个小山坡上热闹了很多，山鹿，野獐，还有大麂
时常从你的身边飞奔而过，当然还有些令人害怕的东西，如长蛇，
毒虫一类的东西也对你虎视眈眈。
LONG);

  set("exits", ([
        "east" : __DIR__"shanlu2",
        "west" : __DIR__"on2",
      ]));
  set("objects", ([
        __DIR__"npc/lu" : 1,
        ]));
  set("outdoors","sc");
  setup();
}
