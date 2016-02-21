inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

        set("family/family_name","ÅÌË¿¶´");
        me->set("title",MAG"ÌìÂÞµØÍø"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("stick", j+random(5));
        me->set_skill("qitian-gun", j+random(5));
        me->set_skill("jindouyun", j+random(5));
        me->set_skill("mihou-force", j+random(5));
        me->set_skill("houquan", j+random(5));
        me->set_skill("mihouxinjing", j+random(5));

        me->map_skill("force", "mihou-force");
        me->map_skill("stick","qitian-gun");
        me->map_skill("parry", "qitian-gun");
        me->map_skill("spells", "mihouxinjing");
        me->map_skill("dodge", "jindouyun");
        me->map_skill("unarmed", "houquan");

	exp=query("combat_exp");
	
      if(exp>1000000){	
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
//       (: perform_action, "stick.sheng" :),
//        (: perform_action, "stick.wu" :),
        (: cast_spell, "zhaitao" :),
        (: cast_spell, "dingshen" :),
        }) );

	if(exp<10000000){
          weapon=new("/d/obj/weapon/stick/mugun");
          set("weapon_","/d/obj/weapon/stick/mugun");
          weapon->move(me);
          command("wield all");
	}else{
          weapon=new("/d/obj/weapon/stick/xiangmo");
          set("weapon_","/d/obj/weapon/stick/xiangmo");
          weapon->move(me);
          command("wield all");
        }
      } 
}
