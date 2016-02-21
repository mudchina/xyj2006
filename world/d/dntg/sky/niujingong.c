// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "牛金宫");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"     : __DIR__"xurigong",
  "south"     : __DIR__"weiyuegong",
  "southeast" : __DIR__"shihuogong",
  "southwest" : __DIR__"bishuigong",
  "northwest" : __DIR__"doumugong",
  "northeast" : __DIR__"nutugong",

]));


  set("objects", 
      ([
       __DIR__"stars/wugeng" : 1,
      ]));


  setup();
}
 
