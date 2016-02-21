// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit F_CLEAN_UP;
#include <obstacle.h>
int telling (object me, object who);
int telling2 (object who);
string name;
int killtime(object me);
int main(object me, string arg)
{
        object ob;
        if( !arg ) {
                ob = me;
                name = ob->short(1);
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
                if(!ob) ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
                name = ob->short(1);
        } else
           return 0;
        telling(me, ob);
        return 1;
}
int help()
{
        write(@TEXT
指令格式：score2 <某人>

显示某人其他资料。 
	比如：查看除魔任务

相关帮助：help wudang 等
TEXT
        );
        return 1;
}

int telling (object me, object who)
{
  write (name+"\n");
  write ("≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");
if(who->query("HellZhenPass")){
	write ("已经下过十八层地狱了。\n");
	write ("────────────────────────────────────\n");
}
   telling2(who);
if(who->query("death")){
	write ("上次死亡损失"+COMBAT_D->chinese_daoxing(who->query("death/combat_exp_loss"))+"道行。\n");
	write ("上次死亡损失"+who->query("death/skill_loss")+"级技能。\n");
	write ("────────────────────────────────────\n");
}
if(who->query("child")){
	write ("有"+who->query("child")+"个孩子。\n");
	write ("────────────────────────────────────\n");
}
  write ("一共吃了"+who->query("liwu/eat")+"个礼物。\n");
  write ("一共吃了"+who->query("rsg_eaten")+"个人参果。\n");
  write ("最近又吃了"+who->query("eat_biou")+"个碧藕。\n");
  write ("最近又吃了"+who->query("eat_jiaoli")+"个交梨。\n");
  write ("最近又吃了"+who->query("eat_huozao")+"个火枣。\n");
  write ("────────────────────────────────────\n");
  write ("一共降伏了"+who->query("killme/number")+"个妖。\n");
  write ("最近累计降伏了"+who->query("killme_number")+"个妖。\n");
	if(who->query_temp("ask_njiang")=="do"){
		write ("正准备放弃刚领的任务，但还没有征得同意。\n");
	}else{
	if(who->query_temp("killme_applied")=="do"){
		write ("现在已经领了任务，应该降妖除魔去了。\n");
		killtime(who);
	}else{
	if(who->query_temp("killme_applied")=="done"){
		write (" 刚杀了妖怪，正等着奖励呢。\n");
	}else{
	if(who->query_temp("ask_jiang")=="do"){
		write ("刚打听过五雷神将的消息，但还没得到答复。\n");
	}else{
	if(who->query_temp("ask_jiang")=="ok"){
		write ("已经打听到五雷神将的消息了，正准备去找。\n");
	}else{
		write ("现在没有领除魔任务。\n");
	}
	}
	}
	}
	}
  write ("≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");
}

int telling2 (object who)
{
  int size = sizeof(obstacles);
  string *names = keys(obstacles);
  string *strs = allocate (size);
  int nb = 0;
  int i;

  for (i = 0; i < size; i++)
  {
    strs[i] = "none";
  }

  for (i = 0; i < size; i++)
  {
    if (who->query("obstacle/"+names[i])!="done")
    {
      strs[nb] = obstacles[names[i]];
      nb++;
    }
  }

  if (nb == 0)
  {
	write ("还剩"+(3-who->query("obstacle/rebirth"))+"根救命毫毛。\n");
	write ("────────────────────────────────────\n");
  }
}
int killtime(object me)
{
	int sec,min,age,time1,time2;
	string out_str;
	object old=find_living(me->query("id")+" yao");
	time2=time();
	time1 = (int)me->query_temp("killme/time1");
	age = 1800 - (time2 - time1);
	if(age>0){
	sec = age % 60;age /= 60;
	min = age % 60;age /= 60;
	out_str = (min? chinese_number(min)+"分钟":"")
	+ (sec? chinese_number(sec)+"秒":"");
		if(old){
			write("必须在" + out_str + "之内除掉它。\n");
		}else{
			write("已经找不到你要除的妖魔了，还是重新领任务去吧。\n");
		}
	}else{
		write("任务已经超时了，还是重新领任务去吧。\n");
	}
	return 1;
}