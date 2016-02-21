// nine-ring.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIY "九环锡杖" NOR, ({ "nine-ring staff", "staff" }) );
	set_weight(90000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", HIY "此乃我祖如来所赐之九环锡杖，上面镶著九个铜环，象征佛法无边。\n" NOR);
		set("value", 50000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N拿出一条九环锡杖握在手中，刹那间四周一片肃穆，连天地鬼神也为之震动。\n\n" NOR);
		set("unwield_msg", HIY "\n$N放下手中的九环锡杖，周围的人才喘过一口气来。\n\n" NOR);
	}

	init_staff(90);
	setup();
}
