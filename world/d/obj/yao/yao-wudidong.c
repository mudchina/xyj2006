inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
         int exp;

        set("family/family_name","ÏÝ¿ÕÉ½ÎÞµ×¶´");
        me->set("title",YEL"ÆÆ¼ëÌìÄ§"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(5));
        me->set_skill("kugu-blade", j+random(5));
        me->set_skill("sword",j+random(5));
        me->set_skill("qixiu-jian",j+random(5));
        me->set_skill("lingfu-steps", j+random(5));
        me->set_skill("yaofa", j+random(5));
        me->set_skill("huntian-qigong", j+random(5));
        me->set_skill("yinfeng-zhua", j+random(5));

        me->map_skill("force", "huntian-qigong");
        me->map_skill("blade", "kugu-blade");
        me->map_skill("sword","qixiu-jian");
        me->map_skill("parry", "kugu-blade");
        me->map_skill("spells", "yaofa");
        me->map_skill("dodge", "lingfu-steps");
        me->map_skill("unarmed", "yinfeng-zhua");

    exp=query("combat_exp");
    if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "huanying" :),
        (: cast_spell, "suliao" :),
        (: perform_action, "blade.pozhan" :),
        (: perform_action, "sword.yaowu" :),
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
