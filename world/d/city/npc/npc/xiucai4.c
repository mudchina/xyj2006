inherit NPC;
string apply_gongming(object me);

void create()
{
        set_name("ºØÖªÕÂ", ({"he zhizhang", "he", "zhizhang"}));
        set("gender", "ÄĞĞÔ");
        set("age", 55);
	set("title", "¹ú×Ó¼à´óÑ§Ê¿");
        set("str", 25);
	set("int", 30);
        set("long", "ºØÖªÕÂÊÇ¹ú×Ó¼à´óÑ§Ê¿£¬Í³¹ÜÈ«¹úÎÄÈË¿¼ÊÔ¼°Éı¼¶¡£\n");
        set("combat_exp", 30000);
  set("daoxing", 50000);

        set("attitude", "friendly");
        set("class", "scholar");
        set_skill("unarmed", 50);
        set_skill("dodge",50);
	set_skill("literate", 100);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);
	set("inquiry", ([
		"name" : "±¡ÃûºÎ×ã¹Ò³İ...ÀÏ·òºØÖªÕÂÃÉ»ÊÉÏ¶÷ÉÍ¹ú×Ó¼à´óÑ§Ê¿£¬ÊµÊÇÀ¢²»¸Òµ±¡£\n",
		"here" : "ÕâÀï±ãÊÇ¹ú×Ó¼à¡£\n",
		"¶ÁÊéÊ¶×Ö": "¶ÔÁË£¬ÄãÊÇÀ´¶ÔµØ·½ÁË£¡\n",
		"Ñ§Ï°" : "Ö»Òª×Ü¹Ü¸®ÈÏ¶¨£¬ÎÒÃÇ¾ÍÊÕ£¡\n",
		"¹¦Ãû" : (: apply_gongming :),
        ]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
int recognize_apprentice(object ob, object who)
{
/*
	object tongpai;
        if( !tongpai = present("tong pai", ob))
return notify_fail("ºØÖªÕÂĞ¦µÀ£ºÃ»ÓĞ×Ü¹Ü¸®µÄÈÏ¿É£¬ÎÒÊÇ²»¸ÒÂÒÊÕÑ§ÉúµÄ£¡\n");
	if((string)tongpai->query("player") != (string)ob->id())
return notify_fail("ºØÖªÕÂµÉÁËÄãÒ»ÑÛ£¬Ñ§ÎÄÖ®ÈËÔõ¿É×÷±×£¡£¡£¿\n");
*/  
      return 1;
}

string apply_gongming(object me)
{
        me=this_player();
        if( me->query("class") != 0 ) //means already has a class
        {
                return "¹¦Ãû¸»¹ó¶¼ÊÇ¹ıÑÛÔÆÑÌ£¬ÓÖºÎ±Ø¹ÒÔÚĞÄÉÏ£¿\n";
        }
        else
        {
                message_vision("ºØÖªÕÂËµµÀ£º¹¦Ãû¸»¹ó¶¼ÊÇ¹ıÑÛÔÆÑÌ£¬ÓÖºÎ±Ø¹ÒÔÚĞÄÉÏ£¿\n", me);
                message_vision("ºØÖªÕÂ¶Ô$NÌ¾ÁË¿ÚÆøµÀ£º¼ÈÈ»ÄãÈç´ËÈÈÖÔ...\n", me);
                me->set("class", "scholar");
                if( me->query_skill("literate", 1) < 20 )
                        return "ÒÔ¸óÏÂµÄ²ÅÊ¶£¬»¹Ö»ÄÜ´ÓÍ¯Éú×öÆğ¡£\n";
                else if( me->query_skill("literate", 1) < 100 )
                        return "ÒÔ¸óÏÂµÄ²ÅÊ¶£¬×ö¸öĞã²Å»¹ÊÇ¿ÉÒÔµÄ¡£\n";
                else    return "ÒÔ¸óÏÂµÄ²ÅÊ¶£¬×ö¸ö´óÑ§Ê¿Ã»ÎÊÌâ¡£\n";
        }
}

ÿ
