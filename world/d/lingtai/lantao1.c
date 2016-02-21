// Room: some place in 西牛贺洲
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "松树林");
  set ("long", @LONG

松林之中非常的暗，光线全被如伞如盖的树枝挡住。地下布
满枯枝，每走一步都会发出很翠的响声，不时可看到几个砍
柴的道士。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"lantao",
"southdown" : __DIR__"forrest",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 1,
"/d/lingtai/npc/kancai": 1
]));
	set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


