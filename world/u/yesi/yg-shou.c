inherit __DIR__"guai.c";
#include <ansi.h>

void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        
        set_skill("literate", 250);
	set_skill("sword", guai_value+random(16));
	set_skill("unarmed", guai_value+random(16));
	set_skill("dodge", guai_value+random(16));
	set_skill("parry", guai_value+random(16));
	set_skill("spells", guai_value+random(16));
	set_skill("force", guai_value+random(16));
	set_skill("mindsword", guai_value+random(16));
	set_skill("taoism", guai_value+20+random(16));
	set_skill("hunyuan-zhang", guai_value+random(16));
	set_skill("zixia-shengong", guai_value+random(16));
	set_skill("sevensteps", guai_value+random(16));
	map_skill("spells", "taoism");
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "mindsword");
	map_skill("parry", "mindsword");
	map_skill("dodge", "sevensteps");
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
        create_family("蜀山派",2 , "弟子");
        set("title",HIW"纷光化影"NOR);       
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"unarmed", "fenguang" :),
        }) ); 
        carry_object("/d/obj/armor/jinjia.c")->wear();
//        carry_object("/d/obj/weapon/sword/qinghong.c")->wield();
}



