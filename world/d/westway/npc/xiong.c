
inherit NPC;

void create()
{
        set_name("ÐÜÉ½¾ý", ({ "xiong shanjun", "xiong", "shanjun" }));
        set("gender", "ÄÐÐÔ");
        set("age", 35);
        set("str", 30);
	set("per", 10);
	set("long", "ÐÛºÀ¶àµ¨Á¿£¬Çá½¡º»ÉíÇû£¬ÉæË®Î¨Ð×Á¦£¬ÅÜÁÖ³ÑÅ­Íþ¡£
ÏòÀ´·û¼ªÃÎ£¬½ñ¶ÀÂ¶Ó¢×Ë£¬ÂÌÊ÷ÄÜÅÊÕÛ£¬Öªº®ÉÆÓùÊ±¡£
×¼ÁéÎ©ÏÔ´¦£¬¹Ê´ËºÅÉ½¾ý¡£\n");
        set("combat_exp", 490000);
  set("daoxing", 300000);

        set("attitude", "peaceful");
        set_skill("unarmed", 140);
        set_skill("force", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
	set_skill("parry", 140);
	set("max_kee", 1300);
	set("max_sen", 1300);
        set("force", 600); 
        set("max_force", 600);
        set("force_factor", 30);
	set("max_name", 600);
	set("mana", 600);
	set("mana_factor", 30);
	set_temp("apply/armor", 50);
        setup();
        carry_object("/d/westway/obj/pao2")->wear();
}

int accept_fight(object me)
{
        object yin=present("yin jiangjun", environment(this_object()));
        object niu=present("te chushi", environment(this_object()));

        if(yin){
                yin->kill_ob(me);
        }
        if(niu){
                niu->kill_ob(me);
        }
        kill_ob(me);
        return 1;

}
void accept_kill(object me)
{
        object yin=present("yin jiangjun", environment(this_object()));
        object niu=present("te chushi", environment(this_object()));
 
        if(yin){
                yin->kill_ob(me);
        }
        if(niu){
                niu->kill_ob(me);
        }
        return;

}

ÿ