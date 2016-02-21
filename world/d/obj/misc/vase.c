#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("紫云翡翠花瓶", ({ "hua ping","huaping","ping","vase"}) );
  set_weight(500);
  set_max_encumbrance(8000);
  set_max_items(12);
  if( clonep() ){
    object a,b;
    seteuid(getuid());
    if(a=new("/d/obj/flower/rose") )
      a->move(this_object());
    seteuid(getuid());
    if(b=new("/d/obj/flower/juhua") ) 
       b->move(this_object()); 
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是一只绘着紫云的珍贵翡翠花瓶。\n");
    set("value", 2000);
  }
  set("wield_msg", "$N捧起紫云翡翠花瓶，小心地抱在胸口。\n");
  set("unwield_msg", "$N将紫云翡翠花瓶轻轻地放下。\n");
  init_hammer(1);
}

int is_container() { return 1; }
//int query_autoload() { return 1; }

