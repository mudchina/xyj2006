inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

        set("class","dragon");
        set("family/family_name","东海龙宫");
        me->set("title",HIC"无尽风波"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("fork", j+random(5));
        me->set_skill("fengbo-cha", j+random(5));
        me->set_skill("hammer",j+random(5));
        me->set_skill("huntian-hammer",j+random(5));
        me->set_skill("dragonstep", j+random(5));
        me->set_skill("dragonfight", j+random(5));
        me->set_skill("dragonforce", j+random(5));
        me->set_skill("seashentong", j+random(5));

        me->map_skill("force", "dragonforce");
        me->map_skill("fork", "fengbo-cha");
        me->map_skill("hammer","huntian-hammer");
        me->map_skill("parry", "huntian-hammer");
        me->map_skill("spells", "seashentong");
        me->map_skill("dodge", "dragonstep");
        me->map_skill("unarmed", "dragonfight");

	exp=me->query("combat_exp");
	if(exp>1000000){
          set("chat_chance_combat", cast_chance(level));
          set("chat_msg_combat", ({
            (: cast_spell, "freez" :),
            (: cast_spell, "breathe" :),
            (: exert_function, "roar" :),
            (: exert_function, "shield" :),
	  }) );
	
	 if(exp<10000000){
	     if (random(2)){
           	weapon=new("/d/obj/weapon/hammer/hammer");
           	set("weapon_","/d/obj/weapon/hammer/hammer");
             }
             else{
                weapon=new("/d/sea/obj/mucha");
                set("weapon_","/d/sea/obj/mucha");
             }
             weapon->move(me);
             command("wield all");
	 }else{
	     if (random(2)){
           	weapon=new("/d/obj/weapon/hammer/jingua");
           	set("weapon_","/d/obj/weapon/hammer/jingua");
             }
             else{
                weapon=new("/d/obj/weapon/fork/gangcha");
                set("weapon_","/d/obj/weapon/fork/gangcha");
             }
             weapon->move(me);
             command("wield all");
        }
      }
}
