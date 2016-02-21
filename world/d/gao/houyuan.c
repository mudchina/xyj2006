// houyuan.c

inherit ROOM;

void create()
{
  set ("short", "后院");
  set ("long", @LONG

后院之中极为宽敞，秋收时就是高家晾晒稻谷的地方．东边靠墙有
一口土井，旁边放了几只木桶．西边一座小楼，是小姐住的地方，
北边是高家的后花园．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"huayuan",
"south" : __DIR__"zhting",
"east" : __DIR__"washing",
"west" :__DIR__"guige",
]));
	set("outdoors", 1);
        set("no_clean_up", 0);
	set("resource/water", 1);
        setup();
        replace_program(ROOM);
}


