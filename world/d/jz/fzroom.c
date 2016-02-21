//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */


inherit ROOM;

void create ()
{
        set ("short", "方丈室");
        set ("long", @LONG

一间小小的斗室，也没有窗户。房间里只点了一盏小油灯，显的特别
昏暗。一榻一几已占去房间的大半，榻上有几个软垫，也是破旧不堪。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits",
        ([ //sizeof() == 4
                "north" : __DIR__"dadian",
        ]));
      set("objects",
        ([ //sizeof() == 1
      __DIR__ "npc/faming" : 1,
        ]));

   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
