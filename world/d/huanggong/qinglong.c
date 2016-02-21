inherit ROOM;

void create()
{
  set ("short", "青龙堂");
  set ("long", @LONG

这里是文官们上朝前休息的地方，屋中并不是很大，靠墙放了
一排软椅，正中有一张八仙桌。上有茶壶茶杯和五色点心。偶
尔有几个官员出入，一个宫中侍官一旁伺候。
LONG);

        set("objects", ([
		__DIR__"npc/shiguan": 1,
        ]) );

        set("exits",
        ([ /* sizeof() == 4 */
                "west" : "/d/huanggong/guangchang",
        ]));
	set("no_clean_up", 1);
        setup();
}

 

