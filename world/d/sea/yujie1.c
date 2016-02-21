inherit ROOM;

void create ()
{
  set ("short", "玉阶");
  set ("long", @LONG

由此向上是龙宫正殿，东海龙王就住在里面。一级级的台阶都是用　　　
玉砌成，阶上两边立着武士，银盔银甲，煞是威风。
LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lishi" : 2,
]));

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huilang1.c",
  "north" : __DIR__"huilang4.c",
  "westdown" : __DIR__"inside1.c",
  "east" : __DIR__"yujie2.c",
]));
//      
        set("water", 1);
//  
  setup();
}
/*
int valid_leave(object me, string dir)
{
        if( (string)me->query("family/family_name")=="东海龙宫" ) return 1;
	if( (string)me->query("family/family_name")=="龙宫" ) return 1;
	if( !me->query("family") ) return 1;
        if( wizardp(me)) return 1;
        if( present("yao pai", me) ) return 1;

        if (dir == "east"
	|| dir=="south" 
	|| dir=="north") {
        if (objectp(present("li shi", environment(me))))
        return notify_fail("宫前护卫伸手挡住了你的去路。\n");
        }   
        return ::valid_leave(me, dir);
}
*/

