// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/laohu.c

inherit NPC;

void create()
{
        set_name("老虎", ({ "lao hu","hu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只威风凛凛的猛虎，露出白森森的牙齿恶狠狠地瞪著你。\n");
        set("attitude", "aggressive");
	  set("bellicosity", 20000);
        set("str", 20);
        set("cor", 30);
	  set("max_kee", 1300);
	  set("max_sen", 1200);
        set("limbs", ({ "头部", "身体", "前脚", "後脚"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);

        set_temp("apply/damage", 15);
        set_temp("apply/armor", 20);
		set_skill("unarmed",100);
		set_skill("parry",100);
		set_skill("dodge",150);

        setup();
}


