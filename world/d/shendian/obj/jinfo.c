inherit ITEM;
void create()
{
        set_name("金佛", ({"jinfo", "fo"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","一个金制的古佛。");
                set("base_unit", "个");
                set("base_weight", 0);
                set("no_sell","这么珍贵的东西这里可不敢收！" );
                set("no_give","这么珍贵的东西给别人不大好吧"); 
        }
        setup();
}

