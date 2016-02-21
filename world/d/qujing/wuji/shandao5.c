// snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

山道崎岖不平，沿着山势上下左右盘绕，地形十分险恶。群峦环绕，难辨
东西南北。大风吹来，有点令人寒颤。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : "/d/qujing/chechi/shatan3",
  "northeast" : __DIR__"shandao4",
  "north" : "/d/qujing/kusong/songlin1",
]));

  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_wuji")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_wuji","done");
	}
}
