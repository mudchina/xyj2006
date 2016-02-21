//Cracked by Roath
// jinlin-jia.c
inherit SKILL;
#include <ansi.h>
string *absorb_msg = ({
 "$n淡淡一笑，不慌不忙的运起金鳞甲。\n",
        "$n闭目凝神，气走全身，护体硬功达到巅峰状态。\n",
        "$n双臂一圈，身行暴长，运起金鳞甲迎向$N！\n",
});
string query_absorb_msg()
{
 return absorb_msg[random(sizeof(absorb_msg))];
}
int valid_learn(object me)
{
  if(me->query("class")!="dragon")
    return notify_fail("你不是龙族，学不了这门武功！\n");
  return 1;
}
