// Rainy

inherit NPC;
void create()
{
        set_name("哮天犬", ({ "xiaotian quan", "quan", "dog"}) );
        set("race", "野兽");
        set("age",10);
        set("str", 30);
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("force",800);
        set("max_force",800);
        set("force_factor", 100);
        set("mana", 800);
        set("max_mana", 800);
        set("mana_factor", 100);
        set_skill("unarmed",200);
        set_skill("dodge",300);
        set_skill("parry",200);
        set_skill("bite", 200);
        map_skill("unarmed", "bite"); 
	map_skill("parry", "bite");
	set_temp("apply/damage", 50);


        setup();
}

void invocation(object who)
{
        object me=this_object();
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
	message_vision("$N又化为一道黑气回到豹皮锦囊中。\n", me);
        destruct(me);
}

