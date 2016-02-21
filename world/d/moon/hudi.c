//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "湖底");
  set ("long", @LONG

到了湖底你才明白＂莲出淤泥而不染＂的真正含义．
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"lotuspond",
        ]));
  setup();
}
void init()
{
  add_action("do_dig", "dig");
}


int valid_leave(object me, string dir)
{
    	message_vision("$N拼命挣扎着爬上岸，肚子里灌满了水．\n", me);
	me->set("water", (int)me->max_water_capacity());
	return ::valid_leave(me, dir);
}

int do_dig(string arg)
{
  object me=this_player();
  object m; 
  if( (!arg) || !((arg == "lotusroot") || (arg == "root") || (arg == "ou")))
    return notify_fail("挖什么？\n");
  else
    {
      message_vision("$N用手刨了淤泥两下，希望能弄点藕吃．\n", me);
      if (random(6) < 1)
        {
       		 message_vision("$N刨啊刨，刨到一棵大莲藕．\n", me);
		 m = new(__DIR__"obj/ou.c");
       	   	 m->move(this_player()); 
	}
    }
  me->receive_damage("sen", (int)me->query("max_sen")*10/100);
  return 1;
}