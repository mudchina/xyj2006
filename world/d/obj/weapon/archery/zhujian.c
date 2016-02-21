// zhujian.c Öñ¼ı

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("Öñ¼ı", ({ "zhu jian", "arrow", "jian" }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",
"Öñ×ÓÏ÷³ÉµÄ¼ı£¬¼ıÍ·Ï÷¼â£¬¼ıÎ²ºúÂÒ²åÁËĞ©ÓğÃ«¡£\n");
    set("unit", "ºø");
    set("base_unit", "Ö¦");
    set("base_weight", 20);
    set("base_value", 10);
  }
  set_amount(10);
  set("value", 100);
  init_archery(10);
  setup();
}

