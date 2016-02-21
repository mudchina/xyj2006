// Room: some place in 西牛贺洲
// uphill3.c

inherit ROOM;

void create()
{
  set ("short", "白石溪");
  set ("long", @LONG

又往上走了一段，山路好象不那么陡峭了。路旁还出现了一条
小溪。小溪不深，溪水清彻见底。溪中的小鱼游来游去，岸边
的杂草中传来青蛙呱呱的叫声。偶尔几只小鸟飞过，鸟啼配着
清泉叮当宛如仙乐。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"uphill4",
"southdown": __DIR__"uphill2",
"northwest": __DIR__"baixi",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}

int valid_leave (object me, string dir)
{
        if (dir == "northwest"){
                message_vision ("$N挽起裤腿，跳到了小溪中。\n",me);
        }
  return 1;
}

