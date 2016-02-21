inherit NPC;

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王"});

void create()
{	string name;
	name=first_name[random(sizeof(first_name))];
	name += "秀才";
        set_name(name, ({"xiucai"}));
        set("age", 18+random(40));
        set("gender", "男性");
        set("long","一个看起来象秀才似的文人\n");
        set("attitude", "friendly");
        set("combat_exp", 3000);
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
		"秀才笑了笑。\n",
		"秀才皱了皱眉头。\n",
                (: random_move :)
        }));

        setup();

        carry_object("/d/gao/obj/changpao")->wear();
}

