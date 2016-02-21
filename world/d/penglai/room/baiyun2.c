inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "白云洞");
  set ("long", @LONG

洞口虽小，洞内却别有天地。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"baiyun3",
  "northeast" : __DIR__"baiyun4",
  "north":      __DIR__"baiyun5",
]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}

