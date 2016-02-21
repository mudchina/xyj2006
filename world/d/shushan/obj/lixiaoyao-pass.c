#include <armor.h>
#include <ansi.h> 
inherit HEAD;
inherit F_UNIQUE;
void create()
{
        set_name(BLU"蓝布头巾"NOR, ({ "lixiaoyao xinwu","xinwu","lanbu toujin","toujin" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", "一顶瓦兰缎子制成的丝带，用来束发。\n");
                set("value", 300);
                set("replace_file", "/d/obj/cloth/wulingjin");
				set("material", "cloth");
                set("armor_prop/armor", 100);
		set("armor_prop/personality", 1);
        }
        setup();
}

