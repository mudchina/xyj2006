inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N使一招"+BLINK""+HIW"「子牙此际落凡尘」"NOR+"，手中$w化为一道乌光砸向$n的$l",
                "dodge":                -5,
                "parry":                -10,
                "damage":               10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N几个急转，使出"+BLINK""+HIG"「白首牢骚类野人」"NOR+"，一声大喝中冲天而起，砸向$n的$l",
                "dodge":                -35,
                "parry":                -5,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N运气发劲，一式"+BLINK""+HIC"「几度束身成老拙」"NOR+"舞出无数幻影, $n只觉得漫天乌光袭来，不知该如何闪躲",
                "dodge":                -10,
                "parry":                -15,
                "damage":               15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N手中$w横腰一扫，一招"+BLINK""+HIY"「叁番涉世反相嗔」"NOR+"一片鞭影扫向$n。 $n躲避不及，挨了这一下，喉头一甜。忍不住吐出一口鲜血",
                "dodge":                -30,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N手中$w一抖，只见漫天黑影。遮天蔽日。\n这一招"+BLINK""+HIB"「溪未入飞熊梦」 "NOR+"只看得$n眼花缭乱，哪里还能招架",
                "dodge":                -20,
                "parry":                -20,
                "damage":               15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$n只觉得眼前一花，$N已悄然间闪至$n身后，手中$w直指$n的后心， 正是一式"+BLINK""+HIR"「渭水安知有瑞麟」"NOR+"",  
                "dodge":                -35,
                "parry":                -5,
                "damage":               20, 
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N不闪不避，一式"+BLINK""+HIG"「会际风云开帝业」"NOR+"，气定神闲， 蓄势待发，掌中$w直指$n破绽所在",
                "dodge":                -5,
                "parry":                -10,
                "damage":               10, 
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N哈哈一声长笑，手中$w一招"+BLINK""+HIM"「享年八百庆长春」"NOR+"砸在$n后背上，$n只觉眼前一黑。差点晕了过去",
                "dodge":                -5,
                "parry":                -10,
                "damage":               10, 
                "damage_type":  "刺伤"
        ]),
});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练打神鞭法。\n");
        if( (string)me->query_skill_mapped("force")!= "xuanzong-force")
                return notify_fail("打神鞭法必须配合玄宗心法才能练。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "mace" )
                return notify_fail("你必须先找一根鞭子才能练。\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="mace" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习打神鞭法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍打神鞭法。\n");
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("kunlun") + "/dashen-bian/" + func;
}
