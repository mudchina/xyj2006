inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

	set("family/family_name","Îå×¯¹Û");
	me->set("title",CYN"Ì«ÒÒÕæÏÉ"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("hammer", j+random(5));
        me->set_skill("kaishan-chui", j+random(5));
        me->set_skill("sword",j+random(5));
        me->set_skill("sanqing-jian",j+random(5));
        me->set_skill("baguazhen", j+random(5));
        me->set_skill("taiyi", j+random(5));
        me->set_skill("wuxing-quan", j+random(5));
        me->set_skill("zhenyuan-force", j+random(5));

        me->map_skill("force", "zhenyuan-force");
        me->map_skill("sword", "sanqing-jian");
        me->map_skill("hammer","kaishan-chui");
        me->map_skill("parry", "kaishan-chui");
        me->map_skill("spells", "taiyi");
        me->map_skill("dodge", "baguazhen");
        me->map_skill("unarmed", "wuxing-quan");

    exp=query("combat_exp");
    if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "zhenhuo" :),
        (: cast_spell, "baxian" :),
         (: perform_action, "sword.jianmang" :),
        (: perform_action, "hammer.danshan" :),
        }) );

	if(exp<10000000){
	  if (random(2)){
               weapon=new("/d/obj/weapon/sword/changjian");
               set("weapon_","/d/obj/weapon/sword/changjian");
          }
          else{
               weapon=new("/d/obj/weapon/hammer/hammer");
               set("weapon_","/d/obj/weapon/hammer/hammer");
          }
          weapon->move(me);
          command("wield all");
	}else{
	  if (random(2)){
               weapon=new("/d/obj/weapon/sword/qingfeng");
               set("weapon_","/d/obj/weapon/sword/qingfeng");
          }
          else{
               weapon=new("/d/obj/weapon/hammer/jingua");
               set("weapon_","/d/obj/weapon/hammer/jingua");
          }
          weapon->move(me);
          command("wield all");
        }
    }
}
