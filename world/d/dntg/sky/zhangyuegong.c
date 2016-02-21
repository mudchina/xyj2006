// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "张月宫");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south"     : __DIR__"guijingong",
  "north"     : __DIR__"zhuquedian",
  "southwest" : __DIR__"yihuogong",
  "southeast" : __DIR__"zhenshuigong",

]));


  set("objects", 
      ([
       __DIR__"stars/lady" : 1,
      ]));


  setup();
}
 
