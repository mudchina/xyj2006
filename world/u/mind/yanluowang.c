
#include <ansi.h>

//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;
int send_me();
int work_me();
string expell_me(object me);
void create()
{
       set_name("ÑÖÂÞÍõ", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "Éí´©´óºìòþÅÛ£¬Í·´÷ºÚ³ñÈí½í£®
ÃæÈç¹øµ×£¬ÐëÈô¸ÖÕë£¬Õâ¾ÍÊÇÑÖÂÞÍõ£®\n");
       set("title", "Òõ¼äÊ®ÍõÖ®");
	set("class", "youling");
       set("gender", "ÄÐÐÔ");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 50);
       set("combat_exp", 1000000);
  set("daoxing", 2000000);


	set_skill("jinghun-zhang", 150);
	set_skill("tonsillit", 100);
	set_skill("gouhunshu", 150);
       set_skill("unarmed", 150);
	set_skill("whip", 150);
	set_skill("hellfire-whip", 150);
	set_skill("sword", 150);
	set_skill("zhuihun-sword", 150);
       set_skill("dodge", 150);
	set_skill("ghost-steps", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
	set_skill("stick", 150);
	set_skill("kusang-bang", 150);

	map_skill("sword", "zhuihun-sword");
	map_skill("parry", "zhuihun-sword");
	map_skill("dodge", "ghost-steps");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("force", "tonsillit");
	map_skill("spells", "gouhunshu");

	set("nk_gain", 500);

	set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
		(: cast_spell, "gouhun" :),
		(: cast_spell, "inferno" :),
		(: cast_spell, "invocation" :),
        }) );

set("inquiry", ([
"»¹Ñô": (: expell_me :),
"leave": (: expell_me :),
//"watch":(:send_me:),
"Ê®°Ë²ãµØÓü":(: work_me :),
"18": (: work_me :),
"name": "ºß£¡Á¬ÀÏ·ò¶¼²»ÈÏµÃ£¬ÏëÀ´ÊÇ»îµÄÌ«¾ÃÁË£¡\n",
"here": "Õâ±ãÊÇÑÖÂÞµØ¸®£¬µ½Ñô¼äÒ»Ì¸£¬ºÙºÙ£¬Ã»ÈË²»ÅÂ£¡\n",
"Ñô¼ä": "ÈËËµÒõÑôÊâÍ¾£¬ÆäÊµ²»È»£¬ÒõÑô¼äÓÐÎåµãÏà½»£¬À´È¥ÏàÍ¨£¡\n",
"Îåµã": "¹þ¹þ£¬ÒªËµÖªµÀµÄÈËÈ´Ò²²»¶à£¬ÄÇ±ãÊÇÄê£¬ÔÂ£¬ÈÕ£¬Ê±ºÍ³¤°²ãþË®ÇÅ£¡\n",
]) );


create_family("ÑÖÂÞµØ¸®", 2, "ÄãºÃ");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
void attempt_apprentice(object ob, object me)
{
        if ( (string)ob->query("family/family_name")=="ÑÖÂÞµØ¸®") {
        if (((int)ob->query("combat_exp") < 50000 )) {
        command("say " + RANK_D->query_rude(ob) + "²»µàµà½ïÁ½£¬ÀÏ×ÓÃ»¿Õ½ÌÄã£¡\n");
        return;
        }
        command("grin");
        message_vision("ÑÖÂÞÍõ¶Ô$NºÙºÙµØÐ¦ÁË¼¸Éù¡£\n", ob);
	message_vision("ÑÖÂÞÍõÅÄÅÄ$NµÄ¼ç°òËµµÀ£ºÒÔºóÔÚÕâÀï¶àÓÃ¹¦£¬³ÙÔçÓÐ³öÍ·µÄÈÕ×Ó£¡\n", ob);
       command("recruit " + ob->query("id") );
        return;
        }
	message_vision("ÑÖÂÞÍõ¶Ô$NºÈµÀ£ºÄãÊÇÄÇÀïÀ´µÄÃ«Ôô£¬¸ÒÅÜµ½±¦µîÉÏÈöÒ°£¡ÓëÎÒºå³öÈ¥£¡\n", ob);
	message_vision("ÅÜ½øÀ´Á½¸öÇàÃæÐ¡¹í°Ñ$NÍÏÁË³öÈ¥¡£\n", ob);
	ob->move("/d/diyu/walk7");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}


int accept_fight(object me)
{
        command("say " + "¹þ¹þ£¡ÑÖÍõ²»½Ð£¬×Ô¼ºÉÏÃÅ£¡\n");
        return 1;
}

