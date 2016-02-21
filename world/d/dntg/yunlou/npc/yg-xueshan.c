
// bula and mon@xyj

inherit __DIR__"yaoguai.c";
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HIW"天魔解体"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("bingpo-blade", j+random(15));
        me->set_skill("xiaoyaoyou", j+random(15));
        me->set_skill("dengxian-dafa", j+random(15));
        me->set_skill("ningxie-force", j+random(15));
        me->set_skill("cuixin-zhang", j+random(15));

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
        me->map_skill("parry", "bingpo-blade");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");
        create_family("大雪山", 2, "弟子");
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
//        (: perform_action,"bingpo-blade", "yaowu" :),
        (: cast_spell, "escape" :),
        (: cast_spell, "tuntian" :),
        (: cast_spell, "juanbi" :),
        }) );

           weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}

