// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townb3.c

inherit ROOM;

void create ()
{
  set ("short", "儿女巷东");
  set ("long", @LONG

你走在西梁镇的儿女巷东。女人们在街头坐着晒太阳，有的
年轻妇女主动迎上来和男游客们笑嘻嘻地打招呼。女人群中
不时地爆发出哄笑。

LONG);

  set("exits", ([
        "north" : __DIR__"towna3",
        "west"  : __DIR__"townb2",
        "south" : __DIR__"townc3",
    ]));
  set("outdoors", __DIR__"");

  set("objects", ([
         __DIR__"npc/woman1" : 2,
     ]));

  setup();
}






