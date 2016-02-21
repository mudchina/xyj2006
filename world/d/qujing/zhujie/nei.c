// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "内宫");
  set ("long", @LONG

内宫里十分宽敞，洞顶垂下几盏明灯，里面点着兽油。西壁有
石案一个，边上铺了厚厚的一层兽皮褥子。靠里面的洞壁有一
长寿椅。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"pian",
      ]));
  set("objects", ([
        __DIR__"npc/shi"   : 1,
      ]));

  setup();
}



