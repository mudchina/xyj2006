// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "首饰店");
  set ("long", @LONG

一座精巧的青砖红瓦小店，门檐上挑着一个“吴”字灯笼。店
里面是几个檀香木桌，几把太师椅。木桌上放着几个打开的玛
瑙匣子，陈列着各种首饰。

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao93",
      ]));
  set("objects", ([
        __DIR__"npc/wu"   : 1,
      ]));

  setup();
}


