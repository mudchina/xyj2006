// created by snowcat.c 4/4/1997
// room: /d/nuerguo/fronthall.c

inherit ROOM;

void create ()
{
  set ("short", "前宫");
  set ("long", @LONG

西梁王宫的前宫。正中一帘镶珠紫红帐，四周雕龙绘凤金碧
辉煌。大厅左侧摆了一排长桌，供满了水果糕点让宾客享用，
大厅右侧是一队青衣少女在跳着宫庭舞蹈。

LONG);

  set("exits", ([
        "north" : __DIR__"backhall",
        "east"  : __DIR__"easthall",
        "west"  : __DIR__"westhall",
        "south" : __DIR__"entry",
      ]));

  set("objects", ([
         __DIR__"npc/girl" : 2,
     ]));

  setup();
}






