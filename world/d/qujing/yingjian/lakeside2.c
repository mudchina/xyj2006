//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/lakeside1.c

inherit ROOM;

void create ()
{
  set ("short", "涧边");
  set ("long", @LONG

涓涓寒脉穿云过，湛湛清波映日红。声摇夜雨闻幽谷，彩发朝霞眩太空。
千仞浪飞喷碎玉，一泓水响吼青风，流归万顷烟波去，鸥鹭相忘没钓逢。

LONG);

  set("exits", ([
        "west" : __DIR__"lakeside3",
        "northeast" : __DIR__"lakeside1",
      ]));
  set("outdoors","yj");
  setup();

}