string expell_me(object me)
{       
	me=this_player();
        if((string)me->query("family/family_name")=="ÑÖÂÞµØ¸®") {
		message_vision("ÑÖÂÞÍõºú×Ó¶¶¶¶£¬ºÃÏñ·Ç³£ÉúÆø¡£\n", me);
                me->set_temp("betray", 1);
		message_vision("ÑÖÂÞÍõ¶Ô$NÈÂÈÂ×Å£ºÐ¡¶«Î÷£¬ÄãËµ»°ÊÇÕæÐÄ»°(true)£¿\n", me);
                add_action("do_true","true"); 
		return ("ÆøËÀÎÒÁË£¬ÆøËÀÎÒÁË£¡\n");
        }
        return ("ÎÊÊ²Ã´ÎÊ£¡×Ô¼ºÏëÈ¥£¡\n");
}
void init()
{
 //       add_action("do_true", "true");
  ::init();
}

int do_true(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ðµÀ£ºµÜ×Ó½²µÄÕæÐÄ»°£¡\n\n", this_player());
		message_vision("ÑÖÂÞÍõÌ¾ÁË¿ÚÆø£¬¼ÈÊÇÈç´Ë£¬Äã±ã»¹ÑôÈ¥°É£¡\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
		this_player()->add("betray/count", 1);
		this_player()->add("betray/hell", 1);
                this_player()->delete("family");
		this_player()->delete_skill("gouhunshu");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙÐÕ");
                this_player()->set_temp("betray", 0);
                this_player()->save();
		message_vision("ÑÖÂÞÍõÉì³öÊÖ½«$NÒ»ÍÆ£¬$N»¯×÷Ò»¹ÉÇàÑÌÏò¶«¶øÈ¥¡£¡£¡£\n", this_player());
		this_player()->move("/d/city/chenghuang");
		tell_room( environment(this_player()),"·¿ÁºÉÏàÛàÛàÂàÂ¼¸ÉùÏì£¬µôÏÂ¸öÈËÀ´£¡\n", ({this_player()}));
		this_player()->unconcious();		
                return 1;
                }
        return 0;
}


