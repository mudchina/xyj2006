// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "偏宫");
  set ("long", @LONG

偏宫里明烛高照，洞宽顶阔有如高堂大殿。西南边有一通道导向洞
内大厅，东南边有一洞门通往剥皮亭，再往西则又是另一个妖怪们
议事的大堂，东北边可见一虹彩门。

LONG);

  set("exits", ([ 
    "west" : __DIR__"dinglu",
    "northeast" : __DIR__"hougong",
    "southeast" : __DIR__"bopi",
  ]));
  set("objects", ([
    __DIR__"npc/nuyao" : 3,
  ]));
  setup();
}
