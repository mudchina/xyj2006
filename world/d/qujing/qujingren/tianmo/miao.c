inherit ROOM;


void append_laoren();
void dis_laoren();

void create ()
{
  set ("short", "天魔庙");
  set ("long", @LONG
小小的地方却供奉着一尊很大的神像,最上方的条幅上写着“天魔庙”.
这天魔不知道是何方神圣，小庙里香火不断，挂满了“有求必应”，
”长命百岁“.看来还是很灵验的，让你忍不住也想叩拜。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"out",	//现在没有设定出口，不知道要放在哪里好
  "north" : __DIR__"zoulang1",
]));

  setup();
}

void init()
{
    add_action("do_bai","koubai");
    add_action("do_bai","knock");

}

int do_bai()
{
    object me,who;
    me=this_object();
    who=this_player();
   
    message_vision("$N俯身虔诚的叩拜起来，口中念念有词，长..命..百..岁\n",who);
  
    if (OBSTACLE_D->query("cated_qjr"))
	{
	    	return 1;
  	}

    if (!present("zhenglong laoren",me) ) 
      	{
         	remove_call_out("append_laoren");
         	call_out("append_laoren",5);
 	}
    return 1;	
}


void append_laoren()
{
	object laoren;
	object me=this_object();

	laoren=new("/d/qujing/qujingren/tianmo/npc/laoren");
	laoren->move(me);
     	message_vision("$N掀开幕布走了出来\n",laoren);
	
	remove_call_out("dis_laoren");
	call_out("dis_laoren",60);
}

void dis_laoren()
{
	object laoren;
	object me=this_object();

	if (laoren=present("zhenglong laoren",me))
	   {
     		message_vision("$N转身走向后堂\n",laoren);
		destruct(laoren);
	   }	
}

int valid_leave (object who, string dir)
{
  if (dir=="south")return ::valid_leave(who,dir); 
  if (!OBSTACLE_D->query("cated_id"))
	return notify_fail("随便闯入恐怕不太好吧\n");
  if (who->query("obstacle/qujing")=="ren")
    {	//护送人需要过一定的时间才可以进去让抓的人有时间布置
	if (!OBSTACLE_D->query("open_door"))
	  return notify_fail("现在还不是闯进去的时候\n");
    } 

  return ::valid_leave(who,dir);

}

