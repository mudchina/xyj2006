//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

这儿竟然平静异常，一丝动静也没有。暗流、旋涡全消失怠尽，透
过混浊的河水，依稀看见一个黑乎乎的洞，冬内一团漆黑，什么也
看不见。洞口的水竟然是血红色的，水中还浮着几根发丝。你不由
的想到这里可能藏着吃人的妖怪，你不禁冷汗直冒，双腿打颤。

LONG);
  set("exits", ([
        "enter":   __DIR__"cave",
        "east":        __DIR__"hedi11",
        ]));
  setup();
}
