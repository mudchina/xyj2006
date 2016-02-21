inherit __DIR__"guai.c";


void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        
        set_skill("literate", 150);
	set_skill("sword", guai_value+random(16));
	set_skill("dodge", guai_value+random(16));
	set_skill("parry", guai_value+random(16));
	set_skill("spells", guai_value+random(16));
	set_skill("force", guai_value+random(16));
	set_skill("yujianshu", guai_value+random(16));
	set_skill("taoism", guai_value+20+random(16));
	set_skill("hunyuan-zhang", guai_value+random(16));
	set_skill("zixia-shengong", guai_value+random(16));
	set_skill("sevensteps", guai_value+random(16));
	map_skill("spells", "taoism");
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "sevensteps");
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
        create_family("蜀山派",2 , "弟子");
        set("title","人面桃花");       
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
}


void heart_beat() {      
   
   if (is_fighting())
      command("cast shou");
      ::heart_beat();
}


