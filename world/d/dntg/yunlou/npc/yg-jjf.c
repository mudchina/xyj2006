
// bula and mon@xyj

inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HIR"无敌三板斧"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("mace", j);
        me->set_skill("wusi-mace",j+random(15));
 
        me->set_skill("spear", j+random(15));
        me->set_skill("bawang-qiang", j+random(15));
        me->set_skill("axe",j+random(15));
        me->set_skill("sanban-axe",j+random(15));
        me->set_skill("yanxing-steps", j+random(15));
        me->set_skill("changquan", j+random(15));
        me->set_skill("lengquan-force", j+random(15));
        me->set_skill("baguazhou", j+random(15));

        me->map_skill("force", "lengquan-force");
        me->map_skill("axe", "sanban-axe");
        me->map_skill("spear","bawang-qiang");
        me->map_skill("mace","wusi-mace");
        me->map_skill("parry", "bawang-qiang");
        me->map_skill("spells", "baguazhou");
        me->map_skill("dodge", "yanxing-steps");
        me->map_skill("unarmed", "changquan");
        create_family("将军府", 3, "蓝");
//        set("chat_chance_combat", cast_chance(level));
  set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: perform_action,"axe", "sanban" :),
//        (: perform_action,"mace", "suo" :),
//        (: cast_spell, "gouhun" :),
        (: exert_function, "jingxin" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/axe/huafu");
        else
           weapon=new("/d/obj/weapon/mace/langyamace");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
