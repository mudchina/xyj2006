inherit NPC;

void create()
{
	set_name("ÓÎ·½É®ÈË", ({"seng ren","seng"}));
	set("long", "Ò»Î»ÓÎ·½ºÍÉĞ£¬¹ÇÊİÈç²ñ£¬ÉíÉÏµÄôÂôÄ´òÂúÁË²¹¶¡¡£\n");

	set("gender", "ÄĞĞÔ");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30+random(20));
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 23);
	set("max_kee", 380);
	set("max_gin", 300);
	set("combat_exp", 10000+random(30000));
  set("daoxing", 50000);


	set("chat_chance", 40);
        set("chat_msg", ({
		(: random_move :)
	}));


	set_skill("force", 30+random(40));
	set_skill("unarmed", 30+random(40));
	set_skill("dodge", 30+random(40));
	set_skill("parry", 30+random(40));

	setup();
	carry_object("/d/obj/cloth/sengyi")->wear();

	setup();
}

ÿ