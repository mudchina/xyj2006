inherit F_VENDOR_SALE;

static int base_price=50000;

int ask_party();
int ask_money();
void create()
{
	reload("xifuhui");
        set_name("ÀÏº¦³æ", ({"xifuhui boss","boss" }));
	set("title", "Ï²¸£»áÀÏ°åÄï");
	
        set("age", 32);
        set("gender", "Å®ĞÔ");
        set("attitude", "friendly");

        set("combat_exp", 50000);
  set("daoxing", 50000);


        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
	set("per", 20);

set("inquiry", ([
"name": "ÔÚÏÂ±ãÊÇÕâÀïµÄÀÏ°å¡£\n",
"here": "ÕâÀïÊÇÏ²¸£»á£¬³ÇÖĞ´ó»§ÈË¼Ò½á»é¶¼ÒªÀ´ÕâÀï°ÚÏ²ÑçÁ¨¡£\n",
"Ñç" : (: ask_party :),
"Ï²Ñç" : (: ask_party :),
"Ï¯" : (: ask_party :),
"¾ÆÏ¯" : (: ask_party :),
"party" : (: ask_party :),
"money": (: ask_money :),
]) );
        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
}

void init()
{
    ::init();
	add_action("do_serve", "serve");
	add_action("do_finish", "finish");
	add_action("do_start", "start");
  	add_action("do_fight", "fight");
  	add_action("do_kill", "kill");
  	add_action("do_steal", "steal");
  	add_action("do_cast", "cast");
  	add_action("do_exert", "exert");
  	add_action("do_perform", "perform");
  	add_action("do_bian", "bian");
	add_action("do_fight", "fight");

}
int ask_party()
{	object me, who, wife;
	me=this_object();
	who=this_player();
//	if( !who->query("married") ) {
//		message_vision("$N¿´×Å$n´óĞ¦ÆğÀ´£ºÄã»¹Ã»½á»éÄØ£¬¿ªÊ²Ã´Ï²Ñç£¡\n", me, who);
//		return 1;
//	}
//	if( who->query("married_party") ) {
//		message_vision("$N¿´×Å$n³ÙÒÉµÄÎÊµÀ£ºÄã²»ÊÇÒÑ¾­¿ª¹ıÏ²ÑçÁËÂğ£¿\n", me, who);
//		return 1;
//	}
	if( who->query_temp("host_of_party") ) {
		message_vision("$N¶Ô$nËµ£ºÕâ²»ÊÇÕı¿ª×ÅÏ²ÑçÄØÂğ£¿\n", me, who);
		return 1;
	}
//	if( (string)who->query("gender")=="Å®ĞÔ" ) {
//		message_vision("$NÖåÁËÖåÃ¼£¬¶Ô$nËµµÀ£º»¹ÊÇ½ĞÄãµÄÕÉ·òÀ´°ìÕâ¼şÊÂ°É£¡\n", me,who);
//		return 1;
//	}
//	if( !objectp(wife=present(who->query("couple/id"), environment(who))) ) {
//		message_vision("$N¶Ô$nËµ£ºĞÂÄï×Ó¶¼Ã»À´£¬ÕâÏ²ÑçÔõÃ´¿ª£¿\n", me, who);
//		return 1;
//	}
	if( me->query_temp("ready_to_party") ) {
		message_vision("$N¶Ô$n²»ºÃÒâË¼µÄËµ£ºÎÒÕâÕı¿ª×ÅÒ»Ï¯ÄØ£¬Òª²»ÄúÃ÷¶ùÔÙÀ´°É£¡\n", me, who);
		return 1;
	}
	if( (string)environment(me)->query("short")!="Ï²¸£»á" ) {
		message_vision("$N¶Ô$nÎªÄÑµÄËµ£ºÏÖÔÚÕâÀïÒ²Ã»×¼±¸£¬ÎÒÊÇÄÑÒÔÏàÖú°¡£¡\n", me, who);
		return 1;
	}
	if( who->query_temp("ready_to_pay") ) {
		message_vision("$N¶Ô$n²»ÄÎ·³µÄËµµÀ£ºÄãÔõÃ´ÎÊ¸öÃ»Íê£¡\n", me, who);
		return 1;
	}
	if( !who->query_temp("party_paid") ) {
		message_vision("$N¶Ô$nËµ£ºÕâÒ»´ÎÏ²ÑçÂğ£¬¿ÉÒª»¨·Ñ"+
			price_string(base_price*query_price()/10)+
			"ÄØ£¡\n", me, who);
		who->set_temp("ready_to_pay", 1);
		return 1;
	}
}
int accept_object(object who, object ob)
{
	object m;
	int value;
	int price;

	value=ob->value();

	if( !who->query_temp("ready_to_pay") )
		return notify_fail(name()+"³ÙÒÉµÄ¿´×ÅÄã£¬²»ÖªµÀÄãÏë¸ÉÊ²Ã´£¡\n");

	if( !value )
		return notify_fail(name()+"Ææ¹ÖµÄ¿´×ÅÄãËµ£º¸øÎÒÕâ¸ÉÊ²Ã´£¿\n");

	price=base_price*query_price()/10;

	if( value < price )
		return notify_fail(name()+"Ëµ£ºÕâĞ©ÄÄ¹»Ñ½£¬Òª"+
			price_string(price)+"²ÅĞĞ£¡\n");
	if(!take_money(value, base_price))
	    return 0;
	this_object()->save();
	who->set_temp("host_of_party", 1);
	who->delete_temp("ready_to_pay");
	call_out("destroy", 1, ob);

	call_out("count_money", 2, who);
	call_out("start_party", 5, who);
	return 1;
}

