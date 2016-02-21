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
        set_name("竹制物什", ({"zhuzhi wushi", "wushi"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一些竹子编织的东西，发放给村民劳动的。\n");
                set("unit", "套");
                set("value", 200);
                    
        }
}
