//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "白虎潭");
  set ("long", @LONG

潭中的水晶莹透彻，远望恰如一只白色的虎爪。潭中偶而有大
鱼跃出，溅起片片的水花。潭的对面有一幅高崖，崖下隐约看
到一个小的山洞。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wangyue",
]));


  set("outdoors", 1);
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
        me->move("/d/qujing/kusong/xuanjing");
        message_vision(HIY "只见$N浑身湿漉漉地从水里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

