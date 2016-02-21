//Cracked by Roath

inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("[36m´óº£Íë[m", ({"haiwan", "wan"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "Ò»¸ö¾«ÃÀµÄ´óÍë¡£\n");
     set("unit", "¸ö");
     set("value", 100);
     set("max_liquid", 30);
   }
   set("liquid", ([
     "type": "water",
     "name": "ºì²è",
     "remaining": 10,
     "drunk_supply": 10,
   ]));
}
