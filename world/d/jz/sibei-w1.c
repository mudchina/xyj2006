//Cracked by Roath

inherit ROOM;

void create ()
{
 
      set ("short", "泗北街");
        set ("long", @LONG

    你走在泗北街的石板上，街上的人匆匆忙忙的走着，好象有
很多心事，而街上的商贩们也有气无力的吆喝着，生意不是很兴
隆，北面是一家卖汤圆的.东面好象是中心了。

LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"sibei-w2",
                "west" : __DIR__"center",
                "north": __DIR__"tangyuan",
      ]));
      set("objects", ([
                                __DIR__"npc/people" :1,
                ]));

      set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
