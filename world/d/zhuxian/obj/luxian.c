#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIC "戮仙剑" NOR, ({ "luxian jian", "jian", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"戮仙剑\n"
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
//victim->start_busy(1);
        return HIY "戮仙剑忽然发出耀眼的光芒，$n眼睛都睁不开了。\n" NOR;
        }
}
 
