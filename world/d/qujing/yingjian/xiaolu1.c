//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

这时你已经走进了山脉地带，山连着山，水接着水，一路上
看不尽的悬崖峭壁，山峦叠荡起浮，让人觉得无比壮观。

LONG);

  set("exits", ([
        "west" : __DIR__"xiaolu2",
        "northeast": "/d/qujing/shuangcha/enter",
      ]));
  set("outdoors","yj");
  setup();

}
