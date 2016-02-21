inherit NPC;

void create()
{
        set_name("³¤ÍÈÏºÆÅ", ({"xia po", "po"}));
        set("long", "Ò»¸ö±ÄÀ´±ÄÈ¥µÄÀÏÏºÆÅ¡£\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("gender", "Å®ÐÔ");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",500);
        set("max_sen", 500);
        set("combat_exp", 15000);
  set("daoxing", 10000);

        set("force", 200);
        set("max_force", 200);
        set("mana", 100);
        set("max_mana", 100);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("spells", 20);
        set_skill("dodge", 20);
	set_skill("hammer", 20);
        set("chat_msg", ({
        "³¤ÍÈÏºÆÅ±ÄÁË¼¸±Ä¡£\n",
	"³¤ÍÈÏºÆÅ×ìÀïà½à½àìàì£ºÔ­À´Ò»±Ä¾Í¿ÉÒÔ½øÈ¥¡£\n",
        (: random_move :)
}));

        setup();
	add_money("silver", random(2)+1);
        carry_object("/d/obj/cloth/skirt")->wear();
}

ÿ