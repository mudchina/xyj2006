//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

由此可以登上山，台阶是有青石板砌成，一阶一阶格外清析，路
盘旋而上，仿佛天边的云彩就在旁边，你一伸手就可以抓到一朵。

LONG);

  set("exits", ([
        "westup"    : __DIR__"shanmen2",
        "eastdown"  : __DIR__"shandao2",
      ]));
  set("outdoors","hf");
  setup();

}
