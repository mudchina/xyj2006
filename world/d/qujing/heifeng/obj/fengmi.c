//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蜂蜜", ({"feng mi", "fengmi","mi"}));
   set_weight(40);
   if (clonep())
     set_default_object(__FILE__);
   else {
                set("long", "这是蜜蜂辛勤劳动的结果。\n");
                set("unit", "块");
     set("value", 100);
     set("food_remaining", 4);
     set("food_supply", 30);
   }
}
