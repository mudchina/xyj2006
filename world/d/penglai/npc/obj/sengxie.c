//Cracked by Roath
#include <armor.h>

inherit BOOTS;
void create()
{
        set_name( "僧鞋", ({ "seng xie", "xie" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("no_sell", 1);
                set("long", "一双圆口青布僧鞋，但看起来鞋底比一般僧鞋厚了许多，还有些针线缝补的痕迹。");
                set("value", 100);
                set("material", "boots");
                set("armor_prop/armor", 3);
                set("armor_prop/dodge", 3);
        }
        setup();
}
void init()
{
        add_action("do_tear", "tear");
}

int do_tear(string arg){
        object ob,me;

        me=this_player();
        if( !this_object()->id(arg) ) return 0;
        ob=new("/d/penglai/npc/obj/ditu");
        ob->move(me);
	message_vision("$N拿起僧鞋使劲一扯，「啪」的一声从鞋底夹层中掉出张小纸片。\n", me);
        destruct(this_object());
        return 1;
}

