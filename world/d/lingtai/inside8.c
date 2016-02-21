// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "练功室");
  set ("long", @LONG

室中静悄悄的，几位道长正在打座练功。正中一个小铜香炉，里
面烧的是上好软香，发出淡淡紫烟。南边是练武场。
LONG);
set("exits", ([ /* sizeof() == 4 */
"south": __DIR__"inside2",
]));
set("objects", ([
		__DIR__"npc/laodao": 1,

]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



