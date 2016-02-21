inherit NPC;
string *first_name = ({ "Çà", "»Æ", "°×", "×Ï", "Òø", "½ð"});
string *name_words = ({ "±´¹¬Å®"});

void create()
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];

       set_name(name, ({"gong nu", "nu"}));
       set("gender", "Å®ÐÔ");
       set("age", 20+random(5));
	set("long", "Ò»¸öÉíºó±³ÓÐ²Ê±´µÄ¹¬Å®¡£\n");
	set("per", 30);
	set("str", 20);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("combat_exp", 70000+random(10000));
  set("daoxing", 100000);

        set_skill("parry", 70);
        set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("force", 50);
	set_skill("spells", 50);
	set("force", 200);
	set("max_force", 200);
        set("force_factor",5);
	set("mana", 100);
	set("max_mana", 100);
	set("mana_factor", 10);
	set("max_kee", 800);
	set("max_sen", 400);
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/sea/obj/bei")->wear();
}

ÿ