//captor.c

inherit NPC;
#include <ansi.h>
#include <auto_move.h>
int msg();

void create()
{
	mapping name;
	
	name=NAME_D->random_name("japan");
	set_name(name["name"], name["id"]);
	set("title", name["title"]);
	set("long", "传说中日本会忍术的武士。\n");
	set("age", 20+random(30));
	set("per", 15+random(10));
	set("gender", "男性");
	
        set("combat_exp", 100000+random(100000));
        set("wuxue_exp", 500000+random(500000));
        set_skill("unarmed", 100+random(100));
        set_skill("dodge", 100+random(100));
//        set_skill("renshu", 100+random(100));
        set_skill("parry", 100+random(100));
        set_skill("blade", 100+random(100));
        map_skill("dodge", "renshu");
        set("max_kee", 1000+random(1000));
        set("max_sen", 1000+random(1000));
        set("max_force", 1000+random(1000));
        set("force", 3000);
        set("force_factor", 70);
        set("mana_factor", 20);
        set("max_mana", 500+random(500));
        set("mana", 2000);

	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :),
		(: msg :),
	}));

	set("move_msg/out", "$N低头念了一句“ぴふゆつの!”，就不见了。\n");
	set("move_msg/int", "$N忽然从地上窜了出来。\n");
	set("move_msg/dis", "$N低头念了一句“ぴふゆつの!”，就不见了。\n");
	
	setup();
        carry_object("/d/obj/cloth/cloth")->wear();
        carry_object("/d/obj/weapon/blade/jindao")->wield();
	
	call_out("auto_disapper", AUTO_DEST_TIME);
	call_out("auto_move", AUTO_MOVE_TIME*3/2);
}

int msg()
{
	string *msg=({
		"ソモノソュノソォナニヌ！\n",
		"なにへぬふひみむめなに！\n",
		"なょゃすすへほゅむ！\n",
		"なへふにゃねゅそそ！\n",
		"かぅこぬ！\n",
	});		
	command("say "+msg[random(sizeof(msg))]);
	return 1;
}