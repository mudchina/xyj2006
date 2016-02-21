//Cracked by Roath
//longshen-yinggong.c
inherit FORCE;
int valid_enable(string usage) { return usage=="jinlin-jia"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return
notify_fail("龙神护体神功只能用学的。\n");
}

int effective_level() { return 20;}
string *absorb_msg = ({
        "$n双臂一震，龙神护体神功决堤似的澎湃而出。\n",
        "$n施展出龙神护体神功，$N身体被震的发麻。\n",
        "$n使出龙神护体神功，浑身硬如金石。\n",
        "$n施展出龙神护体神功，对抗$N的一击之力。\n",
});
string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
int bounce_ratio()
{
 return 5;
}
int learn_bonus()
{
 return -10;
}
int practice_bonus()
{
 return -5;
}
int black_white_ness()
{
 return 20;
}
string perform_action_file(string action)
{
        return CLASS_D("dragon") + "/longshen-yingong/" + action;
}
