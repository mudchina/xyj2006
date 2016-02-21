// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jishui.c

inherit ROOM;

void create ()
{
  set ("short", "祭水场");
  set ("long", @LONG

场上供有一玳瑁镶边的石井，泉水自井中潺潺流出，井边翠竹密
生。旱季时这里也是祭水的场所，仙香奇异无比。东边的五色拱
门直通坛场。

LONG);

  set("exits", ([
        "north"        : __DIR__"fengyun",
        "east"         : __DIR__"tan",
      ]));
  set("objects", ([
        __DIR__"npc/jz1" : 1,
        __DIR__"obj/chantai" : 2,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

