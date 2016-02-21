#include <weapon.h>

inherit SPEAR;

void create()
{
      set_name("画杆方天戟", ({"hua gan ji", "huaji", "ji"}));
      set_weight(8000);

      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "柄");
        set("long", "一柄方天画戟，上刻：＂画杆方天戟，重七千二百斤，东海龙宫打制＂。\n");
        set("value", 400000);
        set("no_give","这种宝贝怎能随便给人？\n");
        set("no_sell","掌柜的摇摇头说：这可是龙宫的宝贝，小店不敢收。\n");
        set("material", "gold");
        set("wield_msg", "$N抖擞精神，大喝一声：起！举起$n。\n");
        set("unwield_msg", "$N将手中的$n放了下来。\n");
        set("weapon_prop/dodge", -60);
        set("weapon_prop/spear", -60);
        }
        init_spear(30);
        setup();
}