/*

int work_me()
{
	object ghost, me;
	me=this_player();
	if( (string)me->query("family/family_name")!="ÑÖÂÞµØ¸®" ) {
		message_vision("$NÐ±Ð±µÄÆ³ÁË$nÒ»ÑÛ£¬ÀäÐ¦µÀ£º¾ÍÄã£¬ºÃÐ¦ºÃÐ¦¡£¡£¡£\n", this_object(), me);
		return 1;
		}
	//for first time.
	if(!me->query("Hell_Job")) {
		call_out("start_job", 1, me);
		return 1;
	}
	if( (int)me->query("Hell_Job/time_start") + 900 > time() ) {
		if( !me->query("Hell_Job/done")) {
			command("heng " + me->query("id"));
			command("say ÉÏ´Î¶¼Ã»¸ÉÍê£¬ÈËÒ²Ã»×¥»ØÀ´£¬»¹ÓÐÁ³»ØÀ´¼ûÎÒ£¡\n");
			return 1;
		}
		command("say ÉÏ´Î¸ÉµÄ²»´í£¬ÑÛÏÂÃ»Ê²Ã´Òª½ôÊÂ£¬ÏÈÐª×Å°É¡£\n");
		return 1;
	}
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	string* dirs;
	object ghost;

        dirs = ({"/d/4world/","/d/city/","/d/gao/", "/d/jjf/",
"/d/lingtai/", "/d/meishan/","/d/moon/", "/d/nanhai/", "/d/penglai/",
"/d/sea/","/d/sky/", "/d/xueshan/", "/d/qujing/nuerguo/", 
"/d/qujing/wudidong/", "/d/qujing/firemount/"});

        seteuid(getuid());

        ghost = new("/obj/npc/ghost");
	ghost->move("/obj/void");
        ghost->invocation(me, dirs);
//release the ghost;
//
	command("spank " + me->query("id"));
	command("whisper " + me->query("id") + "
¾Ý´ÞÅÐ¹ÙËµ£¬ÅÜÁË¸öÀÎÖÐ¶ñ¹í£¬´ó¸ÅÔÚ¸½½ü£¬¸øÄãÊ®Îå·ÖÖÖ°ÑËû×½»ØÀ´¡£\n");
	me->set("Hell_Job/time_start", time());

	return 1;
}

int send_me()
{
	object who;
	who=this_player();
	message_vision("$N¶Ô$nµãÁËµãÍ·£¬µÀ£ºÊÇÄã×Ô¼ºÒªÈ¥£¬»Ø²»À´±ðÔ¹ÎÒ¡£\n",this_object(),who);
	who->move("/d/death/emptyroom");
	return 1;
}
*/
int work_me()
{
	object who;
	who=this_player();

	if( (int)who->query("combat_exp") < 300000 ) {
		message_vision("$N¶Ô$nÒ»¹°ÊÖ£¬µÀ£ºµÀÐÐ²»¹»£¬Ç¿ÇóÒàÊÇÍ÷È»¡£\n", this_object(),who);
		return 1;
	}
	if( who->query("HellZhenPass") ) {

message_vision("$N¶Ô$nÒ»¹°ÊÖ£¬µÀ£º¼´ÊÇÎä¹¦¸ßÇ¿£¬ÎÒµÈÅå·þ±ãÊÇ£¬Õâ¡£¡£¡£±ãÊÇÃâÁË°É£¡\n",this_object(),who);
	return 1;
	}
	if( this_object()->query_temp("SomeonePassing") ) {
		message_vision("$N¶Ô$nÒ»¹°ÊÖ£¬µÀ£ºÕæÊ±»úÔµ²»ÇÉ£¬¸ÄÈÕÔÙÀ´°É¡£\n",this_object(),who);
		return 1;
	}


message_vision("$N¶Ô$nÒõÒõµØÐ¦ÁË¼¸Éù£¬Ëµ£ºÌìÌÃÓÐÂ·Äã²»×ß£¬µØÓüÎÞÃÅÄã´³½øÀ´¡£\n",this_object(),who);
	this_object()->set_temp("SomeonePassing");
//add a chat here.
	command("chat "+who->query("name")+"Òª´³°³µØ¸®Ê®°Ë²ãµØÓü£¬ºß£¡µÈ×ÅÊÕÊ¬°É£¡\n");

	message_vision("$NË«ÊÖÅÄÁËÒ»ÏÂ£¬$n½ÅÏÂÍ»È»ÏÝÁËÏÂÈ¥¡£¡£¡£\n", this_object(),who);
	who->delete("env/brief_message");
	who->move("/d/death/emptyroom");

	command("grin");
	this_object()->move("/obj/void");
	
//	call_out("get_all",1,who);
	call_out("message",3,who);
	call_out("round_1",4, who);
	return 1;
}
/*
int get_all(object who)
{
  object me = this_object();
  object *obs = all_inventory (who);
  int i = sizeof(obs);

  message_vision ("Ò»Õó¿ñ·ç´µÀ´£¬·ðÒ¯³öÏÖ£¡\n",who);
  while (i--)
  {
    object ob = obs[i];

    if (ob == me)
      continue;
    if (ob->query("no_get"))
      continue;
    if (ob->query("no_drop"))
      continue;

    message_vision ("·ðÒ¯´Ó$NÉíÉÏËÑ³ö$n£¡\n",who,ob);
    if (! interactive(ob))
      destruct (ob);
    else
      ob->move(environment(who));
  }  
    return 1;
}

*/
int check_status(object who)
{
	if( (int)who->query("kee") < 50 
	||	(int)who->query("eff_kee") < 50 ) {
                remove_call_out("round_2");
                remove_call_out("round_3");
                remove_call_out("round_4");
                remove_call_out("round_5");
                remove_call_out("round_6");
                remove_call_out("round_7");
                remove_call_out("round_8");
                remove_call_out("round_9");
                remove_call_out("round_10");
                remove_call_out("round_11");
                remove_call_out("round_12");
                remove_call_out("round_13");
                remove_call_out("round_14");
                remove_call_out("round_15");
                remove_call_out("round_16");
                remove_call_out("round_17");
                remove_call_out("round_18");
		remove_call_out("message");
		remove_call_out("winning");
		call_out("failed",1,who);
		return 1;
	}
}
int failed(object who)
{	
	command("chat* ÑÖÂÞÍõ¿ñÐ¦ÁË¼¸Éù¡£");
	command("chat ¹ûÕæÓÐ²»ÅÂËÀµÄ£¬¿ÉÏ§»¹ÊÇÌÓ²»³ö°³µÄÊÖÕÆÐÄ£¡\n");
	this_object()->delete_temp("SomeonePassing");
	who->move("obj/void");
	who->unconcious();
	this_object()->move("/d/death/zhengtang");
	call_out("remove_all", 3);
	return 1;
}
int remove_all()
{	int i;
        object *list,empty;

        if( !(empty = find_object("/d/death/emptyroom")) )
                empty = load_object("/d/death/emptyroom");
	write("ËÄÖÜ¹ÎÆðÒ»ÕóÒõ·ç¡£¡£¡£\n");
        if( empty = find_object("/d/death/emptyroom") ) {

		list=all_inventory(empty);
		i = sizeof(list);
		while (i--)
		{
			object ob=list[i];
			ob->move("/d/changan/fendui");
		}
	}
	return 1;
}

