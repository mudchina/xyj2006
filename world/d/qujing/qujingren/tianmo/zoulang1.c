inherit ROOM;

void create ()
{
  set ("short", "第一走廊");
  set ("long", @LONG
一条长长的走廊被分成了好几个关口,这里是第一关.你可以感觉得到
隐藏的危机.非常中国风格的走廊,习惯性的雕龙刻凤.美和丑,善和恶
就这样矛盾的交织着。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zoulang2",
  "south" : __DIR__"miao",
]));

  setup();
}

void init()
{
   add_action("do_defend","defend");
   add_action("do_defend","fangshou");
   add_action("do_defend","shouhu");
   
}

int do_defend(string arg)
{
   object me,who;

   me=this_object();
   who=this_player();

   if (who->query("id")!=OBSTACLE_D->query("cated_id"))return 0;
   
   if (!arg) return notify_fail("你要谁防守这里呢?\n");

   if (arg=="none") 
	{
		write("你撤掉了这里的防守\n");
		me->delete("shouhu")	;
		return 1;
	}

   write("你指定"+arg+"防守这里\n");   
   me->set("shouhu",arg);
   return 1;
}

int valid_leave (object who, string dir)
{
  object man;
  object me=this_object();
  string shouhu;

  if (dir=="south")return ::valid_leave(who,dir); 
  if (who->query("obstacle/qujing")=="ren")
    {	
        shouhu=me->query("shouhu");
	if (shouhu)
          {
    	    if (man=find_player(shouhu))
	      {
		if (environment(man)==me)
		   return notify_fail(man->query("name")+"防守这里,你要打败他才过得去\n");
	      }
          }
    } 

  return ::valid_leave(who,dir);

}

