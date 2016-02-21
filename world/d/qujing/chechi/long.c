// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/long.c

inherit ROOM;

void create ()
{
  set ("short", "龙楼");
  set ("long", @LONG

龙楼是车迟国公子哥们聚合的场所，楼外门柱上雕有金鳞盘龙一
对，楼内摆满八仙桌。这里常有衣着考究的公子王孙整日在此逍
遥混日，花天酒地谈东道西。

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi9",
      ]));
  set("objects", ([
        __DIR__"npc/long"     : 5,
      ]));
  set("valid_startroom", 1);
  setup();
}

