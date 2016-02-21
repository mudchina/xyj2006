inherit NPC;

void create()
{
        set_name("·¶Â«Æ½", ({"fan luping", "fan"}));
        set("age", 32);
        set("gender", "ÄÐÐÔ");
        set("long",
"Ò»¸ö¾«¾«ÊÝÊÝµÄÐ¡¸ö×Ó£¬ÔÚÁ·Ò»Ì×È­£®\n");
	set("title", "Îä¹Ý½ÌÍ·");
        set("attitude", "peaceful");

        set("combat_exp", 20000);
  set("daoxing", 5000);

        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("force", 30);
        set_skill("parry", 30);
	setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{
	return 1;
}

ÿ