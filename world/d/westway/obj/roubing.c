// created by snowcat on 4/9/1997
// roubing.c

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ÑòÈâ±ı", ({"roubing", "yang", "bing"}));
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "Ò»¿é¿¾µÃºÜÏãµÄÑòÈâÈâ±ı¡£\n");
    set("unit", "¿é");
    set("value", 60);
    set("food_remaining", 3);
    set("food_supply", 120);
  }
}


