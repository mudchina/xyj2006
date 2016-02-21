//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "大道");
  set ("long", @LONG

路渐渐地平坦了起来,草木却逐渐稀疏,人迹也渐渐少了,土地
的枯黄,草木的枯萎你竟然感觉像是到了秋天,满目萧瑟,心中
怅然。

LONG);
  set("exits", ([
        "east"  : __DIR__"dadao3",
        "west":   __DIR__"kuangye1",
        ]));
  set("outdoors","hfd");
  setup();
}
