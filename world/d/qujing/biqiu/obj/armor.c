#include <armor.h>

inherit ARMOR;

string *names = ({
  "ÇàÁøÌÙ¼×",
  "³àÁøÌÙ¼×",
  "×ÏÁøÌÙ¼×",
  "ºÚÁøÌÙ¼×",
});

string *ids = ({
  "qingliu teng jia",
  "chiliu teng jia",
  "ziliu teng jia",
  "heiliu teng jia",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "teng jia", "jia", "armor"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼ş");
   set("value", 500);
   set("material", "wood");
   set("armor_prop/armor", 30);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
