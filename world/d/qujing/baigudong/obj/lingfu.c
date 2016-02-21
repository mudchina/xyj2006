// created by smile 12/24/1998

inherit ITEM;

void create()
{
  set_name("清瘴灵符", ({"lingfu", "fu"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "道");
    set("long", "一道刻了些奇怪的文字的符。\n");
  }
  set("is_monitored",1);
  setup();
}
