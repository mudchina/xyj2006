// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "过道");
  set ("long", @LONG

洞穴在这里显得十分拥挤，两边的石壁上爬着青藤，青藤上插
着一些火炬，以提供洞内的照明。过道的西边通向外宫殿，东
北边通向走廊。

LONG);

  set("exits", ([
        "west"   : __DIR__"wai",
        "northeast"   : __DIR__"zou",
      ]));

  setup();
}



