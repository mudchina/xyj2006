
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

	set("title","·½´çÑýµÀ");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("stick", j);
        me->set_skill("qianjun-bang", j);
//        me->set_skill("sword",j);
  //      me->set_skill("sanqing-jian",j);
        me->set_skill("jindouyun", j);
        me->set_skill("wuxiangforce", j);
        me->set_skill("puti-zhi", j);
        me->set_skill("dao", j);

        me->map_skill("force", "wuxiangforce");
//        me->map_skill("sword", "sanqing-jian");
        me->map_skill("stick","qianjun-bang");
        me->map_skill("parry", "qianjun-bang");
        me->map_skill("spells", "dao");
        me->map_skill("dodge", "jindouyun");
        me->map_skill("unarmed", "puti-zhi");

        set("chat_chance_combat", 10+2*level);
        set("chat_msg_combat", ({
        (: perform_action,"stick", "pili" :),
        (: perform_action,"stick","qiankun" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "light" :),
        (: cast_spell, "dingshen" :),
        }) );

//        if (random(2))
  //         weapon=new("/d/obj/weapon/hammer/jingua");
    //    else
             weapon=new("/d/obj/weapon/stick/qimeigun");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
//        command("wield all");
}
