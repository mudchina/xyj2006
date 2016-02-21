// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "大路");
  set ("long", @LONG

一条烟尘漫漫的大路，其路遥遥，其雾茫茫，前不见古人后不
见来者。时而有远方兽吼，时而又有近处鸟鸣。两边荒山野林
交替出现，你不由自主地加快步伐。

LONG);

  set("exits", ([
        "east"    : __DIR__"dalu15",
        "west"    : "/d/qujing/yinwu/huangye7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_qinfa")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_qinfa","done");
	}
}

