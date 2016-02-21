// bula and mon@xyj

inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
        object me=this_object();
	object weapon;

        set("title",YEL"再堕轮回"NOR);
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j+random(15));
	me->set_skill("lunhui-zhang", j+random(15));
	me->set_skill("lotusmove", j+random(15));
	me->set_skill("buddhism", j+random(15));
	me->set_skill("jienan-zhi", j+random(15));
	me->set_skill("lotusforce", j+random(15));

	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");
        create_family("南海普陀山", 3, "弟子");
        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
//(: perform_action,"staff", "chaodu" :),
        (: cast_spell, "lianhua" :),
	}) );

	weapon=new("/d/obj/weapon/staff/budd_staff");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
