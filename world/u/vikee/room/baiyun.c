inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "白云洞");
  set ("long", @LONG

洞口虽小，洞内却别有天地。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"undertree",
  "northwest":__DIR__"baiyun1",
  "northeast":__DIR__"baiyun2",
  "north":__DIR__"baiyun3",

]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}

