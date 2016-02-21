inherit ROOM;

void create()
{
  set ("short", "农舍");
  set ("long", @LONG

一间宽敞的农舍，打扫的干干净净。屋里正中是祖先的牌位，供案
上有几乎盘蜡做的水果。墙角堆着各种瓜果蔬菜，让你直流口水。
LONG);

set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"cunkou",
]));

set("objects", ([
            "/d/ourhome/obj/xbc" : 1,
            "/d/ourhome/obj/beans" : 1,
            "/d/ourhome/obj/carrot" : 1,
]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

