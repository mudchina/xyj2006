#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIW "绝仙剑" NOR, ({ "juexian jian", "jian", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"绝仙剑\n"
);
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        set("no_sell", 1);
         set("no_drop", 1);
        set("no_put",1);
         set("no_give",1);
         init_sword(150);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int damage;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damage = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("sen",damage/2);
        victim->receive_damage("kee",damage/2);
        return HIW "绝仙剑忽然发出一阵啸声。\n" NOR;
        }
}
 
