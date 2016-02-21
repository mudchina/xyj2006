// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher, master;
	object ob;
	int master_skill, my_skill, sen_cost;
	int time, upper, sen1;
	int amount, qskill, qlearned, i;

	if(!arg) return notify_fail
		    ("指令格式：learn <技能> from <某人> for <次数>\n");

	if(sscanf(arg, "%s for %d", arg, time)!=2 ) 
	    time=1;
	
	if(time<1) time=1;
	if(time>50) time=50;

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
	    return notify_fail
		    ("指令格式：learn <技能> from <某人> for <次数>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if(me->is_busy())
	    return notify_fail("你正忙着呢。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯．．．你得先把" + ob->name() + "弄醒再说。\n");

	if( !me->is_apprentice_of(ob) && getuid(ob)!=me->query("couple/id") 
		                                           ) {
//		&& getuid(ob)!=me->query("bonze/dadangid") ) {

		notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
		if( (string)me->query("family/family_name") != 
			(string)ob->query("family/family_name")
		||	(int)ob->query("family/privs") != -1 ) {
			if( !(ob->recognize_apprentice(me)) ) return 0;
		} else return 0; // mon add this return 0. 5/6/98
	}

	if( ob->is_fighting())
		return notify_fail("你的师傅暂时没空指点你武功。\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	notify_fail(ob->name() + "不愿意教你这项技能。\n");
	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	sen_cost = 300 / (int)me->query_int();

	upper= (int)me->query("potential")-(int)me->query("learned_points");
	if(time>upper) time=upper;

	if(upper<=0)
		return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	
	printf("你向%s请教有关「%s」的疑问。\n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");
        if(!my_skill) {  //It's a bug here, player can learn 0 skill
			//But players want that. shrug.   2000.12.10 beeby
                sen_cost *= 2;
                me->set_skill(skill,0);
        }

	// can't learn from another player if oneself
	// don't have the skill.
	if(userp(ob) && (int)my_skill<1) {
	    return notify_fail("可是你怎么也弄不明白。\n");
	}
/*        if(!my_skill) {
                sen_cost *= 2;
                me->set_skill(skill,0);
        }
*/
        qskill=me->query_skills()[skill]+1;
        qskill*=qskill;
        qlearned=me->query_learned()[skill];
        amount = qlearned;

        // for those level higher than master's
        if( amount > qskill )  {
           for(i=0; i<time; i++)
               amount += random(me->query_int())+1;
        }
        else {
           for(i=0; i<time; i++)   {
              amount += random(me->query_int())+1;
              if( amount > qskill )  {i++;break;}
       }
        }

        amount -= qlearned;
        time = i;
        sen_cost *= time;

	// can't learn above 100 level from a player.
	// mon 3/7/98
        if(userp(ob) && my_skill>=100)
	  return notify_fail("可是"+
	    ob->name()+"已经无力指导你进一步提高了。\n");

	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));

    sen1=(int)ob->query("sen");
    if(userp(ob) || sen1<50)
	if(sen1 > sen_cost + 1 ) {
		if( userp(ob) ) ob->receive_damage("sen", sen_cost+1);
	} else {
		write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}
		

	if( (int)me->query("sen") > sen_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是实战经验不够，你对%s的回答总是无法领会。\n", ob->name() );
		}
		else if( (string)SKILL_D(skill)->type()=="magic"
		&&      my_skill * my_skill * my_skill / 10 > (int)me->query("daoxing") ) {
		           printf("也许是道行不够，你对%s的回答总是无法领会。\n", ob->name() );
		}
		
		else {

                     //added by mon. 7/24/97
		     //to learn beyond NPC master's skill with an added cost.
	             me->add("learned_points", time);
                     if( my_skill < master_skill ) {
			printf("你听了%s的指导，似乎有些心得。\n", ob->name());
			me->improve_skill(skill, amount);
                     } else {
			if(qlearned<me->query_int())
			  message_vision("$N对$n说道："+
			    "你的「"+to_chinese(skill)+
			    "」已经不输为师了，咱们一起切磋切磋吧！"
                            +"\n",ob,me);
		        printf("%s和你切磋了一会儿%s，你似乎有所领悟。\n",
			  ob->name(),to_chinese(skill));
                        me->improve_skill(skill, amount,
			  (qlearned>4*qskill && !userp(ob)) ?0:1);
			  //can't learn beyond a player master's level.
		     }
		}
	} else {
//		sen_cost = me->query("sen");
//		if(sen_cost<0) sen_cost=0;
		write("你今天太累了，结果什么也没有学到。\n");
	        me->start_busy(1);
		return 1;
	}

	me->receive_damage("sen", sen_cost );
//	me->start_busy(1);

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : learn|xue <技能> from <某人> for <次数>
 
这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高于你所请
教的人，然而因为这种学习方式相当于一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

通常，一个人刚学到一种新技能是不会有什么疑难问题的，而是经由实际上的应用中
遭遇问题，这些问题对于学习一种新技能的过程是很重要的，尤其是各种作为其他技
能基础的基本技能，更需要经由「发现问题─解决问题」的过程才能得到较好的效果
因此我们将这种发现问题的过程用「潜能」的观念表示，一个人能够自己发现某些问
题，表示他(她)有解决这项问题的潜能，当你具有这样的潜能时就可以利用这个指令
来向其他人请教，而获得进步。
(PS. 潜能还有其他更广义的定义，这里只是其中之一 )

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

至于如何知道你能从对方学到什么技能，如果对方是你的师父，可以用 skills 指令
直接查看，如果不是你的师父，那么通常会有其他的提示，你只好自己想办法。

其他相关指令 : practice、study
HELP
        );
        return 1;
}
