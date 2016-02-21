// yashi.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "雅室");
  set ("long", @LONG

高小姐的卧房便是这里．卧房吗．．窗前站着一位女子，正呆
呆的望着窗外出神，靠内有一张素净的床铺(bed)，但空荡荡
地不见一个人影．．．
LONG);

set("item_desc",(["bed":"睡觉用的床铺(gosleep,gobed,bed)。 \n", ]));
set("exits", ([ /* sizeof() == 4 */
"down" : __DIR__"guige",
]));

set("objects", ([ /* sizeof() == 1 */
"/d/gao/npc/gaoxiaojie" : 1,
]));

create_door("down", "雕花竹门", "up", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");
	add_action("do_zuoyao", "zuoyao");
}

int do_bed()
{       object me;
        me=this_player();
      	message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
  	me->move("/d/gao/bed_yashi");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
         	return 1;
}

int do_zuoyao()
{
	object me=this_player();
	object ob;
	if (me->query_temp("obstacle/zhutou")==1)
        return 1;

	if (me && (me->query_temp("obstacle/gao_asked")==1) && (me->query_temp("apply/name")[0] == "高小姐"))
	{
		message_vision("$N看到：窗口刮起一团黑风，一个黑影从窗口钻了进来\n",me);
		ob=new("/d/gao/npc/zhu");
		ob->move("/d/gao/yashi");
		 me->start_busy(1+random(2));
                 me->set_temp("obstacle/zhutou",1);

	}
	else
	{
		message_vision("$N在窗口望了半天什么也没发生。\n",me);
	}
	return 1;
}