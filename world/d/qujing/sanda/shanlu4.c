//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

千年古际，万载仙踪，碧梧鸣彩凤，活水隐藏龙，曲径罗荜垂挂，
石梯滕葛攀茏，猿哮翠岩菥月上，鸟啼高树喜晴空。两林竹荫凉
如雨，一径花浓没绣绒。

LONG);

  set("exits", ([
        "eastdown"     : __DIR__"shanlu3",
        "west"     : __DIR__"shanlu5",
      ]));
  set("objects", ([
        __DIR__"npc/nuzi":1,
        ]));
  set("outdoors",1);
  setup();
}
int valid_leave(object me, string dir)
{
   if (dir == "west" ) {
        if (objectp(present("nu zi", environment(me))))
        return notify_fail("女子对你笑道：你一定饿了吧，来吃点东西吧。\n");
        }
        return ::valid_leave(me, dir);
}
