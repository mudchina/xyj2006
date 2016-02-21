// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

山林开阔地带有一块空场地，场地上有一片寺院，仿佛在云雾
之中。寺院前面是一高大的山门，可以看见门里的寺院，门上
有一个大匾：布金禅寺。

LONG);

  set("exits", ([
        "south"   : __DIR__"siyuan",
        "northeast"   : __DIR__"baijiao",
      ]));
  set("objects", ([
        __DIR__"npc/monk"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "northeast")
    return 0;
  return ::valid_leave (who, dir);
}
