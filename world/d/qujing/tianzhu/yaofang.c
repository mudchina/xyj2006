// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "药房");
  set ("long", @LONG

门口挑着一招牌迎风摇晃，药房里面有一个大木柜，上面满是
小抽屉儿。西边靠街处有一窗子，窗边摆了一个仙桌，旁边有
两把软臂靠椅。

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao31",
      ]));
  set("objects", ([
        __DIR__"npc/hou"   : 1,
      ]));

  setup();
}


