// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "石门");
  set ("long", @LONG

一个幽幽的门洞，洞顶上挂有一个石牌，上边刻着：九曲盘恒
洞五个大字。洞的西北边有一入口通向一个大厅，东边有一通
道通向餐厅。

LONG);

  set("exits", ([
        "east"   : __DIR__"can",
        "northwest"   : __DIR__"da",
        "southwest"   : __DIR__"shanlu10",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



