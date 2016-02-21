//Cracked by Roath

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("仙茶", ({"xian cha", "cha", "tea"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一个雕花玉茶壶。\n");
    set("unit", "个");
    set("value", 2000);
    set("max_liquid", 20);
    set("material", "jade");
  }
  
  set("liquid", ([
    "type": "water",
    "name": "灵山仙泉茶",
    "remaining": 20,
   ]) );
  set("no_get", "仙茶乃灵山之佛物，不能拿走！\n");
  setup();

}

