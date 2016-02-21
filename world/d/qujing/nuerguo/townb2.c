// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townb2.c

inherit ROOM;

void create ()
{
  set ("short", "儿女巷中");
  set ("long", @LONG

你走在西梁镇的儿女巷中。女人们在街头坐着晒太阳，有的
年轻妇女主动迎上来和男游客们笑嘻嘻地打招呼。女人群中
不时地爆发出哄笑。

LONG);

  set("exits", ([
        "north" : __DIR__"towna2",
        "east"  : __DIR__"townb3",
        "west"  : __DIR__"townb1",
        "south" : __DIR__"townc2",
    ]));
  set("outdoors", __DIR__"");

  set("objects", ([
         __DIR__"npc/woman1" : 2,
         __DIR__"npc/woman2" : 2,
     ]));

  setup();
}






