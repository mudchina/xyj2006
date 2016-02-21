// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "小二店");
  set ("long", @LONG

小二店是一家平矮的木楼客店，店铺门口挂有几个招牌灯笼，
上面写着“王小二店”，门口放着一些鞋物，屋里是一排大通
铺，整整齐齐地叠着被褥。

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao8",
      ]));
  set("objects", ([
        __DIR__"npc/xiaoer"    : 1,
      ]));
  set("valid_startroom",1);
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

