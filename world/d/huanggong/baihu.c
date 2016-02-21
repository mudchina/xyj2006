inherit ROOM;

void create()
{
  set ("short", "白虎堂");
  set ("long", @LONG

这里是武将们上朝前休息的地方，屋中并不是很大，靠墙放了
一排软椅，正中有一张八仙桌。上有茶壶茶杯和五色点心。偶
尔有几个官员出入，一个宫中侍女一旁伺候。
LONG);

        set("objects", ([
		__DIR__"npc/shinu": 1,
        ]) );

        set("exits",
        ([ /* sizeof() == 4 */
                "east" : "/d/huanggong/guangchang",
        ]));
	set("no_clean_up", 1);
        setup();
}

 

