inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("Àî°×", ({"li bai", "li"}));
        set("long", "´óÊ«ÈËÀî°×£¬Çå¸ßÆ®Òİ£¬½£ÊõÍ¨Éñ¡£\n");
        set("gender","ÄĞĞÔ");
	set("title", "Ê«ÏÉ");
	set("class", "scholar");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",100000);
        set("attitude","heroism");
        set("chat_chance",20);
        set("chat_msg", ({
        "Àî°×µÍÉù³¤Ò÷µÀ£ºÎ£Â¥¸ß°Ù³ß£¬ÊÖ¿ÉÕªĞÇ³½¡£\n",
        "Àî°×µÍÒ÷µÀ£º¶øÀ´ËÄÍò°ËÇ§Ëê£¬²»ÓëÇØººÍ¨ÈËÑÌ¡£\n",
        "Àî°×¹Ä¸¹¶ø¸è£º»ÓÊÖ×Ô×ÈÈ¥£¬ÏôÏô°àÂíÃù¡£\n",

"Àî°×»÷½Ú¶ø¸è£ºÕÔ¿ÍçÏºşÓ§£¬Îâ¹³ËªÑ©Ã÷¡£Òø°°ÕÕ°×Âí£¬ìªí³ÈçÁ÷ĞÇ¡£\n",
        (: do_drink :),
        "Àî°×µÍÒ÷µÀ£º·òÌìµØÕß£¬ÍòÎïÖ®ÄæÂÃ¡£¹âÒõÕß£¬°Ù´úÖ®¹ı¿Í¡£\n",

"Àî°×»÷½Ú¶ø¸è£º½Å×ÅĞ»¹«åì£¬ÉíµÇÇàÔÆÌİ¡£°ë±Ú¼ûº£ÈÕ£¬¿ÕÖĞÎÅÌì¼¦¡£\n",
        "Àî°×Ò÷µÀ£º¹Â·«Ô¶Ó°±Ì¿Õ¾¡£¬Î¨¼û³¤½­Ìì¼ÊÁ÷¡£\n",
        "Àî°×ÀÊÉùÒ÷µÀ£ºÊñµÀÖ®ÄÑ£¬ÄÑÓÚÉÏÇàÌì£¬²àÉíÎ÷Íû³¤×Éàµ¡£\n",
        (: do_drink :),
        "Àî°×µÍÉù³¤Ò÷£ººìÑÕÆúĞùÃá£¬°×Ê×ÎÔËÉÔÆ¡£\n",
        "Àî°××íÌ¬±ÏÂ¶£¬ÀÊÉù³¤Ò÷£º×í¿´·çÂäÃ±£¬Îè°®ÔÂÁ÷ÈË¡£\n",
        "Àî°×³¤Ò÷µÀ£ºÒô³¾¾ø£¬Î÷·ç²ĞÕÕ£¬ºº¼ÒÁêãÚ¡£\n",
	(: random_move :)
        }));

        set("chat_chance", 10);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("literate", 120);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
	carry_object("/d/obj/book/poem");
        add_money("silver", 40);
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say ¾Æ£®£®£®¸øÎÒ¾Æ£®£®£®");
    }
    return;
}

int accept_object(object who, object ob)
{	object m;
	m=new("/d/obj/book/jianpu.c");
    if ((string)ob->query("liquid/type")=="alcohol")
    {
        if ((int)ob->query("liquid/remaining") == 0)
        {
            command("shake");
            command("say ¿ÕµÄÎÒ²»Òª£®£®£®");
            return notify_fail("ºÃÏóÀî°×²»ÊÇÊÕÆÆÀÃµÄ£¬²»Òª¿ÕÆ¿×Ó¡£\n");
        }
        else
                if ( (string)ob->name()=="Å£Æ¤¾Æ´ü" )
                {
                        command ("frown");
                        command ("say Õâ¾Æ»¹ÊÇÄúÁô×Å×Ô¼ººÈ°É¡£");
                        return
notify_fail("ºÃÏóÀî°×¿´²»ÆğÄã¸øËûµÄ¾Æ¡£\n");
                }
                else
                {
                        command("smile");
                        command("say ¶àĞ»!");
			if ((int)who->query_temp("mark/Àî°×") < 1){
			who->set_temp("mark/Àî°×", 1 ); 
			}
                        if(present("jian pu", this_object())) {
			return 0;
			}
                        who->add_temp("mark/Àî°×", 1 );
                        call_out("destroy", 1, ob);
                if ((int)who->query_temp("mark/Àî°×") >= 5+random(5))
                        {
command ( "whisper " + who->query("id") + 
" ÎÒ¿´ÄúÒ²ÊÇÎ»Á·¹¦Ï°ÎäµÄÈË£¬Ò²ËãÔÛÃÇÓĞÔµ£¬Õâ±¾½£Æ×¾ÍËÍ¸øÄãÄÃÈ¥ÑĞ¶Á°É¡£\n");
				m->move(who);
                                who->set_temp("mark/Àî°×", 0 );
				return 1;
                        }
                        return 1;
                }
        }
    }

void destroy(object ob)
{
        destruct(ob);
        return;
}

ÿ