//Cracked by Roath
// create by snowcat.c 4/8/1997
// room: /d/westway/jiayu.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "嘉峪关");
  set ("long", @LONG

一座雄伟的关口坐落在群山之中，嘉峪关是长城最西的关口，
镇守大唐国的西域大门。关外向西便是通向西域各国的艰难
道路，只见西面一片茫茫大雾如海一般恍恍惚惚什么也看不
见。关内向东通向大唐国各地，南边有一个小小出口与蜂火
台相连。

LONG);

/*
  dir = __DIR__;
  dir[strlen(dir)-8] = 0;
*/
  dir = "/d/qujing/";
  set("exits", ([
        "east"      : __DIR__"shizhan",
        "north"      : "/d/zhuxian/xiaolu8",
              "westup"      : "/d/qujing/shuangcha/shanlu1",
        "southup"   : __DIR__"fenghuo",
      ]));
  set("objects", ([
                __DIR__"npc/wujiang": 2 ]) );

  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object me, string dir)
{
  	if (dir == "west"){
    		message_vision ("$N向西一跃，冲进茫茫大雾中！\n",me);
  	}
	if (dir == "southup" ) {
  	if (objectp(present("wu jiang", environment(me))))
        return notify_fail("边关守将嚷到：那不是你该去的地方！\n");
        }
  return 1;
}


