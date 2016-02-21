// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
        object me=this_object();
	object weapon;

	set("title","ÆÕÍÓ¶ñÉ®");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j);
	me->set_skill("lunhui-zhang", j);
	me->set_skill("lotusmove", j);
	me->set_skill("buddhism", j);
	me->set_skill("jienan-zhi", j);
	me->set_skill("lotusforce", j);

	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");

	set("chat_chance_combat", 10+2*level);
	set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
	}) );

//    weapon=new("/d/obj/weapon/staff/budd_staff")
    weapon=new("/d/obj/weapon/staff/tiezhang");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
