
// tomcat

inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j= 200+random(150);  
        create_family("将军府", 3, "弟子");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
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
        me->map_skill("parry", "bawang-qiang");
        me->map_skill("spells", "baguazhou");
        me->map_skill("dodge", "yanxing-steps");
        me->map_skill("unarmed", "changquan");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"axe", "sanban" :),
        (: exert_function, "jingxin" :),
        
        }) );

        weapon=new("/d/obj/weapon/axe/huafu");
        weapon->move(me);
        
        command("wield all");
}
