#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("铁扇", ({"tie shan", "tieshan", "shan", "iron fan", "fan"}));
  set_weight(34000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "一把大铁扇，法力无穷。\n");
    set("value", 30000);
    set("material", "iron");
    set("wield_msg","$N「唰」地打开$n握在手中，扇了一扇。\n");
    set("unwield_msg","$N将手中的$n收起，顺手擦了擦汗。\n");
    set("weapon_prop/int", 2);
  }
  set("no_get", "铁扇磁铁般地吸在地上，你拿不起来。\n");
  set("no_drop", "只听唰地一声，铁扇又自动地飞回你身上。\n");
  set("no_give", "只听唰地一声，铁扇又自动地飞回你身上。\n");
  set("no_sell", "只听唰地一声，铁扇又自动地飞回你身上。\n");
  set("is_monitored",1);
  init_sword(25);
  //changed from 100 to 25...weiqi,970927. though it's a fabao, 
  //not necessarily has high damage. actually, as a sword, should not.
  setup();
}

