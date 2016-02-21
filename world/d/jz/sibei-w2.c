//Cracked by Roath
//jiangzhou 
inherit ROOM;

void create ()
{
        set ("short", "泗北街");
        set ("long", @LONG

    你走在泗北街的石板上，街上的人匆匆忙忙的走着，好象有
很多心事，而街上的商贩们也有气无力的吆喝着，生意不是很兴
隆，南面是一家买冰糖葫芦的。

LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"egate",
                "west" : __DIR__"sibei-w1",
                "south": __DIR__"tanghulu",
      ]));
      set("objects", ([
				__DIR__"npc/people" :1,
		]));
        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
