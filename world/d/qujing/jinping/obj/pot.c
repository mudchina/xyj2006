
inherit ITEM;

void create()
{
  set_name("油罐", ({"you guan", "guan", "pot"}));
  set_weight(5000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一个用于装酥合香油的大石罐。\n");
    set("unit", "个");
  }
}

