#include <armor.h>

inherit HEAD;

void create()
{
        set_name("ºìÄ¾µÀ¹Ú", ({ "bonnet", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("long", "Ò»¶¥Ó²ºìÄ¾µÄµÀ¹Ú¡£\n");
                set("material", "steel");
                set("value", 100);
                set("armor_prop/armor", 1);
		set("armor_prop/intelligence", 1);
		set("armor_prop/personality", 1);
        }
        setup();
}

