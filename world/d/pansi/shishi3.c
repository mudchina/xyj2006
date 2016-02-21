// shishi3.c
// by lestat/2000.1.31

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", HIG"逍遥津"NOR);
	set("long", @LONG
这里是一个极大的石室，比之外面的任何一个都大了数倍，室中一排排
地列满了木制成的书架(shelf),可是书架上却空荡荡地连一本书也没有。
室中还有一张寒冰床(bed)。
LONG );
	set("exits", ([
		"south" : __DIR__"shidong",
	]));
	set("item_desc", ([
		"bed"   : "一张千年寒冰床,看来你可以移动一下它。\n",
		"shelf" : "书架上贴着一张小贴：“乘天地之正，御六气之辩，以游于无穷，是为逍遥。”\n",
	]));
		set("objects",([
		__DIR__"obj/guo" : 3,
		__DIR__"npc/jikao" : 1,
	]));
//	set("book1_count",1);
	set("no_clean_up", 0);
	setup();
}

int do_move(string arg)
{
	object me;

	me=this_player();
	if(!arg || arg!="bed") return 0;
	message_vision("$N用力把小床移开，发现里面竟然有一条秘密通道！\n",me);
	me->move(__DIR__"midao1");
	tell_object(me,"接着是一阵轰隆隆的响声，你定神一看，自己已经处身在秘密通道中了。\n");
	return 1; 
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
		add_action("do_move","move");
		add_action("do_strike","strike");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\n纱帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}
int do_strike(string arg)
{
        object me = this_player();
		object sha;
		
if( me->query("rulaitask/get") )
             {message_vision(CYN"\n你现有任务在身，哪有功夫啊。\n"NOR,me);
              return 1;
             }
if( me->query_temp("pkgame") )
    return notify_fail("你还是等比赛结束了再来吧。\n");
             
        if(!arg || arg!="shelf") return 0;
        message_vision("$N看着看着，忽然猛的一掌向书架打去！震得书架“克拉，克拉”的响了几声。\n",me);
	
//     if (random(100) > 1 && this_player()->query("mark/daya-jian"))
if (random(100) > 97 && this_player()->query("mark/daya-jian") && this_player()->query("combat_exp") > 6600000 )
	{
      if (this_player()->query("mark/dayagett"))
	  {
        message_vision("忽然，$N听到一个声音嘿嘿地奸笑！”\n",me);
        message_vision("接着，不知道哪里射出一支毒箭，射中了$N！\n",me);
        me->die();
	  }
	  else {
		sha = new (__DIR__"obj/daya-book");
     	this_player()->set("mark/dayagett", 1);
		sha->move(me); 
		me->move(__DIR__"shishi3");
        message("channel:rumor", MAG"【江湖传闻】某人："+this_player()->query("name")+"在盘丝洞得到了大雅古剑谱啦。\n"NOR, users());
		tell_object(me, "突然只见一件东西从书架上轻轻飘落了下来！你赶紧捡起来藏在怀里！\n");
	}
	}
	  else { 
		message_vision("忽然，$N听到一个声音嘿嘿地奸笑！”\n",me);
        message_vision("接着，不知道哪里射出一支毒箭，射中了$N！\n",me);
		me->die();
//				tell_object(me, "突然只见一件东西从书架上轻轻飘落了下来！你赶紧捡起来藏在怀里！\n");

	  }

        return 1; 
}
