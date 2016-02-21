
inherit NPC;

int get_short(string rep, string arg, string *householder);
int get_long(string arg, string *householder,string short,string rep);
int save_file(string short, string llong, string *householder);

void create()
{
        set_name("ÀÏÍ·", ({"officer","oldman"}));
        set("gender", "ÄÐÐÔ");
        set("age", 100);
        set("long",
"ãþË®ºÓ±ßµÄ¾ÓÃñÖð½¥Ôö¶à£¬Òò´ËÌØ±ðÔÚ´ËÉèÁ¢·¿¹ÜËù£¬ÁÙÊ±ÓÉÒ»¸ö²»ÖªÃûµÄÀÏÍ·¸ºÔð¡££
\n");
	set("attitude", "friendly");
        set("combat_exp", 250000);
	set("per", 25);
        set_skill("dodge", 60);
	set("max_sen",600);
	set("max_gee",600);
	set("max_gin",600);
	set("force",800);
	set("max_force",800);
	set("max_mana",800);
	set("force_factor",25);
	set_skill("spells",60);
	set_skill("stick",60);
        setup();

        carry_object("/d/gao/obj/changpao")->wear();
        add_money("coin", 100);

}

void init()
{
	::init();
	add_action("do_apply", "apply");
}
       
int do_apply(string arg)
{
	object me,spouse,officer,room;
	string str, partner, *householder,laotou;
	int i,j;
	me = this_player();
	officer = present("officer", environment(me)); 
	laotou = officer->query("name");
  	if(!arg)
	return notify_fail("ÄãÒªÉêÇëÊ²Ã´£¿\n");
	if(arg != "house" )
	return notify_fail("ÄãÒªÉêÇëÊ²Ã´£¿\n");

//	if(file_name(environment(me))!="/d/changan/playerhomes/housingoffice")
//	  return notify_fail(laotou+"ÀÖºÇºÇµØËµ£º"+RANK_D->query_respect(me)
//+"ÈôÓÐÊ²Ã´ÐèÒª°ïÃ¦µÄ£¬Çëµ½±ÖÊÒÈ¥¡£\n");
	if(!(me->query("couple/id")))
	{
message_vision(laotou+"Ì¾ÁËÌ¾µÀ£º" +
RANK_D->query_respect(me)
+"¼ÈÊÇ¶ÀÉíÒ»ÈË£¬×ÔÈ»åÐÒ£×ÔÔÚ¡£ºÎ¿à×ÔÇóÊø¸¿£¿\n", officer);
        return 3;
	}
        if(file_size("/data/playerhomes/h_"+me->query("id")+".o") != -1)
        {      
                message_vision(laotou+"î©ÁË"+me->query("name")+"Ò»ÑÛ£¬Ì¾µÀ£º" +
RANK_D->query_respect(me)       
+"²»ÊÇÒÑ¾­ÓÐÁË·¿×ÓÂð£¿\n",officer,me);
        return 1;       
        }
	if((me->query("gender")) == "ÄÐÐÔ")
	{       str = "ÆÞ×Ó";
	}
        else 
	{ 	str = "ÕÉ·ò";
	}
        partner = me->query("couple/id");
        if(file_size("/data/playerhomes/h_"+partner+".o") != -1)
        {
	        message_vision(laotou+"î©ÁË"+me->query("name")+"Ò»ÑÛ£¬Ì¾µÀ£º" +
RANK_D->query_respect(me)
+"²»ÊÇÒÑ¾­ÓÐÁË·¿×ÓÂð£¿\n",officer,me);
        return 1;
	}
	if(!(spouse = present(partner, environment(me)))) {
	message_vision(laotou+"¶Ô×Å"+me->query("name")+"Ò¡ÁËÒ¡Í·µÀ£ºÁì·¿ÕâÃ´´óµÄÊÂ£¬"+
RANK_D->query_respect(me)
+"»¹ÊÇºÍÄã"+str+"Ò»ÆðÀ´µÄºÃ£¡\n", officer, me);
	return notify_fail("ÄãµÃÈÃÄã"+str+"Ò»ÆðÀ´£¡\n");}
	if(!me->query_temp("rental_paid") && !spouse->query_temp("rental_paid"))
	return notify_fail("ÊÀÉÏÖ»ÅÂÃ»ÓÐ±ãÒËµÄ·¿×ÓÅ¶¡£\n");
        message_vision(laotou+"Ð¦ÃÐÃÐµØ¶Ô$NµÀ£ºÈ¢ÆÞ¡¢Áì·¿¡¢Éú×Ó£¬ÈËÉúÈý´óÊÂÒ®£¡\n", me);
  	me->set_temp("is_applying_house",1);
//	officer->set_temp("house_applied",1);
	
        room=new("/obj/home.c");
        room->set("file_name","h_"+me->query("id"));
        room->set("home_host",({me->query("id")})+({partner}));
        room->save();

       message_vision("$NËµµÀ£º·¿×ÓÒÑ¾­½¨ºÃÁË£¬ÄúÕâ¾ÍÈ¥×°ÐÞ°É£¡\n",officer);


//	message_vision("$NÐ¦ÃÐÃÐµØ¶Ô$nµÀ£ºÈ¡ÆÞ¡¢Áì·¿¡¢Éú×Ó£¬ÈËÉúÈý´óÊÂÒ®£¡\n",officer,me);
//       message_vision("$NËµµÀ£ºÎÒÈ¥¼ì²é¼ì²é·¿×Ó£¬È¥È¥¾ÍÀ´¡£" +
//RANK_D->query_respect(me)+
//"ÔÚÕâ¶ùÉÔ´ýÆ¬¿Ì£¬¿É±ð×ß°¡£¡\n",officer);
//        officer->move(filename);
        return 1;
        }

int accept_object(object who, object ob)
{
//	if(file_name(environment(who))!="/d/changan/playerhomes/housingoffice")
//	{
//	command("say "+RANK_D->query_respect(who)
//+"ÄÄÄÜÕâÃ´¿ÍÆø¡£\n");
//	return 0;
//	}
//	if(query_temp("house_applied"))
//	{
//	command("say ±ð¼±£¬Ç°ÃæÓÐÈËµÈ×ÅÁË¡£\n");
//	return 0;
//	}
	if(!ob->query("money_id"))
	return 0;
	if (ob->value()< 1000000){
	if(who->query_temp("is_applying_house"))
	command("say "+RANK_D->query_respect(who)
+"³öÊÖÕâÃ´´ó·½¡£¸®ÉÏ±£×¼¸»ÀöÌÃ»Ê¡£\n");
	else
	command("say "+RANK_D->query_respect(who)
+"ÕâÃ´¿ÍÆø£¬ÎÒÕâ¾Í¸øÄú°ì¡£\n");
	}
	else{ 
        if(who->query_temp("is_applying_house"))
        command("say "+RANK_D->query_respect(who)
+"³öÊÖÕâÃ´´ó·½¡£¸®ÉÏ±£×¼¸»ÀöÌÃ»Ê¡£\n");
	else{
	 command("say "+RANK_D->query_respect(who)
+"ÈôÊÇÏëÉêÇë·¿×Ó£¬¾¡¹ÜËµ¡£\n");
	who->set_temp("rental_paid", 1);
	}}	
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);
                return 1;
       
}
	
	
	
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

