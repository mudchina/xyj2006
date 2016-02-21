inherit EQUIP;

void create()
{
  set_name("细条竹篓", ({ "zhu lou","zhulou","lou","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是一只漂亮的细条竹篓。\n");
    set("value", 200);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N提起细条竹篓，轻巧地背在身上。\n");
  set("unequip_msg", "$N将细条竹篓从背后卸下来，抱在怀里。\n");
}

