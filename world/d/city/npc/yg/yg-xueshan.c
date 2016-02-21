
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title","Ñ©É½ÀÏÑý");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j);
        me->set_skill("bingpo-blade", j);
//        me->set_skill("hammer",j);
  //      me->set_skill("huntian-hammer",j);
        me->set_skill("xiaoyaoyou", j);
        me->set_skill("dengxian-dafa", j);
        me->set_skill("ningxie-force", j);
        me->set_skill("cuixin-zhang", j);

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
//        me->map_skill("hammer","huntian-hammer");
        me->map_skill("parry", "bingpo-blade");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");

//        set("chat_chance_combat", 10+2*level);
//        set("chat_msg_combat", ({
//        (: perform_action,"sanban-axe", "sanban" :),
//        (: cast_spell, "freez" :),
  //      (: cast_spell, "breathe" :),
    //    (: exert_function, "roar" :),
      //  (: exert_function, "shield" :),
 //       }) );

//        if (random(2))
  //         weapon=new("/d/obj/weapon/hammer/jingua");
    //    else
//           weapon=new("/d/obj/weapon/blade/jindao")
           weapon=new("/d/obj/weapon/blade/blade");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
//      command("wield all");
}
