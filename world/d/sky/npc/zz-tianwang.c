// tianwang.c

inherit NPC;
string send_me(object me);
void create()
{
        set_name("Ä§ÀñÇà", ({ "zengzhang tianwang", "zz", "tianwang" }) );
        set("gender", "ÄĞĞÔ" );
	set("long",
		"Ôö³¤ÌìÍõÎªËÄ´óÌìÍõÖ®Ê×, Éí¸ß¶şÕÉËÄ³ß, ÉÆÓÃÒ»¸Ë³¤Ç¹, \n"
		"Ç¹·¨µÇ·åÔì¼«, ¸üÓĞÃÜ´«¡¸ÇàÔÆ±¦½£¡¹, ¡¸µØ£¬Ë®£¬»ğ£¬·ç¡¹\n"
		"ËÄÊ½Ò»³ö, ´óÂŞ½ğÏÉÒ²ÄÑÌÓ¡£\n"
	);
	set("age",50);
	set("title", "Ôö³¤ÌìÍõ");
	set("attitude", "peaceful");
	set("str",40);
	set("int",30);
	set("max_kee",1100);
	set("kee",1100);
	set("max_sen",1100);
	set("sen",1100);
	set("combat_exp",1000000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 80);
	set("mana_factor",80);
	
        set("eff_dx", 450000);
        set("nkgain", 500);

	set_skill("unarmed",150);
	set_skill("yingzhaogong", 150);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("spear",150);
	set_skill("bawang-qiang",150);
	set_skill("force",150);
	set_skill("spells", 150);
	set_skill("moshenbu", 150);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "ÔÚÏÂÔö³¤ÌìÍõÄ§ÀñÇà£¬·îÊ¥ÚÍ°ÑÊØÄÏÌìÃÅ¡£",
		"here" : "ÕâÀï¾ÍÊÇÄÏÌìÃÅ, ÈëÄÚ¾ÍÊÇÌì½çÁË¡£",
		"»ØÈ¥": (: send_me :),
		"back": (: send_me:),
	]) );

	setup();
	carry_object("/d/obj/fabao/qingyun-baojian");
	carry_object("/d/obj/weapon/spear/jinqiang")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

string send_me(object me)
{
        me=this_player();
	        if( me->is_fighting() )
		return ("¸ÕÀ´¾ÍÈÇÂé·³£¬¹í²ÅÒªÀíÄã£¡\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
		return ("Ã¦ÍêÔÙËµ°É¡£¡£¡£\n");

	message_vision("Ôö³¤ÌìÍõ¹ş¹ş´óĞ¦£¬¶Ô$NËµµÀ£º±¾ÍõÕâ¾ÍËÍÄã»ØÈ¥£¡\n", me);
	message_vision("Ôö³¤ÌìÍõ·ÉÆğÒ»½Å°Ñ$NÌßÁËÏÂÈ¥¡£¡£¡£\n", me);
        me->move("/d/changan/nbridge");
	tell_room( environment(me), "¡¸¹¾ßË¡¹Ò»Éù£¬´ÓÌìÉÏµôÏÂ¸öÈËÀ´£¡\n", ({me}));
	write("Äã´ÓÌìÉÏË¤ÁËÏÂÀ´£¬¸ãÁË¸ö±ÇÇàÁ³Ö×£¡\n");
	return ("ÀÏ·ò½ÅÕıÑ÷Ñ÷¡£¡£¡£\n");
}

ÿ