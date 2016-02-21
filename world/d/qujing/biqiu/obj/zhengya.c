//Cracked by Roath
// by snowcat 11/22/1997
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("œ„÷≠’Ù—º", ({ "xiangzhi zhengya", "zhengya", "ya" }) );
  set_weight(180);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "“ª÷ª’Ùµ√œ„œ„µƒΩΩ÷≠’Ù—º°£\n");
    set("unit", "÷ª");
    set("value", 300);
    set("food_remaining", 4);
    set("food_supply", 45);
  }
}

