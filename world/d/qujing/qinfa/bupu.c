// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "布铺");
  set ("long", @LONG

铺子里放着一匹匹的彩染布料和粗绳细线，门口挂着一些供出
售的衣服绸袍纱裙毡帽。屋子里面挑着一盏油灯，有几条长凳
就着墙角放着。

LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao2",
      ]));
  set("objects", ([
        __DIR__"npc/li"    : 1,
      ]));
  setup();
}

