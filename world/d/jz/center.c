//Cracked by Roath
inherit ROOM;

void create ()
{

      set ("short", "城中心");
        set ("long", @LONG

    不大不小的城市中心，来来往往的人倒也不少，只是
一个个都在忙和着自己的事，路人中还夹杂着一些红发绿
眼的异类，他们好象从西方乘船而来，要到长安去。在中
心，你已经能看到东门了。

LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"sibei-w1",
                "west" : __DIR__"pingan-1",
                "north": __DIR__"xw-1",
                "south": __DIR__"dingan-1",
      ]));
      set("objects", ([
                                __DIR__"npc/people" :1,
                ]));
    set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
  }
