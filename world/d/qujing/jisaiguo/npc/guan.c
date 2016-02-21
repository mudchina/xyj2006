inherit NPC;

void create()
{
       set_name("黄门官", ({"huangmen guan", "guan"}));
       set("gender", "男性");
       set("age", 30);
        set("long", "一个身高胸阔的殿前武士，正走来走去巡视着。\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 18);
	set("str", 25);
       set("combat_exp", 105000);
        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 75);
        set_skill("parry", 75);
	set_skill("force", 75);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 10);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 30);
        set("mana", 30);
	set_weight(300000);
setup();
	carry_object("/d/obj/armor/tongjia")->wear();
        carry_object("/d/qujing/baoxiang/obj/wandao")->wield();
}

void die()
{
	object ob;
        if( environment() ) {
        message("sound", "\n黄门官大叫：有刺客，快来保护皇上！\n", environment());
	seteuid(getuid());
        if (!objectp(present("guan 2", environment(this_object())))){
	if( ob=new("/d/qujing/jisaiguo/npc/guan"))
        message("sound", "\n几个黄门官从台下跑了上来。\n", environment());
		ob->move("/d/qujing/jisaiguo/yunqi");
        	}
	}
	::die();
}

