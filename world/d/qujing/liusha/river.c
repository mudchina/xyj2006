//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "流沙河");
  set ("long", @LONG

忽然一条大河挡住了出路，河水混沌不清，波涛汹涌，一眼望去
，了无边际，河水不停的打着旋涡，有的旋涡竟然方圆数亩，别
说是人，就是座山，也能被卷进去。你不禁双腿发软，胆颤心惊，
不敢在看。

LONG);
  set("exits", ([
        "east"  : __DIR__"kuangye2",
        "westup":   __DIR__"riverside",
        ]));
  set("outdoors","hfd");
  setup();
}
