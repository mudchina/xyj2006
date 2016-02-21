// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "西湖路");
  set ("long", @LONG

一条小路沿着湖边蜿蜒盘绕，西边的湖水浑浊一点，风吹过湖水荡漾
杨柳微拂，在湖水上晃动着长长的倒影。不时有莺歌鸟鸣声声传来，
令人心旷神怡。

LONG);

  set("exits", ([
        "west" : __DIR__"xihu1",
        "southeast" : __DIR__"xihu4",
      ]));

  set("outdoors", __DIR__);

  setup();
}


