inherit __DIR__"guai.c";


void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        set("JQB_known",1);
        set_skill("baihua-zhang", guai_value+random(16));
	set_skill("moondance", guai_value+random(16));
	set_skill("whip", guai_value+random(16));
	set_skill("jueqingbian", guai_value+random(16));
        set("title", "天女散花");
        set("gender", "女性");
	set_skill("moonforce", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("moonshentong", guai_value+20+random(16));
	map_skill("spells", "moonshentong");
	map_skill("force", "moonforce");
	map_skill("unarmed", "baihua-zhang");
	map_skill("whip", "jueqingbian");
	map_skill("parry", "jueqingbian");
	map_skill("dodge", "moondance");
	create_family("月宫",3 , "弟子");
	set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "flower" :),
        }) );
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
	                
        carry_object("/d/obj/armor/jinjia.c")->wear();
}


