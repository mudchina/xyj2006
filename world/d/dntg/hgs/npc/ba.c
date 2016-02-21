//sgzl

inherit NPC;

void create()
{
        set_name("°Å½«¾ü", ({"ba jiangjun","ba","monkey"}));
        set("title","»¨¹ûÉ½´ó½«");
        set("gender", "ÄĞĞÔ" );
        set("age", 35);
        set("class","taoist");
        set("long", "Ò»Ö»³ÉÁË¾«µÄÍ¨±³Ô³¡£\n");
        set("combat_exp", 60000);
  set("daoxing", 30000);

        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("spells", 60);

        set("max_kee", 450);
        set("max_gin", 450);
        set("max_sen", 450);

        set("max_force", 600);
        set("force", 600);
        set("force_factor", 30);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);
        setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "ÎÒ¾ÍÊÇ»¨¹ûÉ½Ë®Á±¶´´ó½«°Å½«¾ü¡£\n",
                "here" : "Õâ¾ÍÊÇ»¨¹ûÉ½¡£\n", 
                "´óÍõ" : "ºÙ£¡ÎÒ¼Ò´óÍõ¾ÍÊÇ»¨¹ûÉ½Ë®Á±¶´¶´Ö÷¡£\n",
                "weapon" : "´ó¼ÒµÄ±øÆ÷£¬¿ÉÈ¥°ÁÀ´¹úÍµĞ©£¬ÎÒ¼Ò´óÍõµÄ±øÆ÷Âï£¬¿´À´ÒªÕÒĞ©À«ÆøµÄÁÚ¾ÓÌÖÁË¡£\n", 
                "±øÆ÷" : "´ó¼ÒµÄ±øÆ÷£¬¿ÉÈ¥°ÁÀ´¹úÍµĞ©£¬ÎÒ¼Ò´óÍõµÄ±øÆ÷Âï£¬¿´À´ÒªÕÒĞ©À«ÆøµÄÁÚ¾ÓÌÖÁË¡£\n", 
 
	 ]) );

        set("chat_msg", ({
	    "°Å½«¾üËµµÀ£ºÎÒ¼Ò´óÍõÉñÓÂÒì³££¬ĞëÓÃÉÏºÃµÄ±øÆ÷¡£\n",	
            "°Å½«¾ü×ÔÑÔ×ÔÓïµÄËµ£ºÎÒµ¹ÖªµÀ¸öµØ·½¿É¸ãĞ©±øÆ÷À´¡£\n",
        }) );
}

ÿ