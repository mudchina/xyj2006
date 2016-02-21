// archery.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

varargs void init_archery(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag); 
}

void setup()
{
	// ::setup();
	seteuid(getuid());

	if( clonep(this_object()) ) return;

	set("skill_type", "sword");
	set("apply/skill_type", "archery");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :));
		set("verbs", ({ "slash", "slice", "thrust", "pierce" }) );
	}
    if( !query("apply/actions") ) {
	   set("apply/actions", (: call_other, WEAPON_D, "query_apply_action" :) );
	   set("apply/verbs", ({ "shoot" }) );
    }

}
