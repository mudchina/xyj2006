// jjf妖怪
//lestat 2001

inherit __DIR__"guai.c";
#include <ansi.h>

void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        
        set_skill("changquan", guai_value+random(16));
	set_skill("yanxing-steps", guai_value+random(16));
	set_skill("spear", guai_value+random(16));
	set_skill("mace", guai_value+random(16));
	set_skill("axe", guai_value+random(16));
	set_skill("force", guai_value+random(16));
	set_skill("unarmed", guai_value+random(16));
        set_skill("dodge", guai_value+random(16));
        set_skill("parry", guai_value+random(16));
        set_skill("spells", guai_value+random(16));
	set_skill("xuanyuan-archery", guai_value+random(16));
	set_skill("jinglei-mace", guai_value+random(16));
	set_skill("sanban-axe", guai_value+random(16));
	set_skill("archery", guai_value+random(16));
	set_skill("bawang-qiang", guai_value+random(16));
	set_skill("lengquan-force", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("baguazhou", guai_value+20+random(16));
	map_skill("spells", "baguazhou");
	map_skill("force", "lengquan-force");
	map_skill("unarmed", "changquan");
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "jinglei-mace");
	map_skill("mace", "jinglei-mace");
	map_skill("archery", "xuanyuan-archery");
	map_skill("axe", "sanban-axe");
	map_skill("dodge", "yanxing-steps");
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
	create_family("将军府",2 , "弟子");
	set("title",RED"浑然天成"NOR);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action,"mace", "tian" :),
        }) );                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("d/obj/weapon/mace/bamboo.c")->wield();
}

