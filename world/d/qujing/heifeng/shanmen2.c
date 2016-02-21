//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shanmen.c

inherit ROOM;

void create ()
{
  set ("short", "二山门");
  set ("long", @LONG

离山顶已经很近了，你远远的望去，只见一座宝殿坐落山顶，云雾
霭霭，仿佛到了仙境，你不禁加快了脚步。

LONG);

  set("exits", ([
        "westup"  : __DIR__"shandao4",
        "eastdown"  : __DIR__"shandao3",
      ]));
  set("outdoors","hf");
  setup();

}
