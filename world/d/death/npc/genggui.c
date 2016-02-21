//puti.c
inherit NPC;

void create()
{
       set_name("打更鬼", ({"dageng gui", "gui"}));
       set("gender", "男性");
       set("age", 60);
	set("long", "看起来相当的老，手里提着小锣，正在打更。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 400+random(100));
	set_skill("unarmed", 5);
	set_skill("dodge", 6);
	set_skill("parry", 4);

set("chat_chance", 8);
set("chat_msg", ({
"打更的喊到：平安无事喽！\n",
"打更的上上下下打量了你几眼。\n",
(: random_move :)
}) );


setup();

        carry_object("/d/obj/weapon/hammer/gucui")->wield();
}

