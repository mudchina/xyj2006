// gangcha.c

#include <weapon.h>
#include <ansi.h>

inherit FORK;

void create()
{
        set_name(HIG"神水叉"NOR, ({ "shenshui cha","cha","fork" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "iron");
                set("long", WHT"上古十二神兵之一：神水叉。\n"NOR);
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
        }
        init_fork(100+random(100));
        setup();
}

