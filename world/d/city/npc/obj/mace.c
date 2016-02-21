#include <weapon.h>

inherit MACE;


void create()
{
              set_name("精钢虎尾鞭", ({ "jinggang mace", "mace" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                   set("unit", "根");
                   set("long", "这是一根无敌虎尾鞭。\n");
                   set("value", 0);
                   set("no_sell", 1);
                   set("material", "iron");
set("wield_msg", "$N操起一根$n，威猛地摆了个架式。\n");
set("unwield_msg", "$N小心翼翼将$n别回腰间。\n");
                   set("no_sell",1);
                   set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
                   set("no_give","总管发的装备，可不能乱送人哟！\n");
                   set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
 
        }
         init_mace(65);
        setup();
}


