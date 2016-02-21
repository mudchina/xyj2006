// Room: come to baigudong.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "剥皮广场");
  set ("long", @LONG

  雾气突然转浓，腥味很重，地上血迹斑斑，广场上立了
几根桩子，西边桩子上绑了个血淋淋的人，仔细一看，面
目全非，身上的皮已经被剥走了。几个小妖蹲在地上，翻
着一堆人皮，嘴里嘟嘟囔囔，不知在说些什么。

LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "northeast":__DIR__"banshanpo",
  "eastup" : __DIR__"dongting",
]));

  set("objects",([
     __DIR__"obj/renpi":1,
     __DIR__"npc/xiaoyao":4,
                ]));
  setup();
}






