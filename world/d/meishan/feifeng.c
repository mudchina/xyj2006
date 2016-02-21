
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "飞凤峰");
  set ("long", @LONG

立于山颠而望四周，唯山边有数朵白云，如同鸾鹤翔舞徘徊，久
久不散，令人惊异。望灌江边小镇，皆茅草屋顶，竹编篱笆，宛
然有着幽雅的情趣。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/erlang" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"cuiping",
]));

  setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob = this_player();

        if( ! arg || arg != "down" )
                return notify_fail("你要向哪跳？\n");
        
        if(present("erlang zhenjun") )
                return notify_fail("二郎真君摇摇头：何苦要寻短见呢。\n");

        message_vision("只见$N纵身一跃，跳下了万丈悬崖。",ob);
        ob->move(__DIR__"fengdi");
        ob->unconcious();
        return 1;
}
