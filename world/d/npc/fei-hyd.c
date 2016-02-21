//tomcat




inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j= 200+random(150);  
        create_family("»ðÔÆ¶´", 3, "µÜ×Ó"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("spear", j+random(15));
        me->set_skill("huoyun-qiang", j+random(15));
        me->set_skill("moyun-shou",j+random(15));
        me->set_skill("moshenbu",j+random(15));
        me->set_skill("huomoforce", j+random(15));
        me->set_skill("pingtian-dafa", j+random(15));
        me->set_skill("dali-bang", j+random(15));
        me->set_skill("stick", j+random(15));

        me->map_skill("force", "huomoforce");
        me->map_skill("spear", "huoyun-qiang");
        me->map_skill("stick","dali-bang");
        me->map_skill("parry", "dali-bang");
        me->map_skill("spells", "pingtian-dafa");
        me->map_skill("dodge", "moshenbu");
        me->map_skill("unarmed", "moyun-shou");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: cast_spell, "sanmei" :),
        }) );

        weapon=new("/d/obj/weapon/stick/xiangmo");
        weapon->move(me);
        command("wield all");
}
