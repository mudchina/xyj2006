// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "乔林");
  set ("long", @LONG

山原浩瀚秀丽，树木苍青葱翠，高大的乔木树林一望无际复盖
着大地。林中歪歪斜斜地横着一条光秃秃的小径，径头不知通
向何处。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"qiaolin1",
        "southeast"    : __DIR__"qiaolin4",
        "eastdown"    : __DIR__"ling6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_pansi")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_pansi","done");
	}
}
