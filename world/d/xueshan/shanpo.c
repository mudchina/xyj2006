//sgzl
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "山坡");
	set ("long", @LONG

这里便是雪山弟子平日起居的处所了，地上积了
厚厚的雪，而往来的雪山弟子从不感到严寒。
LONG);


	set("exits", 
	([ //sizeof() == 4
                "down" : __DIR__"xuejie-2",
                "north" : __DIR__"shanpohou",
                "east" : __DIR__"chufang",
                "west" : __DIR__"restroom",
	]));
	
	set("objects", 
	([
                "/d/xueshan/obj/rack" : 1,
	]));


	set("outdoors", "xueshan");

        create_door("east", "厨房门", "west", DOOR_CLOSED);
        set("no_clean_up", 0);

	setup();
}



