//sgzl
inherit ROOM;

int check_food ();
int come_she ();
int back_she ();

void create ()
{
	set ("short", "雪岭");
	set ("long", @LONG

雪岭的尽头有一个小小的洞(cave)，据说里面有一只赤练
小蛇，吃了后可以大补，但怎么把它从洞里引出来，可就
没几个人知道了。
LONG);


        set("item_desc", 
        (["cave" : 
             "一个小洞，里面黑黑的，什么都看不见。\n", 
        ]));

	set("exits", 
	([ //sizeof() == 4
                "west" : __DIR__"no4-enter",
	]));
	
	set("objects", 
	([
	]));


        set("she_time",1);

	set("outdoors", "xueshan");

	setup();
}

void init()
  {
   remove_call_out ("check_food");
   call_out ("check_food", 5);
  }

int check_food ()
  {
  object who =this_player();
  object where = this_object();
  object douzi;

  if (present ("jiu dou", where)) 
        douzi = present ("jiu dou",where);
  if (douzi && douzi->query("value")==20000 && 
        ! present ("chilian xiaoshe", where)) 
        call_out ("come_she",3);
  remove_call_out ("check_food");
  call_out ("check_food",3);
  return 1;
  }

int come_she ()
  {
    object she;
    object where = this_object();
    object douzi = present ("jiu dou",where);
    object who =this_player();
    int stay_time=where->query("she_time")*2;

    if (douzi && douzi->query("value")==20000)
      {
       tell_room(where,"一只小蛇从洞里爬了出来，将"
          +douzi->query("name") +"叼在嘴里。\n",who);
       she=new("/d/xueshan/npc/she");
       she->move(where);
       destruct (douzi);
       call_out ("back_she",stay_time);
      }
    return 1;
  }

int back_she ()
  {
  object where = this_object();
  object who =this_player();
  object she = present ("chilian xiaoshe",where);

    if (she)
      {
       tell_room(where,she->query("name") +
          "将豆子一口吞了下去，然后机警的爬回洞里。\n",who);
       destruct (she);
       where->add("she_time",1);
      }
  return 1;
  }
