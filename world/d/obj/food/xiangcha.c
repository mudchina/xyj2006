
//xiangcha.c
inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("éªÄ¾²èÖÑ", ({"cha zhong", "chazhong", "cha", "teapot", "tea"}));
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "Ò»Ö»éªÄ¾²èÖÑ¡£\n");
    set("unit", "Ö»");
    set("max_liquid", 2);
}
  
  set("liquid", ([
		  "type": "water",
		  "name": "ÔÆÎíÉ½Ïã²è",
		  "remaining": 2,
		  ]) );
  setup();
}

