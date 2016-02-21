// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "祭庙");
  set ("long", @LONG

祭庙里香火不断，里屋放着一个黑木香案，案上有签筒香炉，
香炉里点着几柱香，正在飘着一丝丝的青烟。庙的西边临街，
时不时有香客进进出出。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie2",
      ]));
  set("objects", ([
        __DIR__"npc/keeper"   : 1,
      ]));

  setup();
}


