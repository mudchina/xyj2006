inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

        set("class","youling");
        set("family/family_name","µØ¸®");
        me->set("title",HIB"Ð¡Â¥Ò¹¿Þ"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("whip", j+random(5));
        me->set_skill("hellfire-whip", j+random(5));
        me->set_skill("stick",j+random(5));
        me->set_skill("kusang-bang",j+random(5));
        me->set_skill("ghost-steps", j+random(5));
        me->set_skill("jinghun-zhang", j+random(5));
        me->set_skill("tonsillit", j+random(5));
        me->set_skill("gouhunshu", j+random(5));

        me->map_skill("force", "tonsillit");
        me->map_skill("whip", "hellfire_whip");
        me->map_skill("stick","kusang-bang");
        me->map_skill("parry", "kusang-bang");
        me->map_skill("spells", "gouhunshu");
        me->map_skill("dodge", "ghost-steps");
        me->map_skill("unarmed", "jinghun-zhang");

     exp=query("combat_exp");
        
      if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action, "whip.three" :),
        (: cast_spell, "gouhun" :),
        (: exert_function, "sheqi" :),
        }) );
	if(exp<10000000){
          if (random(2)){
             weapon=new("/d/obj/weapon/whip/whip");
             set("weapon_","/d/obj/weapon/whip/whip");
          }
          else{
             weapon=new("/d/obj/weapon/stick/mugun");
             set("weapon_","/d/obj/weapon/stick/mugun");
          }   
          weapon->move(me);
          command("wield all");		
	}else{
          if (random(2)){
             weapon=new("/d/obj/weapon/whip/tielian");
             set("weapon_","/d/obj/weapon/whip/tielian");
          }
          else{
             weapon=new("/d/obj/weapon/stick/xiangmo");
             set("weapon_","/d/obj/weapon/stick/xiangmo");
          }   
          weapon->move(me);
          command("wield all");
        }
}
    }
