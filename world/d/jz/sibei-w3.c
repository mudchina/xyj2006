//Cracked by Roath

inherit ROOM;

void create ()
{
        set ("short", "[37m½­Öİ³ÇÎ÷ÃÅ[m");
        set ("long", @LONG

    Õâ±ãÊÇ½­Öİ³ÇµÄÎ÷ÃÅÁË£¬Õâ¸öµØ·½±ÈÆğ³¤°²³Ç¿ÉÕæÊÇ²îÔ¶ÁË¡£
 Ò»ÑÛ¶«Íû£¬¿ÉÒÔ¿´µ½Â·ÉÏÊèÊèÀÊÀÊµÄ¼¸¸öĞĞÈË£¬Õâ¸ö³ÇÃÅ¿´ÆğÀ´
Ò²ºÜ¾ÉÁË¡£ÉÏÊé£º
[1;32m
                ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
                ¡ù                    ¡ù
                ¡ù    ½­        Öİ    ¡ù
                ¡ù                    ¡ù
                ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
[m
LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"chengen-2",
                "west" : __DIR__"shanlu1",
      ]));

        set("objects",
        ([ //sizeof() == 1
           "/d/city/npc/wujiang" : 1,
        ]));


        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
