// zhongkui.c
// by fjz

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "他妈的","你妈的","傻B","我操","操你","和你妈睡","有活的没有","没死会？","操",
                      "操！","操!","fuck","FUCK","Fuck","婊子","有没有活的","想死?","shit","SHIT","Shit",
                      "你奶奶的","和你妈做爱","她妈的","你爷爷的","有没有喘气的","cao","CAO","Cao",
                      "放你妈的屁","tmd","TMD","tmmd","TMMD","操你妈","日死你","干你娘","没死回？","瓜娃子","瓜的","瓜批",
                      "操你姐","狗屁wiz","狗wiz","破wiz","死wiz","日死你","Nnd","kao","KAO","Kao","去死吧",
                      "干你妈","干你的","ｆｕｃｋ","ＦＵＣＫ","F u c k","f u c k","nnd","NND","SB",
                      "mlgb","MLGB","mcb","Sb","sb","shabi","SHABI","MCB","danzi","蛋子","你妈","你爹",
                      "牛比","靠","放屁","吃屎","你大爷","操你妈","打炮","6mang","大便","小便","caobi",
                      "手淫",});
                      

void punish(object);

int give_quest();

void create()
{
        set_name("黑山老妖", ({"heishan laoyao", "laoyao", "yao"}));
        set("title", WHT"「西游记2006巡查使」"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 12);//no rongmao description.

        set("long", "一个神秘的狱卒，你碰上他准是你干了什么坏事。\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("blade", 350);
        set_skill("force", 350);   
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
//		"抓鬼"	:	(: give_quest :),
	]));        
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( clonep() ) CHANNEL_D->register_relay_channel("sldh");
        if( clonep() ) CHANNEL_D->register_relay_channel("party");
        if( clonep() ) CHANNEL_D->register_relay_channel("bd");
        if( clonep() ) CHANNEL_D->register_relay_channel("es");
        if( clonep() ) CHANNEL_D->register_relay_channel("xyj");
		if( clonep() ) CHANNEL_D->register_relay_channel("mp");
        carry_object("/d/lingtai/obj/xiangpao")->wear();

}

void relay_channel(object ob, string channel, string msg)
{

        int i;
        if( !userp(ob) || (channel == "sys") ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
        	msg=replace_string(msg, " ", "");
        	msg=replace_string(msg, "　", "");
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    call_out("punish",1,ob);
                    return;
                    }
        }
}


void punish(object ob)
{
    	int i;
      if(ob->is_fighting()||ob->is_busy())
    {
    call_out("punish", 1, ob); return; }
        command_function("chat* 忽听黑山老妖一声怒喝："+ob->query("name")+" ，这次你可跑不了了。");
        message_vision(HIR"空中飞下一根绳子，一下就套住$N的脖子。\n"NOR+CYN"$N伸长舌头、翻着白眼地被拖走了。\n"NOR, ob);
        
		ob->move("/d/wiz/qiushi");
		        message_vision(HIW"黑山老妖对$N严厉道：敢口出污言秽语？在此地老老实实给我蹲着。\n", ob);
        message_vision(HIW"说着，绳子一松，$N被扔在地上。\n"NOR, ob);
        command("fool");
        command("say 又抓到一个。");
}
/*
int give_quest()
{
	object who, seal;
	mapping room;
	
	who=this_player();
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
	reward=800+random(200)*times+200*times;
	msg="被奖励了";
	switch(random(3))
	{
		case 0:
			who->add("wuxue_exp", reward);
			who->add("catch_ghost/cache/wuxue", reward);
			msg+=chinese_number(reward)+"点武学。\n";
			break;
		case 1:
			who->add("combat_exp", reward);
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
*/

