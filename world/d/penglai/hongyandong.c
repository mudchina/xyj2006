//Cracked by Roath

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "红颜洞");
  set ("long", @LONG

一间占地不大的岩洞，石榻石桌石椅，布置得高雅脱俗。
石桌上放着一副松枝松子所制的棋具，屋角焚着一炉百花
香，散发着淡淡花香。香炉边摆着一具松木瑶琴。百花仙
子闲来无事时，便在此与好友百草仙子、麻姑、织女抚琴
弈棋，消遥自在。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"penglai",
  "south" : __DIR__"baihuajiao",
    "out": __DIR__"bomingyan",
]));
  set("objects", ([ 
     __DIR__"npc/baihua-xianzi" : 1,
]));
  
  setup();
}
int valid_leave(object me,string dir) {


  object xianzi;
  if (dir=="northdown" || !xianzi=present("baihua xianzi",environment(me)) )
    return ::valid_leave(me,dir);
  if (!living(xianzi)) return ::valid_leave(me,dir);
  if (me->query("family/family_name")!="月宫") return notify_fail("百花仙子一把揪住你：“不是月宫的人不许进！”\n");
  if (me->query("family/master_name")=="嫦娥") return notify_fail("百花仙子拦在你面前，冷冷地说：“是你师父派你来扰我清修的？”\n");
  if (dir=="out" && random(2)) {me->start_busy(random(2));return notify_fail("百花仙子拉住你的手，叮咛道：“外面是悬崖峭壁，千万小心！”\n");}
  return ::valid_leave(me,dir);
}
