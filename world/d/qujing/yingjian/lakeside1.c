//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/lakeside1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

走到这，你感觉空气变的很湿润，微微可以听到有水击岸石的声音
，就见前面一道瀑布仿佛从天而落，真是个“疑是银河落九天”
LONG);

  set("exits", ([
        "southwest" : __DIR__"lakeside2",
        "east" : __DIR__"xiaolu4",
      ]));
  set("outdoors","yj");
  setup();

}
