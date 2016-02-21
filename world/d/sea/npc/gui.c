inherit NPC;
int give_me(object ob);

void create()
{
       set_name("¹ê°Ë¶·", ({"gui badou", "gui"}));

	set("long","º£µ×µÄ´ó²Å×Ó£¬ÒÔ²ÅÖÇ¹ıÈËÖø³Æ£¬²¢ÇÒ»á»­½ğÁú·û¡£\n");
       	set("gender", "ÄĞĞÔ");
       	set("age", 56);
        set("title", "¾üÊ¦");
        set("per", 10);
        set("max_kee", 1000);
        set("max_sen",700);
       	set("attitude", "peaceful");
       	set_skill("unarmed",100);
       	set_skill("dodge",100);
        set_skill("parry", 100);
       	set_skill("literate",100);
	set_skill("force", 100);
	set_skill("spells", 100);
        set("combat_exp", 200000);
  set("daoxing", 500000);

	set("force", 400);
	set("force_factor",20);
	set("max_force", 400);
	set("mana", 400);
	set("max_mana", 400);
	set("mana_factor", 20);
        set("inquiry", ([
                "½ğÁú·û": (: give_me :),
                "fu": (: give_me :),
        ]) );


        setup();
        add_money("gold", 1);
       carry_object("/d/gao/obj/magua")->wear();

}

int give_me(object ob)
{
        object who, me;
        who=this_player();
        me=this_object();

        if( (string)who->query("family/family_name")!="¶«º£Áú¹¬" ) {
                message_vision("$NĞ±Ğ±µØî©ÁË$nÒ»ÑÛ£¬Ëµ£º´Ë²»×ãÎªÍâÈËµÀÒ²£¡\n", me, who);
                return 1;
        }
	if ((int)me->query("number") >= 10)
		return notify_fail("¹ê°Ë¶·°ÑÊÖÒ»Éì£¬½ñÌìĞ´Ì«¶àÁË£¬Ã÷¶ù¸öÔÙËµ°É£¡\n");

                ob=new("/d/sea/obj/fu");
                ob->move(who);
		me->add("number",1);

		message_vision("$NÄÃ³öÕÅ·ûÖ½À´£¬»­³ö½ğÁú£¬µİ¸øÁË$n¡£\n", me, who);
                return 1;
}

ÿ