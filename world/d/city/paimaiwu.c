inherit ROOM;

void create ()
{
  set ("short", "ÅÄÂôÎİ");
  set ("long", @LONG

         ÕâÀï±ãÊÇÅÄÂôÎİ

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/d/wiz/npc/paimaishi" : 1,
  ]));
  set("outdoors", 1);
set("no_fight", 1);
set("no_magic", 1);
  set("exits", ([ /* sizeof() == 2 */
"down" : "/d/city/center",
  //"north" : __DIR__"damen",
]));

  setup();
}

