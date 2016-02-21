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
        set_name("催情秘药", ({"cuiqing miyao", "miyao"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这东西说害人也不对，说有用也不对。。。\n");
                set("value", 10000);
                

        }
  
        set("is_monitored",1);
        setup();
}
