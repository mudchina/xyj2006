
// tomcat

inherit __DIR__"fei.c";

// here should be this NPC specific skills.

void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j= 200+random(150);  	
        create_family("方寸山三星洞", 3, "弟子"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("stick", j+random(15));
        me->set_skill("qianjun-bang", j+random(15));
        me->set_skill("jindouyun", j+random(15));
        me->set_skill("wuxiangforce", j+random(15));
        me->set_skill("puti-zhi", j+random(15));
        me->set_skill("dao", j+random(15));

        me->map_skill("force", "wuxiangforce");
        me->map_skill("stick","qianjun-bang");
        me->map_skill("parry", "qianjun-bang");
        me->map_skill("spells", "dao");
        me->map_skill("dodge", "jindouyun");
        me->map_skill("unarmed", "puti-zhi");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"stick", "pili" :),
        (: perform_action,"stick","qiankun" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "light" :),
        (: cast_spell, "dingshen" :),
        }) );

        weapon=new("/d/obj/weapon/stick/xiangmo");
        weapon->move(me);
        command("wield all");
}
