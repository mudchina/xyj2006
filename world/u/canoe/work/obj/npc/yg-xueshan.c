inherit __DIR__"guai.c";
#include <ansi.h>

void set_skills(int max_value, int level)
{
        int guai_value;
        ::set_skills(max_value, level);
        
       	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
        set_skill("cuixin-zhang", guai_value+random(16));
	set_skill("bingpo-blade", guai_value+random(16));
	set_skill("blade", guai_value+random(16));
	set_skill("sword", guai_value+random(16));
	set_skill("unarmed", guai_value+random(16));
	set_skill("xiaoyaoyou", guai_value+random(16));
	set_skill("ningxie-force", guai_value+random(16));
	set_skill("literate", 180);
	set_skill("dengxian-dafa", guai_value+20+random(16));
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("blade", "bingpo-blade");
	map_skill("parry", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	create_family("´óÑ©É½",2 , "µÜ×Ó");
        set("title",HIY"Ô¡»ð·ï»Ë"NOR);
	set("force_factor", query_skill("force")/2);
	set("mana_factor", query_skill("spells",1));
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
         (: cast_spell, "niepan" :),
               }) );

	                
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/obj/weapon/blade/caidao")->wield();
}


