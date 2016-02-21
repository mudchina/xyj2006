//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "石洞门");
  set ("long", @LONG

山崖下青藤高挂，蒿草丛生，自石岩缝隙中间裂开一个大洞，
洞口云雾缭绕，上面有一白石大匾，书有：“积雷山摩云洞”
六个大字。

LONG);

  set("exits", ([
        "north"   : __DIR__"jilei2",
        "northeast"   : __DIR__"jilei3",
        "southeast"   : __DIR__"shilang",
      ]));
  set("outdoors", __DIR__);

  setup();
}



