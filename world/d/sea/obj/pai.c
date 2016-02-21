inherit ITEM;

void create()
{
  set_name("水晶腰牌", ({ "yao pai" }));
  set_weight(1000);
  set("long", "这是一个水晶制成的腰牌，上刻有“东海龙宫”四个字。
奇怪的是边锋上有些突槽，便如钥匙一般。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

