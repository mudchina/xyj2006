//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIM"奇怪的瓶子"NOR, ({"jar"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个奇怪的书，好象里面困住了什么，你可以试试打破(dapo)它。\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  add_action("do_dapo", "dapo");
}

int do_dapo(string arg)
{
  object me = this_player();
  object ob;

  if (arg!="jar")   return 0;
  ob = new("/d/shushan/npc/guiwang");
        ob->move(environment(me));
        message_vision(CYN"$N打破瓶子，忽然发现面前出现了一个妖精。\n",me);  
        write("妖精道：“是你救了我，我就是鬼王，为了报答你...”\n");
        write("鬼王道：“我...就...吃...了...你！！”\n"NOR);
        destruct(this_object());
        return 1;
}

