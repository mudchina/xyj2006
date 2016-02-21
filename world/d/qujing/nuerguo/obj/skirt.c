// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

string *names = ({
  "印花裙",
  "束腰筒裙",
  "水染彩裙",
  "宽身素长裙",
  "短袍裙",
});

void create()
{
  set_name(names[random(sizeof(names))], ({ "skirt", "cloth" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一条西梁女国的裙子。\n");
    set("unit", "条");
    set("material", "cloth");
    set("armor_prop/armor", 3);
    set("armor_prop/personality", 4);
    set("female_only", 1);
    set("value",200);
  }
  setup();
}

