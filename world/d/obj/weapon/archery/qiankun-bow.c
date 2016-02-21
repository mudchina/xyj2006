#include <weapon.h>

inherit BOW; 

void create()
{
        set_name("乾坤弓", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "乾坤弓乃是陈唐关总兵李靖的镇关之宝。后因李靖结交\n虬髯客被疑而调入京城，也被李靖带来了。\n");
                set("unit", "张");
		set("value", 30000);
                set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
                set("material", "steel");
        }

        init_bow(1);
        setup();

}

