//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
      set_name(YEL"檀木佛珠"NOR,({"fo zhu","zhu"}));
      set("long","一串上等檀木做成的佛珠。\n");
      if( clonep() )
                set_default_object(__FILE__);
        else {
      set("value",100);
      set("unit","串");
      set("weight",5000);
      set("armor_prop/armor",5);
      setup();
}
}
