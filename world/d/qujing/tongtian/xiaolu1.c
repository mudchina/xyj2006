// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

小路长长弯弯，路上铺着碎石，已被过往的车轮压出两道槽印，
路边有一棵棵青树，结着各种青果红果不记其数，路的两边是
农田种着庄稼。

LONG);

  set("exits", ([
        "southeast"   : __DIR__"hexi2",
        "west"   : "/d/qujing/jindou/shanlu5",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_tongtian")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_tongtian","done");
	}
}


