inherit EQUIP;

void create()
{
  set_name("烫花竹篮", ({ "zhu lan","zhulan","lan","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是一只漂亮的烫花竹篮。\n");
    set("value", 200);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N提起烫花竹篮，轻巧地背在身上。\n");
  set("unequip_msg", "$N将烫花竹篮从背后卸下来，抱在怀里。\n");
}

