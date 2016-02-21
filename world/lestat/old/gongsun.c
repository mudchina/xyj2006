//weiqi...97/12/11

inherit NPC;

string apply_dancer(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();

void create()
{
	set_name("¹«Ëï´óÄï", ({"gongsun daniang", "gongsun", "daniang"}));
	set("age", 32);
	set("gender", "Å®ĞÔ");
	set("per", 20);
	set("long", "³¤°²³ÇÄÚÉÔÓĞÃûÍûµÄ£¬²»ÖªµÀ¹«Ëï´óÄïµÄÈË¿ÖÅÂÃ»¼¸¸ö¡£\nÌØ±ğÊÇÄÇĞ©ÎÄÈËÉ§¿Í£¬¸ú¹«Ëï´óÄï²»Êì¼òÖ±¾ÍÊÇÃ»Ãæ×Ó¡£\n");
    set("title", "½£Ê¥");
	set("attitude", "friendly");

	set("combat_exp", 40000);
  set("daoxing", 6000000);

    set("max_force", 4000);
    set("force", 8000);
    set("force_factor", 200);
    set_skill("unarmed", 260);
    set_skill("dodge", 290);
    set_skill("binfen-steps", 320);
    set_skill("parry", 260);
    set_skill("literate", 290);
    set_skill("sword",390);
    set_skill("daya-jian", 390);
	map_skill("dodge", "moondance");
	map_skill("sword", "snowsword");

	set("inquiry", ([
		"name" : "ÎûÎû...Á¬ÀÏÄïÎÒ¹«Ëï´óÄïÄã¶¼²»ÖªµÀ...\n",
		"here" : "ºÙºÙ...ÌìÏÂÃÀ¾°²»Ê¤Êı£¬³¤°²´Ë´¦×î·±»ª¡£\n",
		"¼ËÔº" : "´óµ¨£¡´ËÄËÌì×Ó½ÅÏÂ£¬¾¹¸Ò³ö´ËÉË·ç°ÜË×Ö®ÑÔ£¡\n",
		"¼ËÅ®" : "´óµ¨£¡´ËÄËÌì×Ó½ÅÏÂ£¬¾¹¸Ò³ö´ËÉË·ç°ÜË×Ö®ÑÔ£¡\n",
		"æÎ¼Ë" : "´óµ¨£¡´ËÄËÌì×Ó½ÅÏÂ£¬¾¹¸Ò³ö´ËÉË·ç°ÜË×Ö®ÑÔ£¡\n",
		"ÇàÂ¥" : "´óµ¨£¡´ËÄËÌì×Ó½ÅÏÂ£¬¾¹¸Ò³ö´ËÉË·ç°ÜË×Ö®ÑÔ£¡\n",
		"Îè¼Ë" : (: apply_dancer :),
		"ÎèÅ®" : (: apply_dancer :),
		"¸è¼Ë" : (: apply_dancer :),
		"¸èÅ®" : (: apply_dancer :),
		"leave" : (: answer_leaving :),
		"Àë¿ª" : (: answer_leaving :),
	]) );

	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
	add_money("silver", 200);
}

void do_something()
{
	command(sprintf("bet %d silver", 1+random(5)));
	if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
	call_out ("do_something", 120);	
}

string apply_dancer(object me)
{
	me=this_player();
	if( (string)me->query("gender") == "ÄĞĞÔ" ) 
	{
		return "Õâ¾ÍÒª¿´¸óÏÂµÄ±¾ÊÂÁË£¬ÎÒ¿É°ï²»ÉÏ¶àÉÙÃ¦¡£\n";
	}
	else
	{
		if( (string)me->query("class") == "dancer" )
			return "ºÃºÃ¸É°É£¬ÒÔºó²»³î¼Ş²»ÉÏºÃÈË¼Ò¡£\n";

		if( (int)me->query("age") >= 30 )
			return "ËêÔÂ²»ÈÄÈË£¬¹ÃÄï»¹ÊÇÁíÑ°ËüÂ·°É¡£\n";

		message_vision("¹«Ëï´óÄï¿´ÁË$NÒ»ÑÛÌ¾µÀ£ºÕâÍë·¹¿É²»ÊÇÈİÒ×³ÔµÄ¡£\n", me);	
		me->set_temp("dancer_applied", 1);
		return "¹ÃÄï¹ûÕæÊÇÏÂÁË¾öĞÄ£¿(yes)\n";
	}
}

string answer_leaving(object me)
{
	me=this_player();
	if( (string)me->query("gender") == "ÄĞĞÔ" ) 
	{
		return "¿ì¹ö£¬¹öµÃÔ¶Ô¶µÄ£¡ÀÏÄïÕâµØ·½»¹ÅÂÃ»ÈËÀ´Âğ£¿\n";
	}
	else
	{
		if( (string)me->query("class") == "dancer" )
			return "¼ÈÈë´ËÃÅ£¬´ó¼Ò¶¼ÖªµÀÁË£¬Àë²»Àë¿ªÓÖÓĞÊ²Ã´·Ö±ğÄØ£¿\n";
		else return "¿ì×ß°É£¬ÕâÀï±¾À´¾Í²»ÊÇÅ®ÈËÍæµÄµØ·½¡£\n";
	}
}

void init()
{
	::init();

	remove_call_out("do_something");
	call_out ("do_something", 120);		

	add_action("do_yes", "yes");
}

int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("dancer_applied")) 
	{
		message_vision("$N´ğµÀ£ºÎÒ¶¼ÏëÇå³şÁË£¡\n\n", me);
		message_vision("¹«Ëï´óÄïÅÄÁËÅÄ$NµÄÍ·µÀ£ººÃºÃ¸É£¡Ö»ÒªÄÜÅöÉÏºÃÔËÆø£¬ÈÙ»ª¸»¹ó´¹ÊÖ¿ÉµÃ£¡\n", me);
		me->delete_temp("dancer_applied");
		me->set("class", "dancer");
		return 1;
	}

	return 0;
}



ÿ
