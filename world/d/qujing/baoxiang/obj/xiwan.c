// by snowcat oct 15 1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("锡碗", ({"xi wan", "xiwan", "wan"}));
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("long", "一只镶边锡碗．\n"),
    set("value", 800);
    set("max_liquid", 5);
    set("liquid", ([
	"type": "water",
	"name": "清水",
	"remaining": 5,
	"drunk_supply": 5,
    ]));
  }
  setup();
}

int is_container()
{
  return 1;
}
