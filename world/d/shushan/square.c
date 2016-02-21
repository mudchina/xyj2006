
inherit ROOM;

void create()
{
        set("short", "广场");
        set("long", @LONG
蜀山的广场上冷冷轻轻，只有一两个剑童
垂首肃立，青石铺就的地面，上面有坑坑洼洼
的痕迹，大概是几百年来，弟子练功的痕迹
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dadian",
  "east" : __DIR__"jinglou",
  "south" : __DIR__"paifang",
]));

        set("objects",([
        __DIR__"npc/jiantong" : 2,
        __DIR__"npc/zhangmen" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
