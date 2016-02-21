// gate.c

inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG

周围有一些店铺，店家为了抢生意，把东西都摆到了街上．把一
条本来就不宽的石街占了大半．这里的人也显的较多，大多是些
乡下来的，来买上些日常用品．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"budian",
"south": __DIR__"tiepu",
"east" : __DIR__"road1",
"west" :__DIR__"road3",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


