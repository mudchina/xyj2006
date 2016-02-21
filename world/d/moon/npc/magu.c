//mugu.c

inherit NPC;
string ask_for_leave();

void create()
{
        set_name("Âé¹Ã", ({"magu"}));
        set("gender", "Å®ĞÔ" );
        set("age", 35);
        set("title","ÔÂ¹¬¹Ü¼Ò");
        set("long", "Âé¹ÃÔÚÔÂ¹¬¿ÉÊÇÀïÀïÍâÍâÒ»°ÑÊÖ¡£\n");
        set("combat_exp", 100);
  set("daoxing", 5000);

        set("attitude", "peaceful");
        set("per", 15);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        set("inquiry", ([
		"ÍÑÀë" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
		]) );
	setup();
        carry_object("/d/ourhome/obj/pink_cloth")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "ÔÂ¹¬" ) {
		command("say Äã¼ÈÊÇÖ´ÒâÏÂÉ½£¬ÀÏÉíÈ´ÓĞ¼¸¾ä»°Ëµ¡£");
		me->set_temp("betray", 1);
		return ("ÍÑÀëÊ¦ÃÅÒªĞèÒªÓĞÒ»¶¨³Í·££¬Äã¿ÉÔ¸Òâ(agree)£¿");
	}

	return ("ÀÏÉí²»Öª¡£\n");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray") &&
                  this_player()->query("family/family_name")=="ÔÂ¹¬") {
		message_vision("$N´ğµÀ£ºµÜ×ÓÔ¸Òâ¡£\n\n", this_player());
		command("say ¼ÈÊÇÄãÓëÔÂ¹¬ÎŞÔµ£¬Äã±ãÏÂÉ½È¥°É£¡");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/moon", 1);
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
		if( this_player()->query_skill("moonshentong") )
		    this_player()->delete_skill("moonshentong");
		if( this_player()->query_skill("snowsword") )
	            this_player()->delete_skill("snowsword");

		
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
		this_player()->set_temp("betray", 0);
		this_player()->save();
		command("say ½­ºş·ç²¨£¬ÉÆ¶ñÎŞĞÎ£¬ºÃ×ÔÎªÖ®¡£¡£¡£\n");
		return 1;
	}
}

ÿ
