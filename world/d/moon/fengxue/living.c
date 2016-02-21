//living.c

inherit ROOM;

void create ()
{
  set ("short", "·ãÑ©´óµî");
  set ("long", @LONG

·ãÑ©¹¬µÄ´óµî¡£(rules)(schedules)
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "schedules" : @LONG

jobs                  dates (of every month) responsible person 
monthly meeting       decided by the head    the head 
the table of contents the 1st                the acting chief 
the contents          the 3rd                the acting chief 
proofreading          the 5th                proof readers 
publishing            the 7th                techniqcal supports 
Ïê¼û£ºhttp://www.qucis.queensu.ca/home/guo/fxtd/schedule.html

LONG,
  "rules" : @LONG

Ïê¼û£ºhttp://www.qucis.queensu.ca/home/guo/fxtd/ruleC.html

LONG,
]));

  set("exits", ([ /* sizeof() == 4 */
   "west" : __DIR__"zoulang",
   "east" : __DIR__"restroom",
   "north" : __DIR__"meeting",
   "south" : __DIR__"fdoor",
]));

  set("objects", ([ /* sizeof() == 1 */
     __DIR__"npc/niu":1,
]));

  set("valid_startroom", 1);
  set("no_fight", 1);
  set("no_magic",1);

  setup();
  "/obj/board/fxtd_b"->foo();
}

