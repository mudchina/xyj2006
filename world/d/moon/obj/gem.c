//Cracked by Roath

#include <ansi.h>
inherit ITEM;

string *names = ({
HIW"钻石"NOR,
HIG"祖母绿"NOR,
HIR"红宝石"NOR,
HIB"蓝宝石"NOR,
HIG"猫儿眼"NOR,
HIW"水晶"NOR,
HIG"玛瑙"NOR,
HIW"珍珠"NOR,
HIG"翡翠"NOR,
HIW"珊瑚"NOR,
HIW"象牙"NOR,
HIC"玳瑁"NOR,
YEL"琥珀"NOR,
MAG"紫晶"NOR,
HIR"鸡血石"NOR,
HIW"和阗玉"NOR,
});

void create()
{
  set_name("各色宝石", ({"bao shi", "gem",}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("value", 200000);
  }
}

void init()
{
  if (query("name")=="各色宝石")
    set_name(names[random(sizeof(names))], ({"bao shi","gem"}));
//  ::init();
}
