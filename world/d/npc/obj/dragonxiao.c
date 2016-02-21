//made by gogogo
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"盘龙箫"NOR, ({"dragon xiao","xiao","sword"}));
   set_weight(1000);
   if (clonep())
          set_default_object(__FILE__);
   else {
          set("unit", "根");
          set("long", "一根刻有龙的笛子，相传很有灵气。\n");
          set("value", 100000);
          set("no_sell", 1);
          set("no_drop", 1);
          set("material", "wood");
          set("wield_msg", "$N拿起$n，登时有条神龙从笛子飞出。\n");
          set("unwield_msg", "$N将$n收了起来，神龙刹那间消失了。\n");
          set("music/type", "xiao");
   }
   init_sword(180);
	setup();
}