int ask_money()
{
	object who=this_player();
	int i;
	i=(int)this_object()->query("money")+160;
	if( who->query("id")!="bula"){ 
		command("dunno");
		return 1;
	}
	command("whisper bula Õâ¸öÔÂÉúÒâ²»´í£¬µ½ÏÖÔÚ¹²×¬ÁË"
+chinese_number(i)+"Á½½ğ×ÓÁË¡£\n");
	return 1;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void count_money(object who)
{
	message_vision("\n$N°Ñ$n¸øµÄÇ®×ĞÏ¸µÄÇåµãÁËÒ»±é¡£\n\n", this_object(), who);
	message_vision("$NÍ´¿ìµÄËµ£º¿ªÏ¯£¡\n", this_object() );

}

void start_party(object who)
{
	object me=this_object();
	command("chat* "+name()+
	       "£º¸÷Î»ÀÏÒ¯Ì«Ì«ÉÙÒ¯Ğ¡½ã£¬½ñÈÕ" + who->query("name") +  
"ÔÚÏ²¸£»á´ó¿ª¾ÆÏ¯£¬»¶Ó­¸÷Î»Ç°À´Åõ³¡£¡");
	command("say ÄúÒª¿ªÊ¼(start)£¬ÎÒ±ã¿ªÏ¯¡£ÄúÒªÉÏ²Ë(serve)£¬ÎÒ¾ÍÉÏ²Ë£¬µÈÄú³Ô±¥ÁË£¬ÍæÄåÁË£¬ÔÛ¾Í½áÊø(finish)¡£");
	me->set_temp("ready_to_party", 1);
}
int do_start()
{	
	object who = this_player();
        object me = this_object();
	int i;
	object *list;
	object girla,girlb,girlc,girld,cup;
	if( !who->query_temp("host_of_party") )
		return notify_fail(name()+"¶ÔÄãËµ£ºÄãÓÖ²»ÊÇĞÂÀÉ¹Ù£¡\n");
	if( !me->query_temp("ready_to_party") )
		return notify_fail(name()+"¶ÔÄãËµ£º¿ªÊ¼Ê²Ã´Ñ½£¬ÏÖÔÚÓÖÃ»ÈË½á»é£¡\n");
	if( me->query_temp("party_start_already") )
		return notify_fail(name()+"ÉúÆøµÄ¶ÔÄãËµ£ºÕâ²»ÊÇÒÑ¾­¿ªÊ¼ÁËÂï£¡\n");

	message_vision("$N´óÉù¶Ô$nËµ£ºÀÏ°å£¬¿ªÏ¯£¡\n\n", who, me);
	message_vision("$N´óÉùº°×Å£º¿ª¡«¡«Ï¯¡«¡«à¶¡«¡«\n\n", me);
	me->set_temp("party_start_already", 1);
	me->delete_temp("ready_to_party");
	tell_room( environment(who), "ÅÔ±ßËÄ¸ößïÄÅÊÖ´óÉùµÄ´µÆğÁË»¶¿ìµÄßïÄÅ¡£\n");	

	// mon
	environment(me)->set("resource/nuerhong",1);

	list = all_inventory(environment(me));
	i = sizeof(list);
	while (i--)
	{
	  	object ob= list[i];
	 	if( cup=new("/d/obj/food/dishes/cup"))
	  	cup->move(ob);
	}
	seteuid(getuid());
	if(girla=new("/d/city/npc/girla"))	
 	girla->move(environment(me));

        seteuid(getuid());
        if(girlb=new("/d/city/npc/girlb"))
        girlb->move(environment(me));

        seteuid(getuid());
        if(girlc=new("/d/city/npc/girlc"))
        girlc->move(environment(me));

        seteuid(getuid());
        if(girld=new("/d/city/npc/girld"))
        girld->move(environment(me));

	tell_room(environment(who), "ÄÚÌÃ×ß³ö¼¸¸öÆ¯ÁÁµÄĞ¡¹ÃÄï¡£\n");
	tell_room(environment(who), "ÄãµÃµ½ÁËÒ»¸ö°×Óñ¾ÆÕµ¡£\n");
	call_out("finish_party", 500, who);
	return 1;
}
int do_serve()
{
	object me=this_object();
	object who=this_player();
	object food;
	if( !who->query_temp("host_of_party") )
		return notify_fail(name()+"¶ÔÄãÈÂµÀ£ºÖ÷ÈË»¹Ã»Ëµ»°£¬ÄãÈÂ¸öÊ²Ã´¾¢£¡\n");
	if( !me->query_temp("party_start_already") )
		return notify_fail(name()+"¶ÔÄãËµ£ºÄã»¹Ã»Ğû²¼¿ªÊ¼(start)£¬ÔõÃ´ÉÏ²ËÄØ£¿\n");
	if ( (present("food 2", environment(me))) )
		return notify_fail(name()+"¶ÔÄãËµ£ºÂıÂı³Ô£¬³ÔÍê×ÔÈ»»á¸øÄãÉÏ²Ë¡£\n");

	message_vision("$N´óÉùÈÂÈÂ×Å£ºÉÏ²Ë£¬ÉÏ²Ë£¡\n", who);

	tell_room(environment(me), "´ÓÄÚÌÃÅÜ³öËÄÎå¸öĞ¡»ï¼Æ£¬ÊÖ½ÅÂéÀûµÄ½«×ÀÉÏµÄÊ£²Ë·¹¶ËÁËÏÂÈ¥¡£\n");
	tell_room(environment(me), "Ğ¡»ï¼ÆÓÖ´ÓÄÚÌÃ³öÀ´£¬¶ËÉÏÁËÒ»×ÀĞÂµÄ¾ÆÏ¯¡£\n");
        if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
	if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
	if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
	if(food=new("/d/obj/food/dishes/food"))
        food->move(environment(me));
	return 1;
}
int do_finish()
{
	object me=this_object();
	object who=this_player();

	if( !who->query_temp("host_of_party") )
		return notify_fail(name()+"µÉÁËÄãÒ»ÑÛ£º±ğÂÒËµ»°£¡\n");

	if( !me->query_temp("party_start_already") )
		return notify_fail(name()+"µÉÁËÄãÒ»ÑÛ£º²»ÊÇÒÑ¾­½áÊøÁËÂğ£¡\n");
	message_vision("$N¶Ô$nËµµÀ£º³Ô±¥ºÈ×ã£¬¶àĞ»ÀÏ°åÕĞ´ı£¡\n", who, me);
	remove_call_out("finish_party");
	call_out("finish_party", 3, who);
	return 1;
}
void finish_party(object who)
{
	object me=this_object();
        int i;
        object *list;

	message_vision("$N´óÉùËµµÀ£ºÑçÏ¯¾Í´Ë½áÊø£¬¶àĞ»´ó¼Ò¹âÁÙ£¡\n", me);

	// mon
	environment(me)->set("resource/nuerhong",0);

	command("gongxi " + who->query("id"));

	me->delete_temp("party_start_already");
	who->delete_temp("host_of_party");
//	who->set_temp("married_party", 1);
	list=all_inventory(environment(me));
	i=sizeof(list);
	while (i--)
	{
		if(list[i]->query("id") != "ban niang")
			continue;
		else
			destruct (list[i]);
	}
}
int do_fight(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$NÁ³É«²»´ó¶Ô£¬ºÃÏó¶¯ÁËÉ±»ú£¡\n", who);
        message_vision("$N¶Ô$nÖ±Ò¡Í·£ºÕâ´óÏ²µÄÈÕ×Ó¶¯Ê²Ã´µ¶Ç¹°¡£¡\n", me, who);
        return 1;
}

int do_kill(string arg)
{
  	object who = this_player();
 	object me = this_object();

	if(!arg || present(arg,environment(me))!=me) return 0;

	message_vision("$NÁ³É«²»´ó¶Ô£¬ºÃÏó¶¯ÁËÉ±»ú£¡\n", who);
	message_vision("$N¶Ô$nÖ±Ò¡Í·£ºÕâ´óÏ²µÄÈÕ×Ó¶¯Ê²Ã´µ¶Ç¹°¡£¡\n", me, who);
	return 1;
}
int do_cast(string arg)
{
        object who = this_player();
        object me = this_object(); 
	message_vision("$NÕÅ¿ª×ì£¬½á½á°É°ÉµØÄîÁË¼¸ÉùÖäÓï¡£\n", who);
        message_vision ("$N¶Ô$nÖ±Ò¡Í·£ºÕâ´óÏ²µÄÈÕ×Ó£¬ÄãÄîÄÄÃÅ×ÓÖä°¡£¡\n", me, who);
        return 1;
}        
int do_exert(string arg)
{               
        object who = this_player();
        object me = this_object();
	message_vision("$N¹í¹íËîËîµØÒ»ÔËÆø¡£\n",who);
        message_vision("$N¶Ô$nÍÂÍÂÉàÍ·£¬Ëµ£º¸Õ³Ô¹ı·¹£¬²»ÒªÂÒÓÃÄÚ¹¦£¡\n", me, who);
        return 1;
}
int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
	message_vision("$NÁ³É«²»´ó¶Ô£¬ºÃÏó¶¯ÁËÉ±»ú£¡\n", who);
        message_vision ("$N¶Ô$nÖ±Ò¡Í·£ºÕâ´óÏ²µÄÈÕ×Ó¶¯Ê²Ã´µ¶Ç¹°¡£¡\n", me, who);  
        return 1;
}        
int do_steal(string arg)
{       
        object who = this_player();
        object me = this_object();
	message_vision("$NÉì³öÊÖ£¬ÏëÒªÍµµãÊ²Ã´¡£\n", who);
        message_vision ("$N¶Ô$nÂîµÀ£ºÔõ¿ÉËæ±ã¹âÌì»¯ÈÕÊ©µÁĞĞÇÔ£¡\n",me,who);
  	return 1;
}

int do_bian(string arg)
{
  	object who = this_player();
  	object me = this_object();
	message_vision("$N¹í¹íËîËîµØÏë±ä³ÉÊ²Ã´¶«Î÷¡£\n",who);
	message_vision("$N¶Ô$nËµ£ºÕâÊÇÏ²Ñç£¬²»¿ÉËæÒâ±ä»¯£¡\n",me,who);
        return 1;
}

ÿ
int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
        
 if((string)ob->query("name")=="ÍÅÔ²ÑçÏ¯" )
        {
         command("smile");
         command("say ÕâÎ»" + RANK_D->query_respect(me) +
"ÕæÊÇÓĞĞÄÈË£¬ÀÏÄï¾ÍÔùÒ»ÀñÎïÓèÄã¡£");
        call_out("destroy", 1, ob);
        lw->move(me);
        
        return 1;       
        }
 }
void destroy(object ob)
{
        destruct(ob);
        return;
}

