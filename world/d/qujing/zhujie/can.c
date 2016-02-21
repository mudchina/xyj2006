// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "餐厅");
  set ("long", @LONG

餐厅里摆了大大小小的石桌石凳，厅角支起了一口大锅，油烟
顺着洞壁吹向石门外。东北方向有一小门，那里有一个天然的
洞穴仓库。

LONG);

  set("exits", ([
        "west"   : __DIR__"shimen",
        "northeast"   : __DIR__"cang",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



