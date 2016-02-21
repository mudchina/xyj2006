
// À¥ÂØÑý¹Ö
//lestat 2001
inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;
	set("title",HIW"ÓñÐéÃÅÏÂ"NOR);
	set("gender", "ÄÐÐÔ");
//	set("gender","´ÆÐÔ");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("mace", j+random(5));
        me->set_skill("dashen-bian", j+random(5));
        me->set_skill("sword",j+random(5));
        me->set_skill("wugou-jian",j+random(5));
        me->set_skill("lingyunbu", j+random(5));
        me->set_skill("yuxu-spells", j+random(5));
        me->set_skill("kaitian-zhang", j+random(5));
        me->set_skill("xuanzong-force", j+random(5));

        me->map_skill("force", "xuanzong-force");
        me->map_skill("sword", "wugou-jian");
        me->map_skill("mace","dashen-bian");
        me->map_skill("parry", "wugou-jian");
        me->map_skill("spells", "yuxu-spells");
        me->map_skill("dodge", "lingyunbu");
        me->map_skill("unarmed", "kaitian-zhang");
        create_family("À¥ÂØÉ½ÓñÐé¶´",3 , "µÜ×Ó");
                    exp=query("combat_exp");
    if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: perform_action,"sword", "feixian" :),
        }) );}
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
