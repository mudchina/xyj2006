
inherit EQUIP;

void create()
{
  set_name("细编翠竹花篮", ({ "hua lan","hualan","lan","basket"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
	object a,b;
	seteuid(getuid());
	if(a=new("/d/obj/flower/juhua") )
		a->move(this_object());
	seteuid(getuid());
        if(b=new("/d/obj/flower/rose") ) 
                b->move(this_object()); 
    set_default_object(__FILE__);
}  else {
    set("unit", "只");
    set("long", "这是一只精美的套层绢底雕花缎边细编翠竹花篮。\n");
    set("value", 1000);
  }
  set("armor_prop/armor", 1);
  set("armor_type", "basket");
  set("wear_msg", "$N提起细编翠竹花蓝，轻巧地背在身上。\n");
  set("unequip_msg", "$N将细编翠竹花蓝从背后卸下来，抱在怀里。\n");
}

int is_container() { return 1; }
//int query_autoload() { return 1; }

