// zhongkui.c
// by fjz
// tomcat 修改
// 给新手用的
#include <ansi.h>

inherit NPC;
int give_quest();

void create()
{
        set_name("钟馗", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"鬼见愁"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 112);//no rongmao description.

        set("long", "无人不知的抓鬼大仙。\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        set("inquiry", ([
		"抓鬼"	:	(: give_quest :),
	]));        
        setup();
        carry_object("/d/lingtai/obj/xiangpao")->wear();

}


int give_quest()
{
	object who, seal;
	mapping room;
	
	who=this_player();
     
  if ((int)who->query("combat_exp") > 1500000)
      {
           string myname=RANK_D->query_respect(who);
           command("say 这位"+myname+"这点小事不敢劳您大驾！");
           return 1;
      }

	if((time()-who->query("catch_ghost/last_time"))<300)
	{
		command("say 现在还算比较太平，你先去歇了吧。");
		return 1;
	}
	seal=new("/d/city/obj/seal");
	seal->set("master", who);
       do{ room=LOCATION_D->random_location(); } while(!strlen(room["long"]));
	seal->set("file_name", room["file"]);
	seal->set("desc", room["long"]);
	seal->move(who);
	who->set("catch_ghost/last_time", time());
	command("nod");
	message_vision("$N对$n说道：这张符给你，你看看符上写的符号去抓鬼吧。\n", 
	this_object(), who);
        who->start_busy(2);
	return 1;
}

int accept_object(object who, object ob)
{
	int reward, times;
	string msg;
	
	if(!ob->query("finished")||
		who!=ob->query("master"))
		return 0;
	command("nod");
	message_vision("$N对$n说道：很好！\n", this_object(), who);
	times=who->query_temp("catch_ghost");
	msg="被奖励了";
        reward=600+who->query_kar()*10+random(who->query_kar()*10);
	switch(random(3))
	{
		case 0:
			who->add("combat_exp", reward);
			who->add("catch_ghost/cache/wuxue", reward);
			msg+=chinese_number(reward)+"点武学。\n";
			break;
		case 1:
			who->add("daoxing", reward);
			who->add("catch_ghost/cache/dx", reward);
			msg+=COMBAT_D->chinese_daoxing(reward)+"道行。\n";
			break;
		default:
			who->add("potential", reward/4);
			who->add("catch_ghost/cache/pot", reward/4);
			msg+=chinese_number(reward/4)+"点潜能。\n";
	}
	who->add_temp("catch_ghost", 1);
	if(who->query_temp("catch_ghost")>9)
		who->set_temp("catch_ghost", 0);
        MONITOR_D->report_system_object_msg(who, "[抓鬼]"+msg);
        tell_object(who, "你"+msg);
        return 1;
}

