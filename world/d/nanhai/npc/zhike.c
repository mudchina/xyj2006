//Cracked by Roath
// zhike.c ж╙©ми╝╨
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("ж╙©ми╝", ({ "zhike seng", "seng" }));
	set("long", "р╩н╩дЙгА╣ди╝хкё╛аЁиовэйг╢ЬвеххгИ╣дп╕хщ║ё\nкШ╦╨тПтз╢кс╜╫сг╟ю╢╡нЛЬ╫ЬоЦ╣д©мхк║ё\n");
	set("gender", "дппт");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);

	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

        create_family("до╨ёфумси╫", 4, "╣эвс");
	
	setup();
	add_money("silver", 20);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
	&& !ob->query("env/invisibility") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "ж╙©ми╝ххгИ╣ьк╣╣юё╨уБн╩" + RANK_D->query_respect(ob) + "ё╛╩╤с╜ю╢╣╫до╨ёфумси╫ё║\n");
}

Ъ
