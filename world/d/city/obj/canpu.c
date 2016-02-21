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
        set_name("天下名器残谱", ({"mingqi canpu", "canpu"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一张天下名器残谱,里面居然没有定海神针，难道。。。\n");
                set("unit", "张");
                set("value", 25000);
                    
        }
}
