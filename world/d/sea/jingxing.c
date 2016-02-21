inherit ROOM;

void create ()
{
  set ("short", "静性堂");
  set ("long", @LONG

静性堂四四方方，正面墙上高挂一幅“龙腾四海”的古画。画中的
虬龙鳞爪劲张，似乎要从画中跳出来样的。左右两排软椅，东面有
一高几，大概这里是开会的地方。
LONG);
         set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/biantidu" : 1,
  __DIR__"npc/lizongbing" : 1,
]));


  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"inside6",
  "northeast" : __DIR__"mulang2.c",
  "northwest" : __DIR__"shanhua.c",
]));
//      
        set("water", 1);
//  
  setup();
}

