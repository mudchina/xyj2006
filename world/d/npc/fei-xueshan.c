
// tomcat

inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;
        
        int j;
        j= 200+random(150); 
        create_family("´óÑ©É½", 2, "µÜ×Ó");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("bingpo-blade", j+random(15));
        me->set_skill("xiaoyaoyou", j+random(15));
        me->set_skill("dengxian-dafa", j+random(15));
        me->set_skill("ningxie-force", j+random(15));
        me->set_skill("cuixin-zhang", j+random(15));

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
        me->map_skill("parry", "bingpo-blade");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
           (: perform_action,"blade", "yaowu" :),
            }) );    
        weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
        command("wield all");
}
