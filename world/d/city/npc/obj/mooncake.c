inherit ITEM;
inherit F_FOOD;

void create()
{
        
	switch (random(8))
  {
	case 0:{
	set_name("五仁月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
	break;}
	case 1:{
	 set_name("豆沙月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
       break;}
	case 2: {
	set_name("双黄月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
       break;}
	case 3: {
	  set_name("金腿月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
       break;}
	case 4: {
	  set_name("莲蓉月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
	break;}
        case 5: {
          set_name("椰蓉月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
        break;}
        case 6: {
          set_name("枣泥月饼", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
        break;}
        case 7: {
          set_name("七星伴月", ({"moon cake", "mooncake", "yue bing", "yuebing"}));
        break;}

	}
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块精美的月饼，上面印着“中秋快乐”的图案。\n");
                set("food_remaining", 4);
                set("food_supply", 50);
		set("value", 1000);
		set("no_sell","拿去与大家分享不好吗？：）\n");
        }
}

