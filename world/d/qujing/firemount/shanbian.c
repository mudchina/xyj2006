// rewritten by snowcat on 4/11/1997
// Room: huoyan

inherit ROOM;
inherit "/std/dird.c";
int check_move(object me, string arg);

void create ()
{
  set ("short", "山边");
  set ("long", @LONG

越往西越是燥热难忍，西边便是令人色变的火焰山。四野一片红黄
色的荒凉，到处是烤得发红的碎石和砂土。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/sea/npc/long8.c" : 1,
]));
  set("outdoors", "firemount");
  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"huoyan",
  "eastdown" : __DIR__"shalu",
  "enter" : __DIR__"huoku.c",
]));

  setup();
}

void init()
{
  add_action("do_all", "",1);
}

int do_all(string arg)
{
    if (this_player()->query("obstacle/firemount")=="done")
      set("exits/westup", __DIR__"nofire");
    else set("exits/westup", __DIR__"huoyan");
    return 0;
}



