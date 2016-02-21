#include <weapon.h>

inherit FORK;

void create()
{
      set_name("九股叉", ({"jiu gu cha", "fork", "cha"}));
      set_weight(8000);

      if( clonep() )
        set_default_object(__FILE__);
      else 
        {
        set("unit", "柄");
        set("long", "一柄长长的九股托天叉，上刻：＂九股托天叉，重三千六百斤，东海龙宫打制＂。\n");
        set("value", 100000);
        set("no_give","这种宝贝怎能随便给人？\n");
        set("no_sell","掌柜的摇摇头说：这可是龙宫的宝贝，小店不敢收。\n");
        set("material", "gold");
        set("wield_msg", "$N提一口气将几千斤的$n举了起来。\n");
        set("unwield_msg", "$N将手中的$n放了下来。\n");
        set("weapon_prop/dodge", -20);
        set("weapon_prop/fork", -20);
        }
        init_fork(30);
        setup();
}


