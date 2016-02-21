 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "柳土宫");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north"     : __DIR__"yihuogong",
  "southeast" : __DIR__"xingrigong",
  "northeast" : __DIR__"guijingong",

]));


  set("objects", 
      ([
       __DIR__"stars/feixiao" : 1,
      ]));


  setup();
}
 
