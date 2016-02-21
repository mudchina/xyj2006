
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title","将军府叛将");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("spear", j);
        me->set_skill("bawang-qiang", j);
        me->set_skill("axe",j);
        me->set_skill("sanban-axe",j);
        me->set_skill("yanxing-steps", j);
        me->set_skill("changquan", j);
        me->set_skill("lengquan-force", j);
        me->set_skill("baguazhou", j);

        me->map_skill("force", "lengquan-force");
        me->map_skill("axe", "sanban-axe");
        me->map_skill("spear","bawang-qiang");
        me->map_skill("parry", "bawang-qiang");
        me->map_skill("spells", "baguazhou");
        me->map_skill("dodge", "yanxing-steps");
        me->map_skill("unarmed", "changquan");

        set("chat_chance_combat", 10+2*level);
        set("chat_msg_combat", ({
        (: perform_action,"axe", "sanban" :),
//        (: cast_spell, "gouhun" :),
        (: exert_function, "jingxin" :),
        }) );

        if (random(2))
//           weapon=new("/d/obj/weapon/axe/huafu")
           weapon=new("/d/obj/weapon/axe/tiefu");
        else
//           weapon=new("/d/obj/weapon/spear/changqiang")
           weapon=new("/d/obj/weapon/spear/tieqiang");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
//        command("wield all");
}
