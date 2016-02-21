// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/ting.c

inherit ROOM;

void create ()
{
  set ("short", "黄风厅");
  set ("long", @LONG

大厅地势开阔，数十个小妖正上窜下跳的不知忙些什么，
南面一张青花石案，案上摆满了珍馐美味。东北角上有
一出口，光线昏暗，看不出通向什么所在。

LONG);

  set("exits", ([
        "west" : __DIR__"dong3",
        "northeast" : __DIR__"yuandoor",
	"northwest" : __DIR__"dong4",
      ]));
  set("objects",([
          __DIR__"npc/huangfengguai":1,
	__DIR__"npc/yao":3,
                 ]));     
  setup();
}

int valid_leave (object me, string dir)
{
   me->delete_temp("obstacle/has_here");
   return 1;
}
