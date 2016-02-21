// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "心月宫");
  set ("long", @LONG

        剑系风雪情

  雪                   风
  原                   雨
  莽                   纷
  莽                   纷
  雪                   风
  下                   中
  忆                   闯
  神                   江
  州                   湖
  雪                   风
  原                   雨
  映                   心
  丹                   相
  心                   戚


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"     : __DIR__"qinglongdian",
  "east"     : __DIR__"kangjingong",
  "northeast" : __DIR__"jishuigong",
  "southeast"  : __DIR__"weihuogong",

]));


  set("objects", 
      ([
       __DIR__"stars/yixue" : 1,
      ]));


  setup();
}
 
