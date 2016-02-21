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
        set_name("嫁衣", ({"jia yi", "jiayi"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "女孩子做梦都想得到的嫁衣。普通黎民又怎买得起？！\n");
                set("unit", "套");
                set("value", 50000);
                    
        }
}
