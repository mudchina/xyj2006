inherit __DIR__"guai.c";


void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        
        set_skill("yinfeng-zhua", guai_value+random(16));
	set_skill("lingfu-steps", guai_value+random(16));
	set_skill("sword", guai_value+random(16));
	set_skill("qixiu-jian", guai_value+random(16));
	set_skill("huntian-qigong", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("yaofa", guai_value+20+random(16));
	map_skill("spells", "yaofa");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "yinfeng-zhua");
	map_skill("sword", "qixiu-jian");
	map_skill("parry", "qixiu-jian");
	map_skill("dodge", "lingfu-steps");
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
	                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
}


void heart_beat() {      
   if (!query_temp("zxzx") && is_fighting())
      command("perform zxzx");
      ::heart_beat();
}

