inherit NPC;

void create()
{
        set_name("ºØÖªÕÂ", ({"he zhizhang", "he"}));
        set("age", 52);
        set("gender", "ÄÐÐÔ");
	set("int", 35);
        set("long",
"ºØÖªÕÂÊÇ¹ú×Ó¼à´óÑ§Ê¿£¬Í³¹ÜÈ«¹úÎÄÈË¿¼ÊÔ¼°Éý¼¶¡£\n");
	set("title", "¹ú×Ó¼à´óÑ§Ê¿");
        set("attitude", "friendly");
	set("class", "scholar");
        set("combat_exp", 40000);
  set("daoxing", 100000);

        set("shen_type", 1);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
	set_skill("literate", 150);
	setup();
        carry_object(__DIR__"obj/choupao")->wear();
}


ÿ