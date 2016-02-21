inherit NPC;

void create()
{
        set_name("花斑豹", ({ "jaguar" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只花斑大豹，一双眼睛正恶狠狠地瞪著你。\n");
	set("looking", "看起来威风凛凛。");
        set("attitude", "aggressive");
        set("bellicosity", 20000);
        set("str", 50);
        set("cor", 30);
        set("max_kee", 1000);
        set("max_sen", 500);
        set("limbs", ({ "头部", "身体", "前脚", "後脚"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 50);

        setup();
}
