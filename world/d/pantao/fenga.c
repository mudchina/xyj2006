// created by snowcat.c 5/23/1997
// room: /d/pantao/fenga.c

inherit ROOM;

void create ()
{
  set ("short", "彩凤厅");
  set ("long", @LONG

封神台西侧为彩凤厅。厅内碧雾蒙蒙，盘旋着彩羽凌空丹顶凤。
两边天妃仙女玉簪珠履绛纱衣，若星辰灿烂。厅外开满千千年
不谢的琪花。

LONG);

  set("exits", ([
        "east"  : __DIR__"fengb",
      ]));

  set("objects", ([
         __DIR__"npc/female" : 1,
      ]));

  setup();
}

