
//shuitan.c 寻水灵珠
#include <ansi.h>
inherit ROOM;
int do_dive();
void create()
{
        set("short", "水潭");
        set("long", @LONG
迎面是一个瀑布，下面是一个巨大的水潭，瀑布倾泻入水潭，发出轰轰的巨响。
飞溅的水雾在阳光下出现了美丽的彩虹。潭中许多白色的鱼游来游去。
LONG);
   set("exits", ([
      "northeast" : __DIR__"shangu2",
   ]));
   set("resource", ([
      "water" : 1,
   ]) );
set("outdoors",1);
   setup();
}
void init()
{
   add_action("do_dive","dive");
}
int do_dive()
{
   object zhou,who,room;

   who = this_player();
   if(( !(zhou=present("bishui zhou", who))
 ||(string)zhou->query("unit")!="张")
 && (string)who->query("family/family_name")!="龙宫"
 && (string)who->query("family/family_name")!="东海龙宫")
 return notify_fail("你一个猛子扎到水里．．．\n"+
                           "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");
   message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, who);
   if(!( room = find_object(__DIR__"tandi")) )
   room = load_object(__DIR__"tandi");
   if(objectp(room))
   {
        who->move(room);
        message_vision("$N潜到了潭底。\n",who);
   }
   return 1;
}
