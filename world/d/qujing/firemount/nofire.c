// room: nofire

inherit ROOM;

void create ()
{
  set ("short", "火焰山");
  set("outdoors", "firemount");
  set ("long", @LONG

大火已经被人扑灭了，四处还冒着一丝丝的残烟。

曾几何时这里的大火绵延八百里，四周寸草不生。据说当年太上老
君的炼丹炉被蹬翻，几块炉砖掉在此处，即化为火焰山。人一走进
去既成烟灰，更勿提东南西北。

现在一切都很平静了，你走在这里，感叹不已。

LONG);

    set("exits", ([
               "northwest" : __DIR__"shanwai",
               "eastdown"  : __DIR__"shanbian",
             ]));
setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_firemount")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_firemount","done");
	}
}
