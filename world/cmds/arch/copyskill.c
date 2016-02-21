#include <ansi.h>//继承颜色

inherit F_CLEAN_UP;

private int copy_skill(object me, object ob);//定义一个私有函数
int help();//定义HELP函数

int main(object me, string arg)
{
object ob;

if (! arg)//没有参数时就调用HELP函数
{
help();
return 1;
}

if (! objectp(ob = present(arg, environment(me))))//判断对象是否在身旁
return notify_fail("你眼前没有这个人。\n");

if (! wizardp(me))//判断是否是巫师
return notify_fail("只有巫师才可以复制别人的武功。\n");

copy_skill(me, ob);//开始调用函数COPY武功和状态
message_vision(HIM "$N口中念念有词，只见一道红光笼罩了$N和$n。\n" NOR,
me, ob);//显示出状态
return 1;
}

private int copy_skill(object me, object ob)
{
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
int i, temp;
string you_mp= ob->query("family/family_name");

me->set("family/family_name",you_mp);
if (mapp(skill_status = me->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = me->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
me->delete_skill(sname[i]);//删除自己所有功夫
}

if (mapp(skill_status = ob->query_skills()))//判断对象是否有功夫，如有将用这个函数复制全部功夫
{
skill_status = ob->query_skills();
sname = keys(skill_status);//传回所有对象功夫阵列

for (i = 0; i < sizeof(skill_status); i++)
me->set_skill(sname[i], skill_status[sname[i]]);//为自己复制所有功夫
}

if (mapp(map_status = me->query_skill_map()))//判断自己是否有已装配的基本功夫
{
mname = keys(map_status);

temp = sizeof(map_status);
for (i = 0; i < temp; i++)
me->map_skill(mname[i]);
}

if (mapp(map_status = ob->query_skill_map()))//判断对象所装配的基本功夫，如有将用这个函数复制
{
mname = keys(map_status);

for(i = 0; i < sizeof(map_status); i++)
me->map_skill(mname[i], map_status[mname[i]]);
}

if (mapp(prepare_status = me->query_skill_prepare()))//判断自己是否有已装配的特殊功夫
{
pname = keys(prepare_status);

temp = sizeof(prepare_status);
for(i = 0; i < temp; i++)
me->prepare_skill(pname[i]);
}

if (mapp(prepare_status = ob->query_skill_prepare()))//判断对象所装配的特殊功夫，如有将用这个函数复制
{
pname = keys(prepare_status);

for(i = 0; i < sizeof(prepare_status); i++)
me->prepare_skill(pname[i], prepare_status[pname[i]]);
}

hp_status = ob->query_entire_dbase();//得到对象现有状态
my = me->query_entire_dbase();//得到自己现有状态

my["str"] = hp_status["str"];//开始复制状态
my["int"] = hp_status["int"];
my["con"] = hp_status["con"];
my["dex"] = hp_status["dex"];

my["max_kee"] = hp_status["max_kee"];
my["eff_kee"] = hp_status["eff_kee"];
my["kee"] = hp_status["kee"];
my["max_sen"] = hp_status["max_sen"];
my["eff_sen"] = hp_status["eff_sen"];
my["sen"] = hp_status["sen"];
my["max_force"] = hp_status["max_force"];
my["force"] = hp_status["force"];
my["max_mana"] = hp_status["max_mana"];
my["combat_exp"] = hp_status["combat_exp"];
my["daoxing"] = hp_status["daoxing"];//结束复制状态

me->reset_action();//更新身体
return 1;
}

int help()//帮助函数
{
write( @TEXT
指令格式：copyskill 对象

这个指令让你复制对象的战斗经验和所有的武功技能。
TEXT
);
return 1 ;
}


