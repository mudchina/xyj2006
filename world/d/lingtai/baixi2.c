// Room: some place in 西牛贺洲
// uphill3.c

inherit ROOM;

void create()
{
  set ("short", "白石溪");
  set ("long", @LONG

潺潺流水向山下流去，溪水清彻见底。水底布满了大小不一，洁
白如玉的鹅卵石，溪中的小鱼游来游去。林中的鸟儿叽叽喳喳地
叫着。
LONG);
set("exits", ([ /* sizeof() == 4 */
"southup" : __DIR__"lantao",
"southeast": __DIR__"baixi",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


