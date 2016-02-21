//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//baicaidi.c

inherit ROOM;
#include <room.h>

void create ()
{
   set ("short", "白菜地");
   set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是白菜地。
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "south" : __DIR__"qiezidi",
     "northwest" : __DIR__"xiguadi",
     "north":    __DIR__"tree",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     "/d/obj/food/xbc" : 2,
   ]));
   set("outdoors", "wuzhuang");

   setup();
}
