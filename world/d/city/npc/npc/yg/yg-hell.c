
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title","ÓÄÚ¤¶ñ¹í");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("whip", j);
        me->set_skill("hellfire-whip", j);
        me->set_skill("stick",j);
        me->set_skill("kusang-bang",j);
        me->set_skill("ghost-steps", j);
        me->set_skill("jinghun-zhang", j);
        me->set_skill("tonsillit", j);
        me->set_skill("gouhunshu", j);

        me->map_skill("force", "tonsillit");
        me->map_skill("whip", "hellfire_whip");
        me->map_skill("stick","kusang-bang");
        me->map_skill("parry", "kusang-bang");
        me->map_skill("spells", "gouhunshu");
        me->map_skill("dodge", "ghost-steps");
        me->map_skill("unarmed", "jinghun-zhang");

        set("chat_chance_combat", 10+2*level);
        set("chat_msg_combat", ({
        (: perform_action,"whip", "three" :),
        (: cast_spell, "gouhun" :),
        (: exert_function, "sheqi" :),
//        (: cast_spell, "dingshen" :),
        }) );

        if (random(2))
//           weapon=new("/d/obj/weapon/whip/longsuo")
           weapon=new("/d/obj/weapon/whip/whip");
        else
//           weapon=new("/d/obj/weapon/stick/xiangmo")
           weapon=new("/d/obj/weapon/stick/qimeigun");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
//        command("wield all");
}
