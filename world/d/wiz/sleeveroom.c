//mon. 1/11/98.

inherit ROOM;
#include "/cmds/std/valid_move.h";

void create ()
{
  set ("short", "Sleeve Room");
  set ("long", @LONG

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wizroom",
]));

  setup();
}

int clean_up()
{      // this is special for this room. no clean_up when there are
       //player homes inside.

       object *inv;
       int i;

       if(present("sleeve", this_object())) return 1;

       return ::clean_up();

}
