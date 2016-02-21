//puti.c
inherit NPC;

void create()
{
       set_name("¶Ï×ã¹í", ({"duanzu gui", "gui"}));
       set("gender", "ÄĞĞÔ");
       set("age", 60);
	set("long", "Ò»¸ö¿´ÆğÀ´Ïàµ±¿ÉÁ¯µÄÀÏÍ·¡£Ë«×ãÈ´²»¼ûÁË£¬ÌÉÔÚµØÏÂ¡£\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 100);
       set("combat_exp", 6000+random(1300));
  set("daoxing", 5000);

	set_skill("unarmed", 15);
	set_skill("dodge", 15);
	set_skill("parry", 25);
	set_skill("stealing", 30);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: command, "surrender" :),
        }) );


setup();

//        carry_object("/d/diyu/obj/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/diyu/obj/tielian")->wield();
}

int accept_fight(object me)
{
        command("say ÎÒÒÑÂÙÂäµ½Õâ¸öµØ²½ÁË£¬¾Í¿ÉÁ¯¿ÉÁ¯ÎÒ°É£¡\n");
        return 0;
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "¶Ï×ã¹íËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
                + "£¬¸øµãÇ®¿ÉÁ¯¿ÉÁ¯ÎÒ°É¡£\n");
}

int accept_object(object who, object ob)
{
        int val;
        val = ob->value();

	if ( val > 0 )
		write("¶Ï×ã¹íĞ¦ÁËĞ¦£¬¶àĞ»¶àĞ»£¡\n");
	if( val > 1000) {
	command ( "whisper " + who->query("id") + " ÕâÑÂÏÂÓĞ¸öÀÏÍ·£¬Ò»Ììµ½ÍíµÄ¿Ş£¬·³ÈËµÄºÜ£®£®£®²»¹ı£®£®£®ÌıËµ£®£®£®\n");
	}
	call_out("destroy", 1, ob);
	return 1;
	
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

ÿ