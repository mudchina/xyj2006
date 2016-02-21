//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/lakeside1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "鹰愁陡涧");
  set ("long", @LONG

你一眼向涧下望去，只见涧内深陡宽阔，如刀削一般，水面清彻
澄清，经常有些鸟鹊经过此涧时，看见水清中自己的形影，误以
为是自己的同伴，而掷于水中，故名鹰愁陡涧。
LONG);

  set("exits", ([
        "east" : __DIR__"lakeside2",
        "southwest" : __DIR__"grass",
        "west" : __DIR__"grass2",
      ]));
  set("outdoors","yj");
  setup();

}
void init()
{
        object me = this_player();
        add_action("do_dive","dive");
                
        if( me->query("obstacle/yj") == "done" )
                return;
        if(! me->query("obstacle/sc") )
                return;
        if( me->query_temp("see_dragon") )
                return; 
        if( present("bai long") )
                return;

        remove_call_out("dragon_appear");
        call_out("dragon_appear",1,me);
        
}

int dragon_appear(object me)
{
        object dragon = new(__DIR__"npc/long");
        dragon->move(environment(me));
        tell_room(environment(me),HIW"忽然狂风大作，一条白龙自涧底冲出。\n"NOR);
        me->set_temp("see_dragon",1);
        message_vision(HIR"忽然白龙尾巴向$N狂卷而去。\n"NOR,me);
        me->unconcious();
        destruct(dragon);        
        return 1;
}

int do_dive()
{
        object me = this_player();
        object zhou; 
       if(( !(zhou=present("bishui zhou", me))
       ||(string)zhou->query("unit")!="张" ) )
       return notify_fail("你一个猛子扎到水里．．．\n"+
       "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

        message_vision(HIY "$N纵身一跃，跳进了深涧。\n" NOR, me);
        me->move(__DIR__"jiandi1");
        message_vision(HIY "$N从涧上跳了下来。\n"NOR,me);
        return 1;
}

