// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "卧王室");
  set ("long", @LONG

卧王室里十分富丽堂皇，洞壁上点着三盏酥香油灯。地上铺着
一层花兽皮褥，室心放着一玉雕长桌，桌上胡乱地堆着几只金
盏银盅。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi1"  : 1,
      ]));

  setup();
}



