// skull.c
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("铁骷髅",({"ku lou", "skull", "kulou"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long","
\t一个黑黝黝的铁骷髅。在手中掂掂，还满沉的。你不由想道，这么小的一块铁，
能崩断犁头？是谁这么有闲功夫，造这么难看的一个骷髅出来？仔细检查一番，你发现
骷髅头盖骨有些松动，不知有什么古怪。\n");
                set("unit","个");
                set("value",5000);
                set("material","iron");
                set("wield_msg","$N抓住$n的鼻子，虽觉得很不顺手，但也还威风。\n"
);
                set("unwield_msg","$N把$n放回行囊中，甩了甩酸痛的手。\n");
        }
        init_hammer(5);
        setup();
}
void init()
{
        add_action("do_pull", "pull");
}
int do_pull(string arg){
        object ob, me;
        me=this_player();
 
        if (!arg || (arg != "scalp"))
                return notify_fail("你要拉什么？\n");
             else {
                ob=new(__DIR__"lingpai");
                ob->move(me);
                message_vision("$N用力一拉铁骷髅的头盖骨，整个铁骷髅碎成数片，掉在地上。\n", me);
	    message_vision("$N发现碎片中有一块令牌，弯腰把它拣了起来。\n", me);
	    destruct(this_object());
                return 1;
                }
}
