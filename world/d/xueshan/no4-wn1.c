//sgzl
inherit ROOM;

int check_hudie ();

void create ()
{
	set ("short", "雪岭");
	set ("long", @LONG

天空中飘舞的雪花遮住了你的视线，只能隐隐看见前
面挂着一张小小的蜘蛛网(net)。
LONG);


        set("item_desc", 
        (["net" : 
             "一张蜘蛛网。\n", 
        ]));

	set("exits", 
	([ //sizeof() == 4
                "south" : __DIR__"no4-w1",
                "west" : __DIR__"no4-wn2",
	]));
	
	set("objects", 
	([
	]));

	set("outdoors", "xueshan");

	setup();
}

void init()
  {
   remove_call_out ("check_hudie");
   call_out ("check_hudie", 5);
  }

int check_hudie ()
  {
  object where = this_object();
  object hudie;

  if (present ("hu die", where)) 
    {
     hudie = present ("hu die",where);
     remove_call_out ("catch_hudie");
     call_out ("catch_hudie",3);
    }
  remove_call_out ("check_hudie");
  call_out ("check_hudie", 5);
  return 1;
  }

int catch_hudie ()
  {
  object who=this_player();
  object where = this_object();
  object hudie;


  if (present ("hu die", where))  hudie = present ("hu die",where);
  message_vision("$N被一股巨大的力量卷进了蜘蛛网。\n", hudie);
  hudie->move(__DIR__"zhuwang"); 
  tell_room(environment(hudie),hudie->name()+"被卷了进来。\n", who);
  return 1;
  }
