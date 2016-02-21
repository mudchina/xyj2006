//Cracked by Roath
// 凤凰琴  


#include <weapon.h>

inherit "/d/obj/weapon/sword/anqi_container.c";

void create()
{
   set_name("凤凰琴", ({"fenghuang qin","qin","sword"}));
   set_weight(4000);
   if( clonep() ) 
          set_default_object(__FILE__);
   else 
     {
      set("long", "一张颜色暗旧的古琴，刻着两只飞舞的凤凰，看上去少说也是上百年的宝贝了。\n");
      set("orilong", "一张颜色暗旧的古琴，刻着两只飞舞的凤凰，看上去少说也是上百年的宝贝了。\n");
      set("unit", "张");
      set("value", 20000);
      set("material", "leather");
      set("wield_msg", "$N从背后摘下一张$n，捧在手中。\n");
      set("unwield_msg", "$N收起手中的$n，小心翼翼的背回背后。\n");
      set("anqi/allow", 1);
      set("anqi/max", 40);
      set("anqi/now", 0);
      set("music/type", "qin");
     }
     init_sword(65);
     setup();
}

