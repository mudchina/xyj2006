inherit ROOM;

void create ()
{
  set ("short", "灌江口");
  set ("long", @LONG

灌洲灌江口，江水至此，豁然开阔。南面有一坐大庙，气象
恢鸿，门口有把门的鬼判，威风凛凛地巡视着四周。北面是
一大片丘陵，泾水远远地现于天际。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guipan" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/changan/eside4",
  "enter" : __DIR__"temple",
]));

  setup();
}

int valid_leave(object me, string dir)
{      object gui;
       if (dir=="enter" && 
           objectp(gui=present("gui pan",environment(me)))
           && living(gui) && 
	   member_array("gui pan",me->parse_command_id_list())==-1 )
	   return notify_fail("鬼判朝你大喝一声：呔！二郎爷爷的庙宇，谁敢乱闯！\n");
       return ::valid_leave(me,dir);
}



