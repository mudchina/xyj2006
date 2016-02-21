inherit __DIR__"guai.c";
#include <ansi.h>

void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        set_skill("jinghun-zhang", guai_value+random(16));
	set_skill("ghost-steps", guai_value+random(16));
	set_skill("sword", guai_value+random(16));
	set_skill("stick", guai_value+random(16));
	set_skill("kusang-bang", guai_value+random(16));
	set_skill("zhuihun-sword", guai_value+random(16));
	set_skill("hellfire-whip", guai_value+random(16));
	set_skill("tonsilit", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("gouhunshu", guai_value+20+random(16));
	map_skill("spells", "gouhunshu");
	map_skill("force", "tonsilit");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("sword", "zhuihun-sword");
	map_skill("stick", "kusang-bang");
	map_skill("whip", "hellfire-whip");
	map_skill("parry", "zhuihun-sword");
	map_skill("dodge", "ghost-steps");
	create_family("阎罗地府",2 , "弟子");
	set("title",HIB"幽冥炼气士"NOR);
	set("force_factor", query_skill("force")/3);
	set("mana_factor", query_skill("spells",1));
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
         (: perform_action, "whip","three" :)
               }) );
	                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/whip/wuchou")->wield();
}



