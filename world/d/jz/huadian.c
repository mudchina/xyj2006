//Cracked by Roath
inherit ROOM;
#include <ansi.h>
void create ()
{
      set ("short", HIG"鲜花店"NOR);
      set ("long", @LONG

    江州依山傍水，所以各种鲜花当然是随处可见，如果您要
买一些名贵的鲜花，只要问这位老板就是了，离得好远，你就
闻到一股令人心醉的香味。

LONG);
        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"xw-1",
      ]));
      set("objects", ([
                     __DIR__"npc/hehua": 1,
                ]));
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
  }
