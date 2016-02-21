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
        set_name("民间货帽", ({"minjian huomao", "huomao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一套普通的民间货帽，大唐黎民甚是喜欢。\n");
                set("unit", "套");
                set("value", 2500);
                    
        }
}
