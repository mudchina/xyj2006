//Cracked by Roath

inherit ROOM;

void create ()
{
        set ("short", "лют╡╣Й");
        set ("long", @LONG

    ╦у╫Ью╢ё╛дЦ╣зр╩яш©╢╣╫╣д╬мйгдг╨у╨успцШ╣дупефё╨
[35m
                ║У║У║У║У║У║У║У║У║У
                ║У   аХ╪глют╡   ║У
                ║У║У║У║У║У║У║У║У║У
[m
р╡пМуБ╦Ы╠╬╬м╡╩йгуЩвз╣даХ╪глют╡ё╛╣╚йгаХюо╟Е╥ЧнЯл╛╤х
╨цё╛ты╪сиокШцг╣длют╡н╤╣юр╡╡╩╢Мё╛╢С╪рр╡╬мо╟╧ъак║ё

LONG);

        set("exits",
        ([ //sizeof() == 4
                "south": __DIR__"sibei-w1",
      ]));
      set("objects", ([
                                __DIR__"npc/ling" :1,
                ]));

      set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
