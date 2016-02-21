// tian.c by single
//this perform have too large damage, aqing medifyed it
//and solved the nk problem
// aqing 2000.9.30
// 修改by canoe ,05-13-2001
// 对齐了描述,攻击力确实可怕,改小了
// 这个pfm很cool
#include <ansi.h>
inherit SSERVER;

string begin_msg(object me,object target,int i,string w_name);
int perform(object me,object target)
{

string *l_weapon = ({
	"dodge",
	"unarmed",
	"spear",
             "archery",
	"axe",
	"mace",
});
string *fail_msg = ({
	"但是$n却乱闯一通，误打误撞，竟然将$N辛苦布成的阵法破坏了．\n",
	"就在$N的拳头要击中$n的瞬间，$n猛然大叫了一声，$N一受惊，一下收了回来．\n",
	"哪知$n早已料到这招，凭着一口真气，一越而上，愣是从万剑之中逃了出去\n",
	"$n竟然看出身旁的火焰是幻影，丝毫不受$N幻影攻击的影响．\n",
	"想不到$n反手在自己脸上一掌，愣是靠痛楚稳定了自己心神．\n",
	"$n以柔克刚，以阴克阳，愣是让$N的雷霆一击之力化为乌有．\n",
});
string *succ_msg = ({
       "$n只觉得四周有无形之力向自己压来，身形顿时慢了下来．\n",
       "$n向后急退，最后退无可退，硬生生的接了$N一拳，只觉得五脏六腑都移了位．\n",
       "$n一时慌了神，只听”嗤嗤”几声，原来已经被利剑划的身上伤痕累累．\n",
       "$n手足无措，被烈火灼伤了胸部，$n心理精神上受到了很大的打击．\n",
       "$n抵受不了攻击，最后只好运功抵抗，元气大损．\n",
       "$n来不及细想，凭感觉躲闪，但来不及了，肩膀愣是被砸中，顿时行动受损．\n",
});
	object weapon,temp;
	int ap,dp,flag,i,damage;
	string *w_temp,w_name;
	string msg;

string unarmed,dodge,axe,mace,spear,archery;
	if(!target)      target = offensive_target(me);
	if(!wizardp(me)&&(string)me->query("family/family_name") != "将军府" )
		return notify_fail("你不是将军府门下，如何能领悟得了此招「浑然天成」？\n");
	
	if(!target
	|| !target->is_character()
	|| target->is_corpse()
	|| target == me )
		return notify_fail("你准备对谁用这招「浑然天成」？\n");
	
	if(!me->is_fighting(target))
		return notify_fail("这一招「浑然天成」必须在战斗中才能使用．\n");
	if( me->query("sen") < 500 )
		return notify_fail("你的精神不足，使用这招「浑然天成」恐怕有危险．\n");
	if( me->query("kee") < 500 )
	 return notify_fail("你的气血不足，使用这招「浑然天成」恐怕有危险。\n");
		 
	if( me->query("max_force") < 600 )
		return notify_fail("你的内力根本不足以使用这招「浑然天成」．\n");
	if( me->query("force") < 1500 )
		return notify_fail("你的当前内力太少了，会有危险的．\n");
	if( me->query("mana") < 1800 )
		return notify_fail("你的当前法力太低，还无法熟练运用这招。\n");
	if( me->query_skill("lengquan-force",1) < 100 )
		return notify_fail("你的冷泉神功级别太低，还用不了这招．\n");
	if( me->query_skill("baguazhou",1) < 120 )
		return notify_fail("你的八卦咒级别太低，出不了此招．\n");
	if( me->query_skill("spear",1) < 100 )
		return notify_fail("你的基本枪法别太低，使用这招恐怕有危险．\n");
	if( me->query_skill("mace",1) < 100 )
		return notify_fail("你的基本锏法级别太低，还用不了这招．\n");
	if( me->query_skill("axe",1) < 100 )
		return notify_fail("你的基本斧法级别太低，还用不了这招．\n");
		
	weapon = me->query_temp("weapon");
	unarmed = me->query_skill_mapped("unarmed");
	spear = me->query_skill_mapped("spear");
	axe = me->query_skill_mapped("axe");
	mace = me->query_skill_mapped("mace");
	archery = me->query_skill_mapped("archery");
	dodge = me->query_skill_mapped("dodge");
	if( unarmed == "changquan" )  flag = 1;
	if( spear == "bawang-qiang" )  flag += 1;
	if( axe == "sanban-axe" )    flag += 1;
  if( mace == "jinglei-mace" )  flag += 1;
	if( archery == "xuanyuan-archery" )   flag += 1;

	if( flag < 3 )
		return notify_fail("你本门武功太少，无法使用这招「浑然天成」．\n");
	if( me->query_skill_mapped("force") != "lengquan-force" )
		return notify_fail("没有冷泉神功作基础，如何引发这招「浑然天成」？\n");
	if( me->query_skill_mapped("spells") != "baguazhou" )
		return notify_fail("没有八卦咒引导，如何将此招「浑然天成」发挥到最大限度？\n");
	msg = HIR"\n$N暗念八卦咒，运起澎湃护体真气，脚下是越转越快，出手是越来越狠．．．．\n"NOR;
	message_vision(msg,me);
	me->start_busy(2+random(3));
	me->add("force",-400);
	me->add("mana",-300);
	for(i=0;i<sizeof(l_weapon);i++)
	{
	seteuid(getuid());
	if( !me->query_skill_mapped(l_weapon[i]) ||(int)me->query_skill(me->query_skill_mapped(l_weapon[i]),1) < 100 )
		continue;
	if(l_weapon[i]=="unarmed")
	{
		w_name = " ";
		msg = begin_msg(me,target,i,w_name);
	}
	else
	if(l_weapon[i]=="dodge")
	{
		w_name = " ";
		msg = begin_msg(me,target,i,w_name);
	}
	else
	{
	if(l_weapon[i]=="spear") temp=new("/d/obj/weapon/spear/biyuqiang"); 
        if(l_weapon[i]=="axe") temp=new("/d/obj/weapon/axe/huafu"); 
           if(l_weapon[i]=="mace") temp=new("/d/obj/weapon/mace/goldjian"); 
if(l_weapon[i]=="archery") temp=new("/d/obj/weapon/archery/mugong"); 
        temp->move(me);
	w_name = temp->query("name");
	msg = begin_msg(me,target,i,w_name);
	if ( i >= 6 || msg== "shake" )
         {      weapon->delete("equipped");
                temp->set("equipped","wielded");
                me->set_temp("weapon",temp);
                me->reset_action();
		message_vision(msg,me,target);
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
                temp->delete("equipped");
                weapon->set("equipped","wielded");
                me->set_temp("weapon",weapon);
                destruct(temp);
                me->reset_action();
		continue;
	}
	}
        message_vision(msg,me,target);
	if(temp)
	destruct(temp);

	ap = me->query_skill(l_weapon[i]) + me->query_skill("force") + me->query_skill("spells") + me->query("combat_exp")/20000 + me->query_skill("literate");
	dp = target->query_skill("parry") + target->query_skill("force") + target->query_skill("dodge") + target->query("combat_exp")/20000;
	if( random(ap) < random(dp) && userp(target) )
	{	message_vision(fail_msg[i],me,target);
	}
	else
	if( random(ap) < random(dp*2/3) && !userp(target) )
	{       message_vision(fail_msg[i],me,target);
	}
	else
	{
		if( l_weapon[i] == "dodge" )
		{me->add_temp("apply/dodge",(int)me->query_skill("dodge",1)/2);
		 me->add_temp("apply/attack",(int)me->query_skill("dodge",1)/2);
		 me->add_temp("apply/armor",(int)me->query_skill("dodge",1)/2);
		 me->add_temp("apply/strength",(int)me->query_skill("dodge",1)/2);
		target->add_temp("apply/dodge",-(int)me->query_skill("dodge",1)/2);
			me->set_temp("apply/dodge_add",1);
			message_vision(succ_msg[i],me,target);
			me->reset_action();
			continue;
		}		
		if( l_weapon[i] == "unarmed" )
		{	
target->receive_damage("kee",me->query_skill("unarmed")/(1+random(2)));
			target->receive_wound("kee",me->query_skill("unarmed")/(2+random(2)));
			target->set_temp("last_damage_from",me);
			if(target->query("force")>me->query_skill("unarmed")*2)
			target->add("force",-me->query_skill("unarmed")*2);
			else target->set("force",1);
			if(me->query("force")<3*me->query("max_force"))
			me->add("force",me->query_skill("unarmed"));
			message_vision(succ_msg[i],me,target);
			COMBAT_D->report_status(target);
			continue;
		}
		weapon->delete("equipped");
        if(l_weapon[i]=="spear") temp=new("/d/obj/weapon/spear/biyuqiang"); 
        if(l_weapon[i]=="axe") temp=new("/d/obj/weapon/axe/huafu"); 
        if(l_weapon[i]=="mace") temp=new("/d/obj/weapon/mace/goldjian"); 
        if(l_weapon[i]=="archery") temp=new("/d/obj/weapon/archery/mugong"); 
 		temp->move(me);
		temp->set("equipped","wielded");
 		me->set_temp("weapon",temp);
		me->reset_action();
		message_vision(succ_msg[i],me,target,me->query_temp("weapon"));

		damage = me->query_skill(l_weapon[i]) + random(me->query_skill(l_weapon[i])) + me->query("force_factor");
		if(random(5)==1)
		{damage += me->query_str();
message_vision(CYN"\n轰!!轰!!轰!!$N被$n砸得天旋地转,站立不稳,差点去见崔叔叔!!\n"NOR,target,me->query_temp("weapon")); }
             target->receive_damage("kee",damage/(1+random(2)));
                  target->receive_wound("kee",damage/(2+random(3)));
		target->receive_damage("sen",damage/4);
		target->receive_wound("sen",damage/8);
		target->set_temp("last_damage_from",me);
	        COMBAT_D->report_status(target);
        	temp->delete("equipped");
        	weapon->set("equipped","wielded");
        	me->set_temp("weapon",weapon);
        	destruct(temp);
        	me->reset_action();

	}
	}	
	if(me->query_temp("apply/dodge_add"))
	{
		me->add_temp("apply/dodge", -(int)me->query_skill("dodge",1)/2);
		me->add_temp("apply/attack",-(int)me->query_skill("dodge",1)/2);
		me->add_temp("apply/armor",-(int)me->query_skill("dodge",1)/2);
		me->add_temp("apply/strength",-(int)me->query_skill("dodge",1)/2);
		target->add_temp("apply/dodge",(int)me->query_skill("dodge",1)/2);
		me->delete_temp("apply/dodge_add");
	}		 
       if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	return 1;
}
string begin_msg(object me,object target,int i,string w_name)
{
 	if(i==0)	
           return ( HIM"\n【布阵诀．．．．．．．．．．奇门八卦】"NOR+"\n$N口中念道：乾生天，坤生地，八卦无形，周转复始．绕着$n越转越快，\n同时在地上不知布了一些什么玄机.地上起了些奇异的变化!!!\n");
	if(i==1)
return ( HIC"\n【勇气诀．．．．．．．．．．神勇无敌】"NOR+"\n$N叫道：“着”同时，双手交换出拳，一拳比一拳快，当真是\n有万夫莫敌之气势，将长拳发挥得淋漓尽致，直朝着$n而去．\n");
	if(i==2)
return ( HIY"\n【枪字诀．．．．．．．．．．枪行天下】"NOR+"\n$N将手中"+w_name+"往空中一抛，手指$n，叫道：去也．只见"+w_name+"一分二，\n二分四，越分越多，从四面八方直朝着$n射去,$n顿时惊慌失措．\n");
	if(i==3)
        return (HIR"\n【刀字诀．．．．．．．．．．火浴重生】"NOR+"\n$N暗暗将咒语附着在"+w_name+"上，向四周虚劈了几下，所到之处，卷起层层烈焰，\n象是要把$n吞噬一样,$n的脸被火焰映得通红．\n");
	if(i==4)
return (HIB"\n【斧字诀．．．．．．．．．．开天辟地】"NOR+"\n $N抛起"+w_name+",合手念起八卦咒，$n只觉心底烦躁不已。\n");
	if(i==5)
       return (HIW"\n【锏字诀．．．．．．．．．．惊天动地】"NOR+"\n$N双手举起"+w_name+"，以雷霆万钧之势向$n砸去，此招看似大拙，实则大巧．\n"+w_name+"在空中一个转折,向$n飞来,$n脸上写满恐怖!\n");
	if(i==6)
	return (HIG"\n【鞭字诀．．．．．．．．．．忧心忡忡】"NOR);
else return ("shake");
}
