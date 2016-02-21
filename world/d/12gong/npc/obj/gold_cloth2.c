// by happ@YSZZ

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(HIY"ปฦฝ๐สฅาย"NOR, ({ "huangjin shengyi","shengyi","armor" }) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "ผþ");
     set("no_give",1);
     set("value",2000000);
     set("material", "steel");
     set("armor_prop/armor",150);
  }
   setup();
}
int query_autoload() { return 1; }
