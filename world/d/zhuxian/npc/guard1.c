inherit NPC;

void create()
{

        set_name("守卫", ({ "guard" }) );
        set("race", "人类");
        set("age", 3000);
        set("str", 20);
        set("cor", 30);
        set("max_force", 3000);
        set("mana", 4000);
        set("force", 6000);
        set("max_mana", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 1000000+random(1000000));
  	set("daoxing", 5000000);

    set_skill("dodge", 160);
    set_skill("unarmed", 100);
    set_skill("parry", 160);
    set_skill("moshenbu", 160);
    set_skill("force", 160);
    set_skill("wuxiangforce", 160);
    set_skill("sword", 200);
    set_skill("dugu-jiujian", 200);
    set_skill("dao", 200);
    set_skill("spells", 200);
       map_skill("force", "wuxiangforce");
       map_skill("parry", "dugu-jiujian");
       map_skill("sword", "dugu-jiujian");
       map_skill("dodge", "moshenbu");
       map_skill("spells", "dao");
         set("chat_chance_combat", 30);
         set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "dingshen" :)
       }));
        set_temp("apply/armor", 80);
        set_temp("apply/damage",80);
        set_temp("apply/armor_vs_force",300);
        set_weight(1000000);
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}


void init()
{
        ::init();
  	add_action("do_cast", "cast");
  	add_action("do_exert", "exert");
  	add_action("do_perform", "perform");
  	add_action("do_bian", "bian");
  	add_action("do_ji","ji");

}

int do_cast(string arg)
{
        object who = this_player();
        object me = this_object(); 
	message_vision("$N张开嘴，结结吧吧地念了几声咒语。\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who); 
        return 1;
}        

int do_exert(string arg)
{               
        object who = this_player();
        object me = this_object();
	message_vision("$N鬼鬼祟祟地一运气。\n",who);
        message_vision("$N对$n摇了摇头。\n", me, who); 
        return 1;
}

int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
	message_vision("$N脸色不大对，好象动了杀机！\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who);  
        return 1;
} 

int do_ji(string arg)
{
        object who = this_player();
        object me = this_object();
	message_vision("$N偷偷把手伸进怀里，想用什么法宝！\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who);  
        return 1;
}
