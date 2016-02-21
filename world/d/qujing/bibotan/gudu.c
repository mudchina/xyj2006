#include <room.h>
inherit ROOM;

int do_dive();
void create ()
{
  set ("short", "古渡口");
  set ("long", @LONG

这里乃是碧波潭边一个渡口，后来因潭中闹水怪，附近的百姓纷
纷迁到城中，渡口便荒废了下来。靠水边只有零零散散几根木头
搭着，似乎一阵风浪就可掀翻。远望湖心有一小岛，倒也树木茂
盛。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaolu1",
  "west" : __DIR__"xiaolu3",
]));

  setup();
}

void init()
{
    add_action("do_dive", "dive");
}
int do_dive()
{   object me,ridee;
        me=this_player();
if(me->is_busy()) return notify_fail("你正忙着呢!\n");
     ridee=me->ride();
            if( (!present("bishui zhou", me)) &&
	    (!((string)me->query("family/family_name")=="东海龙宫")) &&
	    (!((string)me->query("family/family_name")=="火云洞")) )
                return
notify_fail("你一个猛子扎到水里．．．\n\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

   if (ridee && ridee->query("under_water")) {
     message_vision("$N一拍$n的头，连人带马跃入水中。\n",me,ridee);
     ridee->move("/d/qujing/bibotan/tandi3");
   }
    else
                message_vision("$N一个猛子扎到水中，然后不见了．\n", me);
                me->move("/d/qujing/bibotan/tandi3");
		message_vision("$N游了过来。\n", me);
                return 1;
}

