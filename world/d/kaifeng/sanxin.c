//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "三心宫");
  set ("long", @LONG

三心宫里面供着一个青玉大案，上面有青铜香炉，里面插着香正冒着
袅袅的青烟。宫的东西两边都绘着各种神像，北边通向三个不同的宫
殿，南边是出口。

LONG);

  set("exits", ([
        "south" : __DIR__"wanshou",
        "north" : __DIR__"ningxin",
      ]));

  setup();
}

void init ()
{
  object who = this_player();
  string key;
  int i,j,k,m;
  mapping colors;

  if (who->query_temp("kaifeng_qingxin") &&
      who->query_temp("kaifeng_ningxin") &&
      who->query_temp("kaifeng_jingxin"))
  {
    who->start_busy (1,1);
    who->delete("quest/pending");
    who->delete_temp("kaifeng_qingxin");
    who->delete_temp("kaifeng_ningxin");
    who->delete_temp("kaifeng_jingxin");

    //penalty for cancelling.
    // randomly remove 1 cloud.
    // mon 12/17/98
    colors=who->query("quest/colors");
//    for(i=1;i<=3;i++) {
	j=sizeof(colors);
	if(j>0) {
	    k=random(j);
	    key=keys(colors)[k];
//	    m=colors[key]-1;
//	    if(m>0)
//		colors[key]=m;
//	    else
		map_delete(colors,key);
	}
//   }
    who->set("quest/colors",colors);

    who->set_temp("kaifeng_donate_silver",0);
    // delete temp after finish san-xin.

    call_out ("feeling",1,who);
  }
}

void feeling (object who)
{
  who->interrupt_me();
  message_vision ("$N走出三心宫，呼出一口气，顿时心境明朗如镜。\n",who);
}

