//copy from bone by repoo

#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit ARMOR;

void create()
{
   set_name(HIY"龙神"+HIB"之翼"NOR, ({HIR"long yi"NOR,"yi"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一对龙神身上的翼。\n");
    set("unit", "对");
 set("no_sell", 1);
 set("no_drop", 1);
 set("no_put",1);
   set("no_give",1);

    set("material", "cloth");
                set("value", 0);
                 set("armor_prop/armor", 150);
                set("armor_prop/dodge", 100);
  }
  setup();
}
void init()
{
        check_owner();
}
