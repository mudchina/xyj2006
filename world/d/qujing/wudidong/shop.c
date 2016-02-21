//shop.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "张家老店");
	set("long", @LONG

张小二天生是个好动不好静的主儿。刚把店从他爹那儿接过来没一个
月，就整理过几十上百回了，搞得他自己都找不到东西。村子穷，张
小二也拿不出什么好东西卖，无非是些家常酒菜之类。墙上有块牌子
(sign)，似乎这里还可以过夜。

LONG
        );
	set("no_clean_up", 1);
	set("resource/water", 1);
	set("exits",([
		"north"  : __DIR__"road2",
		"south" : __DIR__"kefang",
        ]));
	set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]));
	set("item_desc", (["sign":"
\t本店客房，一夜二两白银。小人店小利薄，概不赊欠。

\t又：免费提供茶水。\n
"]));
        set("valid_startroom", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "south" )
                return notify_fail("没付房钱就想住店？\n");
        return ::valid_leave(me, dir); 
}
