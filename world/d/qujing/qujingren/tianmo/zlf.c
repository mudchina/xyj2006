inherit ROOM;

void create ()
{
  set ("short", "蒸笼房");
  set ("long", @LONG
一个偌大的蒸笼放在房子中央,四处烟雾弥漫,热气腾腾,奇怪的是
竟然没有一丝火星.你只感觉到热,还有一股莫名的香味.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zoulang7",
]));

  setup();
}

void init()
{
   add_action("do_xian","xian");
   add_action("do_xian","掀");
}

int do_xian()
{
  object qujingren,rou;
  object me=this_object();
  object who=this_player();

  
  if (me->query_temp("xian"))return 0;
  if (who->query("obstacle/qujing")=="ren")
    {
  	message_vision("$N用力的掀开蒸笼盖,看到可怜的取经人正躺在里面\n",who);
  	message_vision("$N一把把取经人抱了出来\n",who);
 
  	qujingren=new("/d/qujing/qujingren/"+OBSTACLE_D->query("guan")
                   +"/qujingren");
  	qujingren->move(me);
  	me->set_temp("xian",1);
  
  	who->command_function("cry qujing ren");
  	remove_call_out("append_laoren");
  	call_out("append_laoren",5);
	return 1;
    } 
  if (who->query("id")==OBSTACLE_D->query("cated_id"))
    {
	if (OBSTACLE_D->query("obstacle_fail"))
	  {
		message_vision("$N兴高采烈的掀起蒸笼盖,挖塞!六块取经人的肉\n",
			who);
		who->command_function("rumor "+who->query("name")+
			"获得六块取经人的肉");
		for (int i=1;i<=6;i++)
		   {
 		      rou=new("/d/qujing/qujingren/obj/rou");
		      rou->move(who);
		   }	
		OBSTACLE_D->delete("cated_id");
		return 1;
	  }  
    }
    return notify_fail("笼里正蒸着东西呢,还没熟的话，最好不要乱掀\n");


}

void append_laoren()
{
	object laoren;
	object me=this_object();

	laoren=new("/d/qujing/qujingren/tianmo/npc/laoren");
	laoren->move(me);
     	message_vision("$N走了过来\n",laoren);
	
}


