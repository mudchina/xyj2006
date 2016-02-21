#include <weapon.h>

inherit BLADE;

void create()
{
      set_name("大砍刀", ({"da kan dao", "blade", "dao"}));
      set_weight(8000);
      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "把");
        set("long", "一把大砍刀，刀背上挂着十几个大环。\n");
        set("value", 50000);
        set("no_give","这种宝贝怎能随便给人？\n");
        set("no_sell","掌柜的摇摇头说：这可是龙宫的宝贝，小店不敢收。\n");
        set("material", "gold");
        set("wield_msg", "$N大喝一声将$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n背在背后。\n");
        set("weapon_prop/dodge", -10);
        set("weapon_prop/blade", -10);
        }
        init_blade(30);
        setup();
}


