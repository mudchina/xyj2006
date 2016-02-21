// story:caishen 财神

#include <ansi.h>

int give_gift(string money, int amount, string name);

private mixed *story = ({
        "天兵甲：喂！你看，那个人又坐在那里发呆了。连续几天都这样，延误我们哥俩关门收工的时间嘛？",
        "天兵乙：是啊，整天傻坐在那里自言自语，说什么结发的妻子在天那边，还不停地流泪。看看他
		那副德性，鬼鬼祟祟丢人现眼，披头散发人模狗样。",
        "天兵甲：他的妻子是谁啊？",
        "天兵乙：从他的口气听好象是上次打伤我们哥俩逃下凡间的那个紫霞仙子。",
        "天兵甲：哗！紫霞仙子！不会吧？紫霞仙子那样美丽纯真，像我这么有理智的人怎么可能相信紫霞
		仙子是他的妻子这种无稽的事情呢？",
//        (: give_gift, "coin", 10 + random(10), "铜板" :),
        "天兵乙：嘘。小声点！他刚调到这里来做事的，好象被如来佛主封了个什么斗战胜佛，最好少惹他。",
//        (: give_gift, "silver", 10 + random(10), "白银" :),
        "天兵甲：我KAO！斗战胜佛，很有名吗？干嘛给他面子！",
        (: give_gift, "gold", 1 + random(10), "黄金" :),
        "天兵乙：不是啊，听说他以前叫做齐天大圣，好象很能打的。",
        (: give_gift, "thousand-cash", 1 + random(3), "银票" :),
        "天兵甲：齐天大圣……是他！呃……好兄弟，你在这里顶着，我肚子有点不舒服走一步先。",
		"天兵乙：大哥，你的腿在抖耶。哇！你裤子怎么突然湿了，难道你是怕那个人……我也要走！",
});

void create()
 
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift(string money, int amount, string name)
{
        STORY_D->give_gift("/obj/money/" + money, amount,
                           HIM "\n“啪”的一声一些" + name + "掉到你面前。\n\n" NOR);
        return 1;
}

