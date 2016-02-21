inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

	set("class","xian");
	set("family/family_name","月宫");
	set("gender", "女性");
	me->set("title",HIM"天地双飞"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("whip", j+random(5));
        me->set_skill("jueqingbian", j+random(5));
        me->set_skill("sword",j+random(5));
        me->set_skill("snowsword",j+random(5));
        me->set_skill("moondance", j+random(5));
        me->set_skill("moonshentong", j+random(5));
        me->set_skill("baihua-zhang", j+random(5));
        me->set_skill("moonforce", j+random(5));

        me->map_skill("force", "moonforce");
        me->map_skill("sword", "snowsword");
        me->map_skill("whip","jueqingbian");
        me->map_skill("parry", "jueqingbian");
        me->map_skill("spells", "moonshentong");
        me->map_skill("dodge", "moondance");
        me->map_skill("unarmed", "baihua-zhang");

     exp=query("combat_exp");
     if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "arrow" :),
        (: cast_spell, "mihun" :),
        (: perform_action, "sword.tian" :),
        }) );

        if(exp<10000000){
             if (random(2)){
                weapon=new("/d/obj/weapon/whip/whip");
                set("weapon_","/d/obj/weapon/whip/whip");
             }
             else{
                weapon=new("/d/obj/weapon/sword/changjian");
                set("weapon_","/d/obj/weapon/sword/changjian");
             }
             weapon->move(me);
             command("wield all");
        }else{
             if (random(2)){
                weapon=new("/d/obj/weapon/whip/longsuo");
                set("weapon_","/d/obj/weapon/whip/longsuo");
             }
             else{
                weapon=new("/d/obj/weapon/sword/qingfeng");
                set("weapon_","/d/obj/weapon/sword/qingfeng");
             }
             weapon->move(me);
             command("wield all");
        }
    }
}
