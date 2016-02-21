//huanhua.c
//hehe, this npc is interesting:D...weiqi, 97.09.15

inherit NPC;
void create()
{
	set_name("ä½»¨", ({"huan hua", "huanhua", "hua"}));
	set("gender", "Å®ÐÔ" );
	set("age", 16);
	set("long", "Ñ©É½ÃÅÏÂÅ®µÜ×Ó¡£\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 30000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 4, "µÜ×Ó");
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("blade", 30);
	set_skill("bingpo-blade", 30);
	set_skill("xiaoyaoyou", 30);
	set_skill("force", 30);   
	set_skill("ningxie-force", 30);
	map_skill("force", "ningxie-force");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");


	set("per", 21);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);
	setup();

	set("eff_dx", -8000);
	set("nkgain", 60);

	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}
void init()
{       
        object ob=this_player();
	object me=this_object();

        ::init();

        if ( ((string)ob->query("gender")=="ÄÐÐÔ") &&
((int)ob->query("env/invisibility")  == 0) &&
((string)environment(me)->query("short")=="Å®µÜ×ÓÎÔ·¿") )
        {

                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
                command("chat* Ö»Ìýä½»¨¸ßÉù½ÐµÀ£º" + ob->query("name") + "£¬ÄãÕâ¸ö³ôÁ÷Ã¥£¡¾ÓÈ»´³µ½Å®µÜ×ÓÎÔ·¿À´ÁË£¡\n");
		command("kick " + ob->query("id"));
                break;
        }
}



ÿ
