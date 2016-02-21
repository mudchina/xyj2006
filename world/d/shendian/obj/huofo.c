inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("火佛", ({"huofo", "fo"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","一个看起来象火制的古佛。");
                set("base_unit", "个");
                set("base_weight", 0);
                set("no_sell","这么珍贵的东西这里可不敢收！" );
             set("no_give","这么珍贵的东西给别人不大好吧"); 
        }
        setup();
}
void init()
{
    add_action("do_jie", "lianzhi");
}

int do_jie()
{
     object me,ob, obj, obj1, obj2, obj3, obj4, pan;
     me = this_player();
     ob = this_object();
     obj = present("mufo", me);
     obj1 = present("jinfo", me);
     obj2 = present("bingfo", me);
     obj3 = present("shifo", me);
     if(!objectp(obj))
           return notify_fail("你手中没有木佛，先找到木佛再说吧。\n");
     if(!objectp(obj1)) 
           return notify_fail("你手中没有金佛，先找到金佛再说吧。\n"); 
     if(!objectp(obj2)) 
           return notify_fail("你手中没有冰佛，先找到冰佛再说吧。\n");
     if(!objectp(obj1)) 
           return notify_fail("你手中没有石佛，先找到石佛再说吧。\n");
  message_vision(HIY"\n只听铛的一声，$N手中的五尊佛像在一阵霞光中合为一体， 变成了一个凤凰涅磐！。\n"NOR, me);
     pan = new("/d/shendian/obj/niepan")->move(me, 1); 
     destruct(obj);
     destruct(obj1);
     destruct(obj2);
     destruct(obj3);
     destruct(ob);
     destruct(ob);
     return 1;
}

