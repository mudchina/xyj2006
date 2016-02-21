//jueshi.c by yushu 2000.11
#include <weapon.h>
#include <ansi.h> 
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIC"小竹剑"NOR, ({"jiansheng xinwu","xinwu","sword","jian"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "把");
              set("long", "一把看似很普通的小竹剑,也不知道有什么用．\n");
              set("no_sell", 1); 
         //     set("no_give", 1);
              set("no_drop", 1);
              set("no_put", 1);
              set("value", 1); 
              set("replace_file", "/d/obj/weapon/sword/qinghong");
              set("material", "gold");
              set("wield_msg", "$N「唰」地一声抽出一把$n握在手中．\n");
              set("unwield_msg", "$N将手中的$n插入腰间．\n");
              set("weapon_prop/int", 2);

        }
        init_sword(150); 
   //     set("is_monitored",1);
        setup();
}