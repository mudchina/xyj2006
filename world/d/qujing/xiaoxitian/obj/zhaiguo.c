// created by snowcat on 12/18/1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "桃斋果",
  "杏斋果",
  "梨斋果",
  "面斋果",
  "豆斋果",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"zhai guo", "guo"}));
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一只红里透紫的斋果。\n");
    set("unit", "只");
    set("value", 60);
    set("food_remaining", 3);
    set("food_supply", 120);
  }
//  set("no_sell",1);
}


