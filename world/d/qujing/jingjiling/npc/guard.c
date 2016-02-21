inherit NPC;

void create()
{
        set_name("³àÉí¹íÊ¹", ({"guard"}));
        set("long", "Ò»¸öÇàÃæâ²ÑÀµÄºìÐë³àÉí¹íÊ¹¡£\n");
        set("age", 30);
	set("attitude", "heroism");
        set("gender", "ÄÐÐÔ");
        set("str", 25);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
        set("combat_exp", 100000);
  set("daoxing", 100000);

        set("force", 500);
        set("max_force", 500);
        set("mana",50);
        set("max_mana", 50);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("dodge", 60);
	set_skill("fork", 60);
	set_skill("yueya-chan", 30);
	map_skill("fork", "yueya-chan");
	map_skill("parry", "yueya-chan");
        setup();

	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}
ÿ