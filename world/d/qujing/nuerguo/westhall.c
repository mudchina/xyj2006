// created by snowcat.c 4/4/1997
// room: /d/nuerguo/westhall.c

inherit ROOM;

void create ()
{
  set ("short", "西侧殿");
  set ("long", @LONG

这里是西梁王宫的西侧殿。靠墙四周铺设了一圈极为考究的
红木桌椅，上面放着香炉，玉如意等玩物。这里主要是供来
宾们休息使用的场所。

LONG);

  set("exits", ([
        "east"  : __DIR__"fronthall",
      ]));

  setup();
}






