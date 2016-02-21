//sgzl

inherit NPC;

void create()
{
        set_name("±À½«¾ü", ({"beng jiangjun","beng","monkey"}));
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
                "name" : "ÎÒ¾ÍÊÇ»¨¹ûÉ½Ë®Á±¶´´ó½«±À½«¾ü¡£\n",
                "here" : "Õâ¾ÍÊÇ»¨¹ûÉ½¡£\n", 
                "´óÍõ" : "ºÙ£¡ÎÒ¼Ò´óÍõ¾ÍÊÇ»¨¹ûÉ½Ë®Á±¶´¶´Ö÷¡£\n", 
                "weapon" : "ÎÒÃÇ»¨¹ûÉ½ÕıÈ±ÕâÍæÒÕ£¬ÒªÄÜ¸ãµãÀ´¶àºÃ£¡\n", 
                "bingqi" : "ÎÒÃÇ»¨¹ûÉ½ÕıÈ±ÕâÍæÒÕ£¬ÒªÄÜ¸ãµãÀ´¶àºÃ£¡\n", 
                "±øÆ÷" : "ÎÒÃÇ»¨¹ûÉ½ÕıÈ±ÕâÍæÒÕ£¬ÒªÄÜ¸ãµãÀ´¶àºÃ£¡\n", 
	 ]) );

        set("chat_msg", ({
	    "±À½«¾üËµµÀ£ºÒªÏëÊØÎÀÎÒ»¨¹ûÉ½£¬¾ÍĞë²ÙÁ·±øÂí¡£\n",	
            "±À½«¾ü×ÔÑÔ×ÔÓïµÄËµ£ºÎÒµÈĞëµÃĞ©·æÀû½£êª²ÅÄÜµÖÓùÀ´·¸Ö®µĞ¡£\n",
            "±À½«¾üµÍÍ·ËµµÀ£ºµ½ÄÄÀï²ÅÄÜ¸ãĞ©±øÆ÷À´ÄØ£¿\n",
        }) );
}

int accept_object(object who, object ob)
{
	object me=this_object();

        if ((string)ob->query("id")!="bing qi") 
          {
           command("say ÕâÍæÒÕÓĞÊ²Ã´ÓÃ£¿");
           message_vision ("\n$NË³ÊÖ°Ñ"+ ob->query("name")+ "ÈÓÁË¡£\n",me);
           return 1;
           }
        else if (who->query("dntg/donghai")=="begin" || who->query("dntg/donghai")=="allow" 
            || who->query("dntg/donghai")=="done")
          {
          command("say ±øÆ÷ÒÑ¾­¹»ÓÃÁË£¬²»ÀÍ´óÍõ²ÙĞÄÁË¡£\n");
          return 1;
          }
/*
        else if (who->query("dntg/huaguo")!="done")
          {
          message_vision ("\n$NµÀ£º£¢Äú²»ÊÇÎÒÃÇ»¨¹ûÉ½µÄÈË£¬¸øÎÒÕâ¸öÊÇÊ²Ã´ÒâË¼£¿£¢\n",me);
          return 1;
          }
*/
        else if (random(10) != 1)
	  {
          message_vision ("\n$NĞË·ÜµÄ½ĞµÀ£ºÌ«ºÃÁË£¡ÒªÊÇÔÙ¶àÒ»µã¶ù¾Í¸üºÃÁË¡£\n",me);
          return 1;
          }
        else 
          {
          command("jump");
          command("say ´óÍõ£¬ÎÒÃÇµÄ±øÆ÷ÊÇ¹»ÓÃÁË£¬Äú×Ô¼ºÒ²ÌôÒ»Ñù³ÆÊÖµÄ¼Ò»ï°É£¡\n");
          who->set("dntg/donghai","begin");
          return 1;
          }


}


ÿ
