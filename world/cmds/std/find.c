// find.c
// cglaem...01/25/97.

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void fail(object me);
void find_result(object me, object env, string target);

mapping maps=([]);
void create() 
{ 
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}

int main(object me, string target)
{
    	object ob, env=environment(me);
        int mana_cost;

//        if (me->is_busy() || me->is_fighting() )
//	  return notify_fail("你现在正忙着呢。\n");

        if(env->query("no_fight") || env->query("no_magic") )
	  return notify_fail("安全区内不能用天眼通。\n");

        if( !target) return notify_fail("你想用天眼通查谁？\n");
	
	if((int)me->query("daoxing")<5000)
         	return notify_fail("你的道行不够，用不了天眼通。\n");

        if((int)me->query("sen") < 100||
	  (int)me->query("sen")*100/(int)me->query("max_sen")<50 )
  	return notify_fail("你现在头晕脑胀，恐怕连自己在哪里都不清楚！\n");
           if(time()-me->query_temp("find_end")<5)
        return notify_fail("天眼通不能用得这么频繁！\n");         

//	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
//	mana_cost=-100+(int)me->query_skill("spells")/10;
//      if(mana_cost > -50) mana_cost=-50;

        mana_cost=-60;
        me->set_temp("find_end",time());

        if((int)me->query("mana")+mana_cost <= 30 )  
	  return notify_fail("你的法力不够，用不了天眼通。\n");

        me->add("mana", mana_cost);
	
	message_vision(HIY
	"$N口中念了几句咒文，眼中突然精光一闪，大喝一声“千里眼何在！”\n"
	NOR,me);

	call_out("find_result",2+random(3),me,env,target);
	return 1;

}

void fail(object me)
{
	tell_object(me,"千里眼告诉你：奇怪，找不到这个人．．．\n");
	return;
}

void find_result(object me, object env, string target)
{
        object ob, where, bang;
string fail, msg, filename, filename1, answer, shortstr;
	int len;

        if(!me) return;
	if(environment(me)!=env) return;

	message_vision(HIY
	"只听嘿嘿几声奸笑，不知从哪里钻出来一个尖嘴猴腮的家伙，在$N耳边低声说了几句话。\n" NOR, me);
        
	ob = find_player(target);
	if( !ob ) ob = find_living(target);

	if (!ob || (ob->query("env/invisibility") && wizardp(ob) )) 
	  return fail(me);
	where = environment(ob);
	if (!where) return fail(me);

        if(present("jin gu bang", ob) ){
	  tell_object(me,
		  "千里眼告诉你：人是找到了，但是说不得，不能说．．．\n"+
		  "那家伙带着猴子给他的金箍棒。\n");
          return;
        }
	//added by weiqi, need better solution later...

	answer=MISC_D->find_place(where);
	if(!answer || sizeof(answer)<2) return fail(me);

	tell_object(me,"千里眼告诉你："+(string)ob->name()+
	  "("+(string)ob->query("id")+")"+
	  "在"+answer+"。\n");

shortstr=where->query("short");  
        //added by yesi
        if ( me->query("family/family_name") == "三界散仙" 
        && (int)me->query_skill("mysticism",1) >60
        && me->query("learned_points")>250000)
           tell_object(me,"具体位置好象就在"+shortstr+"\n");
         else tell_object(me,"\n"); 
        message_vision("$N“啊～～秋～～”一声打了个喷嚏，不由皱了皱眉。\n",
	  ob);
        msg="你急忙掐指算去，";
        if(ob->query("daoxing")>me->query("daoxing")/3)
	  msg+="似乎"+me->name()+"("+me->query("id")+")"+
	       "正在探听你的行踪。\n";
        else
	  msg+="心中却只是一片茫然。\n";
        tell_object(ob, msg);

	return;
}

int help(object me)
{
        write(@HELP
指令格式 : find <某人>

天眼通：用来发现别人所在地。
HELP
        );
        return 1;
}
