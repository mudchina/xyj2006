inherit NPC;
string *first_name = ({ "赵","钱","孙","李"});
string *name_words = ({ "二","三"});
string *last_words = ({ "哥","伯","叔"});
void create()
{
	string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
	name += last_words[random(sizeof(last_words))];

        set_name(name, ({"lie hu", "hu"}));
	set("title", "猎户");
        set("long", "一个山间猎手。\n");
        set("age", 30+random(20));
	set("attitude", "heroism");
        set("gender", "男性");
        set("str", 25);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",800);
        set("max_sen", 800);
        set("combat_exp", 80000+random(30000));
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
set("inquiry", ([
"name": "乡间草民，打猎为生，说出来怕您也不知道。\n",
"here": "此地山上野兽甚多，你可要小心哪。\n",
]) );

        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}
