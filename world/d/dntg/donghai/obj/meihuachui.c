#include <weapon.h>

inherit HAMMER;

void create()
{
      set_name("八楞梅花亮银锤", ({"mei hua chui", "hammer", "chui"}));
      set_weight(8000);

      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "对");
        set("long", "一对亮银锤，上刻：＂八楞梅花亮银锤，重五千四百斤，东海龙宫打制＂。\n");
        set("value", 100000);
        set("no_give","这种宝贝怎能随便给人？\n");
        set("no_sell","掌柜的摇摇头说：这可是龙宫的宝贝，小店不敢收。\n");
        set("material", "gold");
        set("wield_msg", "$N运足力气气将$n提了起来。\n");
        set("unwield_msg", "$N将手中的$n放了下来。\n");
        set("weapon_prop/dodge", -40);
        set("weapon_prop/hammer", -40);
        }
        init_hammer(30);
        setup();
}


