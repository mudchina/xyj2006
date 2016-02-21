inherit ITEM;
inherit F_FOOD;

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
        set_name("团圆宴席", ({"tuanyuanyanxi", "yanxi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一桌香喷喷、热腾腾的团圆宴席。\n");
                set("unit", "桌");
                set("value", 250000);
                    set("food_remaining", 20);
                    set("food_supply", 100);
        }
}
