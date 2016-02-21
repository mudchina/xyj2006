// tomcat

inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j= 200+random(150);
        create_family("ÊñÉ½ÅÉ", 3, "µÜ×Ó"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("sword",j); 
        
        me->set_skill("yujianshu", j+random(15));
	me->set_skill("mindsword", j+random(15));        
        me->set_skill("spells",j+random(15));
        me->set_skill("sevensteps",j+random(15));
        me->set_skill("taoism", j+random(15));
        me->set_skill("unarmed", j+random(15));        
        me->set_skill("hunyuan-zhang", j+random(15));
        me->set_skill("zixia-shengong", j+random(15)); 

        me->map_skill("force", "zixia-shengong");
        me->map_skill("sword", "mindsword");        
        me->map_skill("parry", "mindsword");
        me->map_skill("spells", "taoism");
        me->map_skill("dodge", "sevensteps");
        me->map_skill("unarmed", "hunyuan-zhang");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "fenguang" :),
        (: cast_spell, "jianshen" :),
        }) );        
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
     
        command("wield all");
}