int winning(object who)
{
// add a chat here.
	command("chat "+who->query("name")+"£¬ËãÄã×ßÔË£¬ÏÂ»Ø¿ÉÃ»ÕâÃ´±ãÒËÁË£¡\n");
// add reward here.
	who->add("kar", 10);
	who->add("potential", 1000);
//    who->add("combat_exp", 5000)
    who->add("daoxing", 5000);
	tell_object(who,"ÄãµÃµ½ÁËÒ»Ç§µãÇ±ÄÜºÍÎåÄêµÀÐÐ¡£\n");
	who->set("HellZhenPass",1);
	this_object()->move("/d/death/zhengtang");
	this_object()->delete_temp("SomeonePassing");
	call_out("remove_all", 3);
	return 1;
}
int message(object who)
{
	switch(random(5)) {

		case 0:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÖÜÎ§¾°ÎïÈç²Êµû·­·É£¬²»¿É×¢Ä¿¡£\n");
break;
		case 1:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ¡£\n");
break;
		case 2:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÌìµØËÆºõÃ»ÁË½çÏÞ¡£¡£¡£\n");
break;
                case 3:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÖÜÎ§Ò»ÇÐ¶¼ÔÚÐý×ª¡£¡£¡£\n");
break;
		case 4:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÏÂ½µ£¬ËÆºõÂäÏòÁËÎÞ¾¡µÄÉîÔ¨¡£\n");
break;
	}
	return 1;
}
int round_1(object who)
{
	object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/1");
	tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
	tell_room(environment(who),RED"                **************************************\n"NOR);
	tell_room(environment(who),RED"                **               µõ½îÓü             **\n"NOR);
	tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	call_out("check_status",1,who);
	call_out("message",2,who);
	call_out("round_2", 3, who);
        return 1;
}

int round_2(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/2");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               ÓÄÍ÷Óü             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_3", 3, who);
        return 1;
}
int round_3(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/3");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               »ð·»Óü             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_4", 3, who);  
        return 1;
}
int round_4(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/4");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               Ûº¶¼Óü             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_5", 3, who);  
        return 1;
}
int round_5(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/5");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        tell_room(environment(who),MAG"                **               °ÎÉàÓü             **\n"NOR);
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_6", 3, who);  
        return 1;
}
int round_6(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/6");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               °þÆ¤Óü             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_7", 3, who);  
        return 1;
}
int round_7(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/7");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        tell_room(environment(who),HIR"                **               Ä¥ÑÄÓü             **\n"NOR);
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_8", 3, who);  
        return 1;
}
int round_8(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/8");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        tell_room(environment(who),HIG"                **               ×¶µ·Óü             **\n"NOR);
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_9", 3, who);  
        return 1;
}
int round_9(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/9");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        tell_room(environment(who),HIY"                **               ³µ±ÀÓü             **\n"NOR);
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_10", 3, who);  
        return 1;
}
int round_10(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/10");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        tell_room(environment(who),HIB"                **               º®±ùÓü             **\n"NOR);
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_11", 3, who);  
        return 1;
}
int round_11(object who)
{
        object ghost,ghostb;
	seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/11");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        tell_room(environment(who),HIM"                **               ÍÑ¿ÇÓü             **\n"NOR);
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_12", 3, who);  
        return 1;
}
int round_12(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/11");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/12");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        tell_room(environment(who),HIC"                **               ³é³¦Óü             **\n"NOR);
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_13", 3, who);  
        return 1;
}
int round_13(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");

        seteuid(getuid());
        ghost=new("/d/death/HellZhen/13");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        tell_room(environment(who),HIW"                **               ÓÍ¹øÓü             **\n"NOR);
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_14", 3, who);  
        return 1;
}
int round_14(object who)
{
        object ghost,ghostb;
	seteuid(getuid());
        ghostb=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/14");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               ºÚ°µÓü             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_15", 3, who);  
        return 1;
}
int round_15(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/15");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               µ¶É½Óü             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_16", 3, who);  
        return 1;
}
int round_16(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/16");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               Ñª³ØÓü             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_17", 3, who);  
        return 1;
}
int round_17(object who)
{
        object ghost,ghostb;
	seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               °¢±ÇÓü             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_18", 3, who);  
        return 1;
}
int round_18(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/18");
	seteuid(getuid());
	ghostb=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ý£º\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               ³Ó¸ËÓü             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
	ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("winning", 3, who);  
        return 1;
}

ÿ
int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
        
   if((string)ob->query("name")=="ÑÖÍõÉúËÀ²¾" )
        {
         command("smile");
         command("say ÕâÎ»" + RANK_D->query_respect(me) +"ÕæÊÇÓÐÐÄÈË£¬ÎÒ¾ÍÔùÒ»ÀñÎïÓèÄã¡£");
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
