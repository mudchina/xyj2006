#include <ansi.h>

inherit ITEM;


void init()
{
      if(this_player()==environment())
        
      call_out("announce",random(10),this_player());
}

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            who->query("name")+"得到了"+name()+"！\n");
}

void create()
{
set_name("《阎王生死簿》", ({"shengsibu", "bu"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "《阎王生死簿》闪着蓝幽幽的光。。。\n");
                set("value", 10000);
                

        }
  
        set("is_monitored",1);
        setup();
}
