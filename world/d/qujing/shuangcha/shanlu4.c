//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "山坡");
  set ("long", @LONG

山坡上一条小河横穿而过，河水顺流而下，发出汩汩的声音，
路两旁怪石嶙峋。树林茂密而整齐。
LONG);

  set("exits", ([
        "eastup" : __DIR__"on2",
        "westdown"   : __DIR__"shanlu5",
      ]));
  set("outdoors","sc");
  set("objects",([
        __DIR__"npc/taibao":1,
        ]));
  setup();
}
