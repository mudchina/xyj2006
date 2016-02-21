inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

        set("family/family_name","´óÑ©É½");
        me->set("title",HIW"°ÙÄñ³¯·ï"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("sword",  j);
 
        me->set_skill("blade", j+random(5));
        me->set_skill("bingpo-blade", j+random(5));
        me->set_skill("xiaoyaoyou", j+random(5));
        me->set_skill("dengxian-dafa", j+random(5));
        me->set_skill("ningxie-force", j+random(5));
        me->set_skill("cuixin-zhang", j+random(5));
        me->set_skill("birds-sword", j+random(5));

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
        me->map_skill("parry", "birds-sword");
        me->map_skill("sword", "birds-sword");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");


    exp=query("combat_exp");
    if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "juanbi" :),
        (: perform_action, "blade.yaowu" :),
        (: perform_action, "sword.chaofeng" :),
        }) );

	if(exp<10000000){
	  if (random(2)){
               weapon=new("/d/obj/weapon/sword/changjian");
               set("weapon_","/d/obj/weapon/sword/changjian");
          }
          else{
               weapon=new("/d/obj/weapon/blade/dandao");
               set("weapon_","/d/obj/weapon/blade/dandao");
          }
          weapon->move(me);
          command("wield all");
	}else{
	  if (random(2)){
               weapon=new("/d/obj/weapon/sword/qingfeng");
               set("weapon_","/d/obj/weapon/sword/qingfeng");
          }
          else{
               weapon=new("/d/obj/weapon/blade/jindao");
               set("weapon_","/d/obj/weapon/blade/jindao");
          }
          weapon->move(me);
          command("wield all");
        }
    }
}
