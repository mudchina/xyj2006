
// bula and mon@xyj

inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HIB"¸èÎèÑÖÂÞ"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("whip", j+random(15));
        me->set_skill("hellfire-whip", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("zhuihun-sword",j+random(15));
        me->set_skill("ghost-steps", j+random(15));
        me->set_skill("jinghun-zhang", j+random(15));
        me->set_skill("tonsillit", j+random(15));
        me->set_skill("gouhunshu", j+random(15));

        me->map_skill("force", "tonsillit");
         me->map_skill("whip", "hellfire-whip");
        me->map_skill("sword","zhuihun-sword");
        me->map_skill("parry", "zhuihun-sword");
        me->map_skill("spells", "gouhunshu");
        me->map_skill("dodge", "ghost-steps");
        me->map_skill("unarmed", "jinghun-zhang");
        create_family("ÑÖÂÞµØ¸®", 2, "µÜ×Ó");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"whip", "ldlh" :),
//        (: perform_action,"sword", "yanluo" :),
        (: cast_spell, "gouhun" :),
        (: cast_spell, "inferno" :),
//        (: cast_spell, "dingshen" :),
        }) );

//        if (random(2))
             weapon=new("/d/sea/obj/dragonwhip");
//        else
//           weapon=new("/d/obj/weapon/sword/qinghong");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
