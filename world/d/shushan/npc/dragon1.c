//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
// modified by vikee 2000.11

inherit NPC;

void create()
{
        set_name("ÊØÖù¾ÞÁú", ({ "dragon", "long" }));
        set("title", "");
        set("race","Ò°ÊÞ");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "Î²°Í", "¶ÇÆ¤", "ºó×¦"}) );
        set("verbs", ({ "bite", "claw"}) );

        set_skill("force", 120);
        set_skill("dragonforce", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("unarmed", 120);
        set_skill("spells", 120);
        set_skill("seashentong", 120);
        set_skill("dragonfight", 120);
        set_skill("dragonstep", 120);   

        map_skill("dodge", "dragonstep");
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        map_skill("unarmed", "dragonfight");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "shield" :),
        }) );
   add_temp("apply/damage", 50);
   add_temp("apply/armor", 50);
        setup();
}

