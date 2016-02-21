//Cracked by Roath

inherit ROOM;
void create ()
{
      set ("short", "孝武街");
        set ("long", @LONG

    一条并不算宽的石板路,只够一辆马车通过，两旁的商号里
进进出出的人们都带着笑容，当你走过来的时候，老板们都不
失时机的向你邀喝着。你左顾右盼着。
LONG);
        set("exits",
        ([ //sizeof() == 4
                "west" : __DIR__"yamen",
                 "north": __DIR__"ngate",
                "south": __DIR__"xw-1",
      ]));
      set("objects", ([
                              __DIR__"npc/people" :1,
             ]));
    set("outdoors", "JZ");
 set("no_clean_up", 0);
        setup();
}
