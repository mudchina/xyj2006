#include <armor.h>

inherit SHIELD;

string *names = ({
  "青萝藤盾",
  "紫萝藤盾",
  "樟木盾",
  "楠木盾",
});

string *ids = ({
  "qingluo dun",
  "ziluo dun",
  "zhangmu dun",
  "nanmu dun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "dun", "shield"}));
  set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 200);
   set("material", "wood");
   set("armor_prop/armor", 32);
   set("armor_prop/dodge", -2);
  }
  set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
  setup();
}
