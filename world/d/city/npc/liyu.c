inherit NPC;
string fan_me(object me);

void create()
{
        set_name("ÀîÓñÄï", ({"li yuniang", "li"}));
        set("age", 28);
        set("gender", "Å®ĞÔ");
        set("long",
"ÀîÓñÄïÊÇÔ¬Ììî¸µÄÀÏÆÅ£¬ÕıÔÚÏ´²Ë×ö·¹¡£\n");
        set("attitude", "friendly");
	set("per", 25);
        set("combat_exp", 4000);
  set("daoxing", 20000);

        set("shen_type", 1);
        set_skill("unarmed", 20);
	set_skill("parry", 20);
        set_skill("dodge", 40);
        set("inquiry", ([
"Ô¬Ììî¸": "ÆøËÀÈËÁË£¬ÕâÃ´ÍíÁËÒ²²»»Ø¼Ò³Ô·¹£¡Ò²ÕÒ²»µ½¸öÈË°Ñ·¹ËÍÈ¥£¡\n",
"ËÍ·¹": (: fan_me :),
]));

	setup();

        carry_object("/d/obj/cloth/pink_cloth")->wear();
	carry_object("/d/city/obj/fanhe");
}
string fan_me(object me)
{	object who;
	who=this_player();
	
	if(!present("fan he", me)){
	return "ÕâÌìºÚÂ·Ô¶µÄ£¬ËãÁË°É£¬¶àĞ»ÁË£¡\n";
	}
	if(present("fan he", me)){
	command("give fan to " + who->query("id"));
	return "¶àĞ»ÁË£¬¿ìÈ¥°É£¡";
	}
}
ÿ