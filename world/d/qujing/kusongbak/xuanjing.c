#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "玄晶洞");
  set ("long", @LONG

洞中的石壁上闪耀耀地嵌着许多水晶，在洞内幻出许多虚象。
洞外便是白虎潭，如同一面大的镜子。潭后是大片大片的草原，
延绵到天的尽头。
LONG);
  set("exits", ([ /* sizeof() == 4 */
//  "south" : __DIR__"wangyue",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/qixiushou" : 3,    
]));



  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me = this_player();

message_vision(HIY
"$N纵身一跃，跳入潭中。只见$N使足了全身力气，手足并用，不一会儿就游到了潭的对岸。\n" NOR,
me);
        me->move("/d/qujing/kusong/baihu");
        message_vision(HIY "只见$N浑身湿漉漉地从水里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

