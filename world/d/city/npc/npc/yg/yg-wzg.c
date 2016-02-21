
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

	set("title","Îå×¯¹ÛÐ×Í½");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("hammer", j);
        me->set_skill("kaishan-chui", j);
        me->set_skill("sword",j);
        me->set_skill("sanqing-jian",j);
        me->set_skill("baguazhen", j);
        me->set_skill("taiyi", j);
        me->set_skill("wuxing-quan", j);
        me->set_skill("zhenyuan-force", j);

        me->map_skill("force", "zhenyuan-force");
        me->map_skill("sword", "sanqing-jian");
        me->map_skill("hammer","kaishan-chui");
        me->map_skill("parry", "kaishan-chui");
        me->map_skill("spells", "taiyi");
        me->map_skill("dodge", "baguazhen");
        me->map_skill("unarmed", "wuxing-quan");

        set("chat_chance_combat", 10+2*level);
        set("chat_msg_combat", ({
        (: cast_spell, "zhenhuo" :),
        (: cast_spell, "baxian" :),
        }) );

        if (random(2))
//           weapon=new("/d/obj/weapon/hammer/jingua")
           weapon=new("/d/obj/weapon/hammer/hammer");
        else
//           weapon=new("/d/obj/weapon/sword/qingfeng")
           weapon=new("/d/obj/weapon/sword/duanjian");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
//        command("wield all");
}
