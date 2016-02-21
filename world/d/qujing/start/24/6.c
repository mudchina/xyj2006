//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("婆竭龙王", ({"pojie longwang", "longwang"}));
       	set("gender", "男性");
       	set("age", 70);
        set("class", "dragon");
       	set("attitude", "friendly");
       	set("rank_info/respect", "老龙王");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 1500);
       	set("max_gin", 1500);
       	set("max_sen", 1500);
       	set("force", 2400);
       	set("max_force", 2400);
       	set("force_factor", 100);
       	set("max_mana", 2000);
       	set("mana", 2000);
       	set("mana_factor", 100);
       	set("combat_exp", 1400000);
        set("daoxing", 1000000);

       	set_skill("dodge", 180);
       	set_skill("parry", 180);
        set_skill("dragonfight", 180);
        set_skill("spells", 180);
        set_skill("seashentong", 180);
        set_skill("dragonstep", 180);
	set_skill("unarmed", 180);
        map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("unarmed", "dragonfight");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "roar" :),
                (: exert_function, "zhenshen" :),
                (: exert_function, "recover" :),
                (: cast_spell, "water" :),
        }) );



	setup();
	carry_object("/d/sea/obj/longpao")->wear();
}

