// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "寺院");
  set ("long", @LONG

方方正正的寺院里，种着几棵千年大树，树枝茂密将寺院的一
半几乎遮住。寺院南边有一圆拱月门通向寺院深处，西边有个
台阶通向一个大殿。

LONG);

  set("exits", ([
        "west"   : __DIR__"baodian",
        "north"   : __DIR__"shanmen",
        "south"   : __DIR__"houyuan",
      ]));
  set("objects", ([
        __DIR__"npc/monk"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


