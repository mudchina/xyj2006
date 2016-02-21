inherit __DIR__"guai.c";


void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        
        set_skill("wuxing-quan", guai_value+random(16));
	set_skill("baguazhen", guai_value+random(16));
	set_skill("sword", guai_value+random(16));
	set_skill("sanqing-jian", guai_value+random(16));
	set_skill("zhenyuan-force", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("taiyi", guai_value+20+random(16));
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("parry", "sanqing-jian");
	map_skill("sword", "sanqing-jian");
	map_skill("dodge", "baguazhen");
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: perform_action, "sword","jianzhang" :)
               }) );
        
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
}




