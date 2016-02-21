//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu2.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山上的树林如天上的云彩一般密集，一片墨绿，偶尔从山林深处
传来一两声鸟莺鸣叫之声，在空旷的山谷中荡然传开。

LONG);

  set("exits", ([
        "west" : __DIR__"xiaolu3",
        "east" : __DIR__"xiaolu1",
      ]));
  set("outdoors","yj");
  setup();

}
