//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "旷野");
  set ("long", @LONG

身后的鸟语花香已经不复存在了，整个就是一片旷野，绿色仿佛
从世界上消失了。你不禁发出疑问,脚步也放慢了许多,远远地竟
然听到了波涛的声音。

LONG);
  set("exits", ([
        "west"  : __DIR__"river",
        "southeast": __DIR__"kuangye1",
        ]));
  set("outdoors","hfd");
  setup();
}
