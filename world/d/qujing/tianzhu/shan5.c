// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山冈");
  set ("long", @LONG

高高的山冈上，山路顺着山势起伏，道路凸凹不平铺着大大小
小的石头块。路边怪石林立形状不可言逾，山路时宽时窄，路
边长着长长的荒草。

LONG);

  set("exits", ([
        "north"   : __DIR__"shan4",
        "east"   : "/d/qujing/jinping/cunlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_tianzhu")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_tianzhu","done");
	}
}



