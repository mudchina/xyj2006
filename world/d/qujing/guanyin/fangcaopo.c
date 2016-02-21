inherit ROOM;

void create ()
{
  set ("short", "芳草坡");
  set ("long", @LONG

这儿有几个石椅，还有一个石桌。两边的悬崖峭壁，峻岭平
岗。真是个好风光。这儿是这儿怪谈天说地的地方。 
LONG);
 
        set("objects", 
        ([ //sizeof() == 3
        ]));
  set("exits", ([
        "south" : __DIR__"lingdao4",
        "northdown"  : __DIR__"lingdao3",
      ]));

  set("outdoors", __DIR__);

  setup();
}
int valid_leave (object me, string dir)
{
	if ( dir == "northdown" )
	call_out("leave_here",60+random(120),me);
	return 1;
}
void leave_here(object me)
{
      object xiushi;
      if (! present("xiushi",environment(me)))
      {
        xiushi = new(__DIR__"npc/xiushi");
        xiushi->move(environment(me));
	tell_object(me,"忽然一阵沙沙声，转眼间，从杂草中钻出个人来！\n");
	call_out("destruct_me",300+random(120),xiushi);
      }else{
	tell_object(me,"莫名其妙的一阵沙沙声传过！\n");
      }
}
void destruct_me(object me)
{
	if(me){
	destruct(me);
	tell_object(this_player(),"白衣秀士倏地一声，没了踪迹！\n");
	}
}
