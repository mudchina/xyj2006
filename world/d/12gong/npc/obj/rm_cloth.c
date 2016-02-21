// by happ@YSZZ
#include <ansi.h>

#include <armor.h>

inherit CLOTH;

void create()
{
   set_name(HIY"射手圣衣"NOR, ({ "sheshou shengyi" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("material", "steel");
     set("armor_prop/armor",60);
     set("no_get","这件黄金圣衣不属于你!\n");

   }
   setup();
}
