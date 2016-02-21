// jiudai.c  酒袋

inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name("行军丹", ({"dan"}));
set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
  set("long", "行军，长途征战之必备良药。\n");
set("unit", "颗");
 set("value", 10000);
	}
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
 me->set("eff_sen", (int)me->query("max_sen"));
me->set("eff_kee", (int)me->query("max_kee"));
me->set("mana", (int)me->query("max_mana")*2);
me->set("force", (int)me->query("max_force")*2);
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
message_vision("$N吃下了一粒行军丹！\n", me);
  destruct(this_object());
  return 1;
}
