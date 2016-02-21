// actionavailable.c

#include <ansi.h>
#include <weapon.h>
#include <login.h>
inherit F_CLEAN_UP;

int room_path(object, object);
int user_path(object, object);

int main(object me, string arg)
{
	object ob, *inv;
	string win,*ids;

        if (sscanf(arg, "%s,%s", arg, win) != 2) 
                return 0;
                
	switch (win)
	{
		case "0" :
			ob=present(arg,environment(me));
			if(!objectp(ob)) {
				inv=all_inventory(environment(me));
				for(int i = 0; i<sizeof(inv); i++) {
					if(inv[i]==me) continue;
					if(ids=inv[i]->query_temp("apply/id"))
					for(int j=0;j<sizeof(ids);j++) {
						if(ids[j]==arg)
						ob=inv[i];
					}
				}
			}
			room_path(me,ob);
			break;
		case "1" :
			ob=present(arg,me);
			user_path(me,ob);
			break;
	}
	return 1;
}

int room_path(object me, object ob)
{
	mapping skills,meskills;
	object *inv;
	string *str,id,*ids,name,tmp;
	int i,my_skill;

	if(!objectp(ob)) return 1;
	
	if(stringp(tmp=ob->query_menu(me,0)))//如果对象能解释菜单，则直接返回菜单
	{
		write(tmp);
		return 1;
	}
	

	if(!ob->query("apply/id")) id=ob->query("id");
	else {
		ids=ob->query_temp("apply/id");
		id=ids[sizeof(ids)-1];
	}

//	if(ob->query_temp("apply/name")) name=ob->query_temp("apply/name");
	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem 观察$U;look "+id);
	if(living(ob))
	{
		if(interactive(ob))
		{
			tmp+=TMI("mitem 告诉$U...;tell "+id+" ...")+TMI("mitem 对$U耳语...;whisper "+id+" ...");
			if(id==me->query_temp("reply"))
				write(TMI("mitem 回答$U...;reply ..."));
		}

		tmp+=(me->query_leader()==ob)?TMI("mitem 停止跟随$U;follow none"):TMI("mitem 跟随$U;follow "+id);
		if(!environment(me)->query("no_fight"))
		{
			tmp+=TMI("mitem 与$U切磋;fight "+id);
			if ((int)ob->query("age") > 17 || !interactive(ob))
				tmp+=TMI("mitem 攻击$U;hit "+id)+TMI("mitem 杀死$U;kill "+id)+TMI("mitem 偷袭$U;touxi "+id)+TMI("mitem 偷$U的...;steal ... from "+id);
		}
		if(ob->query("inquiry")) {
			str=keys(ob->query("inquiry"));
			for(i=0; i<sizeof(str); i++)
				tmp+=TMI("mitem 向$U打听关于"+str[i]+"的信息;ask "+id+" about "+str[i]+"");
		}
		tmp+=TMI("mitem 给$U...东西;give ... to "+id );
		if(me->query("family/family_name") == "丐帮" ) {
			if ( me->query_skill("checking",1) >= 10 )
				tmp+=TMI("mitem 打探...的技能;check ...");
			if(ob->query("family/family_name") != "丐帮" )
				tmp+=TMI("mitem 乞讨$U的...;beg ... from "+id);
		}
		if(ob->query("vendor_goods")) {
			tmp+=TMI("mitem 查询$U出售的东西;list");
			tmp+=TMI("mitem 向$U买...;buy ...");
		}
		if(ob->query("dealer")=="pawn") {
			if(!ob->query("vendor_goods")) {
				tmp+=TMI("mitem 查询$U出售的东西;list");
				tmp+=TMI("mitem 向$U买...;buy ...");
			}
			tmp+=TMI("mitem 估价...;value ...");
			tmp+=TMI("mitem 卖...给$U;sell ...");
			tmp+=TMI("mitem 典当...给$U;pawn ...");
			if(me->query("pawns"))
				tmp+=TMI("mitem 赎回物品...;redeem ...");
		}
		if(ob->query("dealer")=="bank") {
			tmp+=TMI("mitem 兑换货币;convert ...");
			tmp+=TMI("mitem 存钱;deposit ...");
			if(me->query("money")) {
				tmp+=TMI("mitem 查询存款;check");
				tmp+=TMI("mitem 取钱;withdraw ...");
			}
		}
		if(me->query("family/master_name")!=ob->name(1)) {
			if(ob->is_master())
				tmp+=TMI("mitem 拜$U为师;bai "+id);
		} else {
			tmp+=TMI("mitem 向师父$U磕头;bai "+id);
			tmp+=TMI("mitem 查询师父$U技能;skills "+id);
			if(ob->query_skills() && me->query("jing")>=1
				&& (int)me->query("potential")>(int)me->query("learned_points")) {
				skills=ob->query_skills();
				str=keys(skills);
				for(i=0; i<sizeof(str); i++) {
					if(me->query_skills()) {
						meskills=me->query_skills();
						my_skill = me->query_skill(str[i], 1);
						if( (string)SKILL_D(str[i])->type()=="martial"
							&& my_skill*my_skill*my_skill/10>(int)me->query("combat_exp") )
							continue;
						if(skills[str[i]]>my_skill && str[i]!="idle")
							tmp+=TMI("mitem 学习"+to_chinese(str[i])+";learn "+id+" "+str[i]+" ...");
					} else
					tmp+=TMI("mitem 学习"+to_chinese(str[i])+";learn "+id+" "+str[i]+" ...");
				}
			}
		}
	} else {
		if(!ob->query("no_get"))
			tmp+=TMI("mitem 把$U捡起来;get "+id);
		if(ob->is_container()) {
			inv = all_inventory(ob);
			if(sizeof(inv)) {
				tmp+=TMI("mitem 把$U里的东西都拿出来;get all from "+id);
				tmp+=TMI("mitem 从$U里拿出...;get ... from "+id);
			}
			tmp+=TMI("mitem 把...装进$U里;put ... in "+id);
		}
		if(id=="board") {
			tmp+=TMI("mitem 读新的留言;read new");
			tmp+=TMI("mitem 读第...条留言;read ...");
			tmp+=TMI("mitem 写新的留言;post ...");
			tmp+=TMI("mitem 删除留言...;discard ...");
		}
	}
	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

int user_path(object me, object ob)
{
	mapping prop;
	string id,tmp;

	if(!objectp(ob)) return 1;
	
	if(stringp(tmp=ob->query_menu(me,1)))//如果对象能解释菜单，则直接返回菜单
	{
		write(tmp);
		return 1;
	}
	
	id=ob->query("id");
	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem 观察$U;look "+id);

	if(!ob->query("no_drop"))
		tmp+=TMI("mitem 丢弃$U;drop "+id);

	if(!ob->query("no_give"))
		tmp+=TMI("mitem 把$U给...;give "+id+" to ...");

	if(ob->query("liquid")) {
		if(ob->query("liquid/remaining"))
			tmp+=TMI("mitem 喝$U;drink "+id);
		if(environment(me)->query("resource/water"))
			tmp+=TMI("mitem 把$U装满水;fill "+id);
	}
	
	if(ob->query("food_remaining"))
		tmp+=TMI("mitem 吃$U;eat "+id);
		
	if(ob->is_container()) {
		tmp+=TMI("mitem 把$U里的东西都拿出来;get all from "+id);
		tmp+=TMI("mitem 从$U里拿出...;get ... from "+id);
		tmp+=TMI("mitem 把...装进$U里;put ... in "+id);
	}
	if(mapp(prop=ob->query("armor_prop"))&& stringp(ob->query("armor_type")) ) {
		if(!ob->query("equipped"))
			tmp+=TMI("mitem 穿上$U;wear "+id);
		else
			tmp+=TMI("mitem 脱下$U;remove "+id);
	}

	if(mapp(prop=ob->query("weapon_prop")) && stringp(ob->query("skill_type"))) {
		if(!ob->query("equipped"))
			tmp+=TMI("mitem 装备$U;wield "+id);
		else
			tmp+=TMI("mitem 解除装备$U;unwield "+id);
	}

	if(ob->query("skill"))
		tmp+=TMI("mitem 读$U;study "+id);
	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

