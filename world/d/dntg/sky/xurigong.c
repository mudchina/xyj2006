// Room: /d/sky/nantianmen
 
#include <ansi.h>
inherit ROOM;

void init();

void create ()
{
  set ("short", "虚日宫");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"niujingong",
  "north"     : __DIR__"caihongqiao2",
  "southeast" : __DIR__"nutugong",
  "southwest" : __DIR__"doumugong",

]));


  set("objects", 
      ([
       __DIR__"stars/fer" : 1,
      ]));


  setup();
}
 
