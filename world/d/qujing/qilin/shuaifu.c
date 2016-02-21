// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "帅府宫");
  set ("long", @LONG

帅府宫里恶气横生，宫内四周墙上挂满各类兽头兽骨，地上铺开虎
皮豹皮，中间一玉石雕纹桌，宫后有一张龙虎巨床。东南方向有一
洞门通向鼎炉厅。

LONG);

  set("exits", ([ 
    "southeast" : __DIR__"dinglu",
  ]));
  set("objects", ([
    __DIR__"npc/nanyao" : 2,
  ]));
  setup();
}
