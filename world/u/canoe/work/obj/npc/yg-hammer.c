inherit __DIR__"guai.c";


void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        set_skill("jienan-zhi", guai_value+random(16));
	set_skill("lotusmove", guai_value+random(16));
	set_skill("staff", guai_value+random(16));
	set_skill("lunhui-zhang", guai_value+random(16));
	set_skill("lotusforce", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("buddhism", guai_value+20+random(16));
	map_skill("spells", "buddhism");
	map_skill("force", "lotusforce");
	map_skill("unarmed", "jienan-zhi");
	map_skill("staff", "lunhui-zhang");
	map_skill("parry", "lunhui-zhang");
	map_skill("dodge", "lotusmove");
	create_family("南海普陀山",3 , "弟子");
	set("class", "bonze");
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
	                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/staff/budd_staff.c")->wield();
}


void heart_beat() {      
   if (is_fighting())
      command("cast bighammer");
       ::heart_beat();
}


