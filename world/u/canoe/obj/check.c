#include <ansi.h>
inherit ITEM;
int do_sign(string);
void init()
{
   add_action("do_sign","qianming");
}
void create()
{
        set_name(HIY"千两黄金支票"NOR, ({"check","jiangpin"}));
        set_weight(0);
        set("unit","张");
        set("long","这是wiz为鼓励大家提出宝贵意见的礼物(你可以qianming一下试试)");
    set("value",0);
        set("drug_type",",支票");
setup();
}
int do_sign(string arg)
{
        object me = this_player();
    if (!id(arg)) return notify_fail("你要在什么上签名？\n");
         me->add("balance",10000000);  
    message_vision(HIC"\n  $N从怀里掏出一管自用的毛笔,在支票收款人落款处大笔一挥,\n"
"只见几个龙飞凤舞的大字跃然纸上.\n\n"
  "  忽然一个尖嘴猴腮的家伙出现在$N面前,从$N手中接过支票,深深的鞠了一躬,说道:\n"
"支票已签收,"HIY"一千两黄金"+HIC"已转入你钱庄账户,感谢对本站的支持,望再接再厉!!\n\n"NOR,me);
            destruct(this_object());
return 1;
}

