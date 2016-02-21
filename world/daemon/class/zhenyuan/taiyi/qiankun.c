//cast function: qiankun.c 袖里乾坤。
//need to be activated by 镇元大仙 to use this cast...weiqi, 
//weiqi, mon 1/98

#include <ansi.h>

inherit SSERVER;

#define WIND_FILE "/d/jjf/obj/wind_seal.c"

void get_out(object where);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp;
	object sleeveroom,sleeve;
	string sname;
	object env, *inv;
	int size, i, taiyi_level;
	int maxenc;

	seteuid(getuid());

	if( me->query("spell_qiankun_on") != 1 )
		return notify_fail("你还不会袖里乾坤。\n");
         if(me->query("family/family_name") != "五庄观")
                return notify_fail("[袖里乾坤]是五庄观不传之密！\n");
          if(me->query_temp("pkgame"))
                return notify_fail("你不能对参加ｃｓ大赛选手使用[袖里乾坤]！\n");

if ((int)me->query("faith") < 500 )
     return notify_fail("你的门忠太低,还未学会袖里乾坤。\n");
//	if( !target ) target = offensive_target(me);

        if(!target) 
        {
          //see if I am fighting someone...this is useful for NPC...
          if(  (offensive_target(me)) ) target = offensive_target(me);
 	  else
         {
	  // then take stuff out.
	  sleeveroom=load_object("/d/wiz/sleeveroom");
	  if(!sleeveroom) return notify_fail("你的袖子恐怕破了。\n");

          sname=me->query("id")+"'s sleeve";
          if(!sleeve=present(sname,sleeveroom)) {
             message_vision(
	     "$N将大袖迎空一甩，但是里面什么也没有。\n",me);
	     return 1;
          }

	  size=sizeof(inv=all_inventory(sleeve));
	  if(!size) {
             message_vision(
	     "$N将大袖迎空一甩，但是里面什么也没有。\n",me);
	     return 1;
          }

	  msg="$N将大袖迎空一甩，";
	  for(i=0;i<size;i++) {
	    if(inv[i]->is_character())
	      msg+="$n扑通一声摔倒在地上。\n";
            else
	      msg+="$n嗵地一声砸在地上。\n";

            env=environment(me);
            while(!(inv[i]->move(env))) env=environment(env);

	    message_vision(msg,me,inv[i]);
	    msg="";
	  }
          return 1;
	}
       }

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("你要对谁施展袖里乾坤？\n");

	if( (int)me->query("mana") < 400 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
		return notify_fail("你现在头脑不清醒，哪里使得出袖里乾坤！\n");

	if( random(me->query("max_mana")) < 50 ) {
		write("你失败了！\n");
		return 1;
	}

	msg =  HIR "$N喃喃地念了几句咒语，突然大袖一挥朝$n罩了过去！\n" NOR;
	message_vision(msg, me, target);
	
	target->kill_ob(me);

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("daoxing");
	ap = 3*ap; 
	dp = target->query("daoxing");
	if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
	if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to success.

	if(success == 1 )
	{
		me->add("mana", -400);
	
	        sleeveroom=load_object("/d/wiz/sleeveroom");
		if(!sleeveroom) return notify_fail("你的袖子恐怕破了。\n");

                sname=me->query("id")+"'s sleeve";
		if(!sleeve=present(sname,sleeveroom)) {
                  sleeve=new("/d/obj/fabao/sleeve");
		  if(!sleeve) return notify_fail("你的袖子恐怕破了。\n");

		taiyi_level = (int)me->query_skill("taiyi", 1);
		maxenc=taiyi_level*2000;
		if(maxenc>400000) maxenc=400000;
		sleeve->set_max_encumbrance(maxenc);
		// mon 4/15/98
/*
		if( taiyi_level < 50 ) sleeve->set_max_encumbrance(100000);
		else if( taiyi_level < 100 ) sleeve->set_max_encumbrance(200000);
		else if( taiyi_level < 150 ) sleeve->set_max_encumbrance(300000);
		else sleeve->set_max_encumbrance(400000);
*/
		  //400000 correspondes to about 4 people?
		//note...if we want a npc can not be moved...can set its str very high...:)

		  sleeve->set_name(
		    me->query("name")+"的衣袖中",({sname,"sleeve"}));
                  sleeve->set("short",
		    me->query("name")+"的衣袖中");
		  if(!sleeve->move(sleeveroom)) 
		    return notify_fail("你的袖子恐怕破了。\n");
		}

		if(target->move(sleeve)) {
		  msg =  HIR "结果嗖的一声$n被装了进去。\n" NOR;
		  message_vision(msg, me, target);
		  
		  // mon 7/31/98
		  if(!userp(me)) {
		      call_out("get_out", 120+random(240), sleeve);
		  } else
		      call_out("get_out", 240+random(480), sleeve);


                } else {
                  msg=HIR"结果$n只是摇晃了一下，又不动了。\n" NOR;
		  msg+="$n对$N来说太沉了。\n";
		  message_vision(msg, me, target);
		}
		
	}
	else 
	{
		msg =  HIR "结果被$n法力一逼，差点罩住$N自己的脑袋。\n" NOR;
		message_vision(msg, me, target);

		me->add("mana", -400);
	} 

	return 3+random(5);
}

void get_out(object where)
{
   object wind, *inv;
   int i;

   if(!where) return;

   i=sizeof(inv=all_inventory(where));
   while(i--) {
      if(inv[i]->is_character()) { // NPC or players 
         wind=new(WIND_FILE); // wind can only be used once, so need to new.
         wind->do_blow(inv[i]);
         message_vision("只见铺天盖地大袖一挥，$N扑通一声狠狠地砸在地上！\n",
	   inv[i]);
//         inv[i]->unconcious();
         destruct(wind);
      } else  // objects.
	  destruct(inv[i]); 
   }

   return;
}
