
// wudidong

inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;
        int j;
        j= 200+random(150); 
        create_family("ÏÝ¿ÕÉ½ÎÞµ×¶´", 3, "µÜ×Ó"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("kugu-blade", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("qixiu-jian",j+random(15));
        me->set_skill("lingfu-steps", j+random(15));
        me->set_skill("yaofa", j+random(15));
        me->set_skill("huntian-qigong", j+random(15));
        me->set_skill("yinfeng-zhua", j+random(15));

        me->map_skill("force", "huntian-qigong");
        me->map_skill("blade", "kugu-blade");
        me->map_skill("sword","qixiu-jian");
        me->map_skill("parry", "kugu-blade");
        me->map_skill("spells", "yaofa");
        me->map_skill("dodge", "lingfu-steps");
        me->map_skill("unarmed", "yinfeng-zhua");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"blade", "diyu" :),
        (: perform_action,"blade", "pozhan" :),
        (: perform_action,"blade", "sword" :),
        }) );

        weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
       
        command("wield all");
}
