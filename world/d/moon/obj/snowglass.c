inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("Ñ©Òû±­", ({ "snowglass", "glass" }) );
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "±­Ìå±ÌÂÌÍ¨Í¸£¬Ááçç¿É°®£®\n");
    set("unit", "¸ö");
    set("value", 120);
    set("max_liquid", 100); 
    set("liquid_supply", 80);
  }

  set("liquid", ([
    "type": "water",
    "name": "±ÌéØ²è",
    "remaining": 90,
  ]) );
  setup();
}

