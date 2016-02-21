// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/baoxianfeng.c

inherit NPC;
void create()
{
	set_name("豹先锋", ({"bao xianfeng", "bao", "xianfeng"}));
	set("gender", "男性" );
	set("age", 43);
	set("per", 112);//no rongmao description.
	set("str", 50);
	set("long", "黄风大王部下的前路先锋，是黄风大王最得力的助手。\n精明干练，和虎先锋一同,是黄风大王的左右手之一\n");
	set("class", "yaomo");
	set("combat_exp", 800000);
	set("attitude", "peaceful");
	set_skill("unarmed", 130);
	set_skill("cuixin-zhang", 70);
	set_skill("dodge", 60);
	set_skill("xiaoyaoyou", 70);
	set_skill("parry", 120);
	set_skill("force", 90);   
	set_skill("ningxie-force", 80);
	set_skill("literate", 70);
	set_skill("spells", 90);
	set_skill("dengxian-dafa", 80);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill ("parry","cuixin-zhang");

	set("max_kee", 1200);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 800);
	set("max_mana", 400);	
	set("force_factor", 60);
	set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

	setup();
	carry_object("/d/qujing/huangfeng/obj/baopi")->wear();
}
