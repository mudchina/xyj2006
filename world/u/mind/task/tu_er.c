inherit ITEM;


void init()
{
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
        set_name("宝物图二", ({"baowu tuer", "tuer"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "某人画的宝物图之二。\n");
                set("unit", "张");
                set("value", 1000);
                    
        }
}
