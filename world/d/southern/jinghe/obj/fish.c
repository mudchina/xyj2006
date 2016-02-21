//Cracked by Roath
// ajax  06/13/99

inherit ITEM;
inherit F_FOOD;


string *names = ({
  "青鱼",
  "金色鲤鱼",
  "草鱼",
});

void create()
{
   set_name(names[random(sizeof(names))], ({"fish"}));
   set_weight(100);
   if( clonep() )
           set_default_object(__FILE__);
   else 
     {
     set("long","一条鲜鱼。\n");
     set("unit", "条");
     set("value", 80000);
     set("no_sell","掌柜的摇了摇头：这玩艺活蹦烂跳的，没法保存，不要。\n");
     set("food_remaining", 4);
     set("food_supply", 50);
     }
   setup();
}


