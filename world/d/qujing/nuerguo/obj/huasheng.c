// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "油炸花生",
  "炒花生",
  "煮花生",
  "五香花生",
  "烘花生",
  "卤花生",
  "盐水花生",
  "细糖花生",
});

void create()
{
  set_name("各式花生", 
          ({"hua sheng", "huasheng", "sheng", "peanut"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包花生。\n");
    set("unit", "包");
    set("value", 90);
    set("food_remaining", 10);
    set("food_supply", 9);
  }
//  set("no_sell",1);
}

void init()
{
  if (query("name")=="各式花生")
    set_name(names[random(sizeof(names))], 
            ({"hua sheng", "huasheng", "sheng", "peanut"}));
  ::init();
}
