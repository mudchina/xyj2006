// pk_counter.c
// by mon. 9/22/97

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        object env=environment(me);
	int damage;
	string *msg=({
	BLU"你突然背上凉嗖嗖的,冷汗直流, 是不是有鬼?\n"NOR,
	BLU"你回想起所做过的罪孽,背上冷汗直流. \n"NOR,
	HIY"突然天上电闪雷鸣,一个霹雳打在你的头上.\n"NOR,
	}); 	
	if(env) {
	    if(!env->query("no_fight") && !env->query("no_magic"))
	       me->apply_condition("no_pk_time", duration - 1);
	    else
	     { 
		if (random(2)==0)  
		tell_object(me,msg[random(sizeof(msg))]);
		if (living(me))
		 {
		  if (me->query("kee")<=10 || me->query("sen")<=10)
		       	me->unconcious(); 
		  else { 
		    me->receive_damage("kee", me->query("max_kee")/10);
	            me->receive_damage("sen", me->query("max_sen")/10);
	          }
	         }
	          if( duration < 1 ) return 0;
		  return 3;
	     }
	    // can't hide in safe room to count hours.
	}

//	write("PK:"+duration+":"+me->query_condition("no_pk_time")+"\n");

	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}

// mon 8/1/98
// this condition can't be cleared.
int no_clear_condition() {return 1;}

