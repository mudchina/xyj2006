// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "正厅");
  set ("long", @LONG

正厅为一殿堂，窗明几净，设有三清圣象。堂心放有一桃木花
心供桌，上面有兽脚铜炉一只，里面有香火燃烟。殿堂的左右
各有两扇双推门。

LONG);

  set("exits", ([
        "north"    : __DIR__"yuannei",
        "west"    : __DIR__"pian",
        "east"    : __DIR__"cha",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong"    : 1,
      ]));
  setup();
}

