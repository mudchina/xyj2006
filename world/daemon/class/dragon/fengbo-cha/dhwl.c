
// dhwl.c
//write by yeahsi
//yeahsi@21cn.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void perform_effect(object me, object target);
void check(object me, object target, int dodge_amount);
void remove_effect(object me);
void match_force(object me,object target);
void perform_effect2(object me, object target);

int perform(object me, object target)
{
        int skill,skill_fork,fengbo_skill,skill_dodge,dodge_amount,ini_dodge_apply,ini_damage_apply;
        
        skill = me->query_skill("dragonforce",1);
        skill_dodge = me->query_skill("dodge",1);
        skill_fork= me->query_skill("fork",1);
        fengbo_skill= me->query_skill("fengbo-cha",1);
	dodge_amount = (skill+skill_dodge)/20;              
        
        if (!me->query_temp("dhwl"))
             ini_dodge_apply = me->query_temp("apply/dodge");
                  
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「大海无量」？\n");

        if(!me->is_fighting())
               return notify_fail("「大海无量」只能在战斗中使用！\n");
                
        if( time()-(int)me->query_temp("dhwl_end") < 6 )
                return notify_fail("绝招用多就不灵了！\n");
        
        if (me->query_temp("dhwl")) return notify_fail("你已经在蓄力了。\n");
        if( skill < 100 )  return notify_fail("你的龙神心法修为不够。\n");
        if( skill_fork < 100 )  return notify_fail("你的基本叉法未够纯熟。\n");
        if( fengbo_skill < 160 )  return notify_fail("你的风波十二叉未够纯熟。\n");
               
        if( (int)me->query("force") < skill )     
		return notify_fail("你的内力不够。\n");
 
        me->add("force", -skill);
        me->set_temp("dhwl_target",target);
        tell_object(me, MAG"你不动声色将龙神心法在体内一转，觉得一股真气从脚下涌泉穴缓缓升起。\n"NOR);
        me->set_temp("no_move",1);  
        me->set_temp("dhwl", 1);
        me->set_temp("before_dhwl_dodge",ini_dodge_apply);
        call_out("check", 1, me,target,dodge_amount);
        return 1;
}


void check(object me, object target, int dodge_amount)
{   	
	object weapon;
		
	 if(!me) return;
	 
    if(!target) return;
	 if (me->query_skill_mapped("force") != "dragonforce"
	         || !objectp(weapon=me->query_temp("weapon")) 
	         || (weapon->query("apply/skill_type") != "fork" 
	             && weapon->query("skill_type") != "fork" ) 
	         ||  me->query_skill_mapped("fork") != "fengbo-cha" )     
	     remove_effect(me);
	 	 	    
         else if(!present(target->query("id"), environment(me)) || !me->is_fighting(target) || !me->is_fighting())
	           remove_effect(me);
	 
	 else if(!me->query_temp("dhwl"))
	       remove_effect(me);
	           
	else {me->add_temp("dhwl",1);
	      if (me->query_temp("dhwl")==10)
	            tell_object(me, MAG"你运气一周天，浑身充满强霸的力道。突然间脑际灵光一闪，气化为神，神化为虚只冲头顶。\n\n"NOR);     
	      else if (me->query_temp("dhwl")==9)
	            tell_object(me, MAG"你突觉内力运转周身无法突破，不禁闭目沉思，然而就在闭上双目的一瞬间意识到眼不视而魂在肝的道理。\n\n"NOR);
	      else if (me->query_temp("dhwl")==8)
	            tell_object(me, MAG"你心平气静，对外界的嘈杂亦不听不想；耳不闻而精在肾，沉身运气，内力更高了一层。\n\n"NOR);
	      else if (me->query_temp("dhwl")==7)
	            tell_object(me, MAG"你屏住气息，运转内力于肺间。呼吸均匀悠长，以然达到了鼻不香而魄在肺的境界。\n\n"NOR);
	      else if (me->query_temp("dhwl")==6)
	            tell_object(me, MAG"你想起龙神心法所言：舌不吟而神在心。连忙收声运气，但觉得心灵中一片空灵。\n\n"NOR);
	      else if (me->query_temp("dhwl")==5)
	            tell_object(me, MAG"你将沉与丹田之力带行全身，身上啪啪连响，运转自如直冲任督，忍不住纵声长啸。\n\n"NOR);
	      else if (me->query_temp("dhwl")==4)
	            tell_object(me, MAG"你默念龙神心法，四肢不动而意在脾，人虽未动，却只觉内力沉于丹田，力量倍增。\n\n"NOR);
	      else if (me->query_temp("dhwl")==3)
	            tell_object(me, MAG"你收敛心神，把脚底热气运至膝间跳环，但觉内力运转间身轻无比。\n\n"NOR);
	      else if (me->query_temp("dhwl")==2)
	            tell_object(me, MAG"\n你运起龙神心法，转瞬间突然周身骨骼格格做响，面上浮现出阵阵青气。\n\n"NOR);
	      	                                          
	     // me->add_temp("apply/dodge",random(dodge_amount));
	      
	      call_out("check", 1, me,target,dodge_amount);
	     }
             
}


void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check");
        remove_call_out("remove_effect");
        me->set_temp("apply/dodge",me->query_temp("before_dhwl_dodge"));
        me->delete_temp("before_dhwl_dodge");
        me->delete_temp("dhwl_target");
        if (!me->query_temp("dhwl_match_force"))
               me->delete_temp("no_move");
        if (me->query_temp("dhwl"))
             tell_object(me, GRN"你只觉真气一松，提不起劲了。\n"NOR);
        me->delete_temp("dhwl");
}


