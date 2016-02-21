// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit NPC;
int check_name(string str,object me);
int create_banghui(string str);
void create()
{
        set_name("土地", ({ "tu di", "tudi" }) );
        set("long",
                "大唐土地，专门负责大唐帮会事务。\n");
	set("title", HIW"西游记2006"NOR);
        set("attitude", "heroism");
       
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("agi",55);
	set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
        set("inquiry", ([
		"banghui"	:"要创建帮会请create <帮会名>\n",
		"帮会"		:"要创建帮会请create <帮会名>\n",
        ]) );
        set("combat_exp", 9000000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 1000);
	set_skill("sword",1000);
	set_skill("force",1000);
        set_skill("parry", 1000);
        set_skill("dodge", 1000);
	set_skill("changquan",1000);
	set_skill("literate",1000);
	
   map_skill("unarmed","changquan");
	        setup();

}
void attempt_apprentice(object me)
{
	command("sigh");
	command("say 我何德何能？\n");
}
int check_name(string name,object me)
{
        int i;

        i = strlen(name);

	if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {
		tell_object(me,"帮会名称请定在二到八个字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
			tell_object(me,"对不起，你的帮会名中不能用控制字符。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
			tell_object(me,"请用「中文」命名你的帮会。\n");
                        return 0;
                }
        }
	return 1;
}

// by gslxz@mhsj 1/7/2001

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
                {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
                }
	add_action("create_banghui","create");
}
void greeting(object ob)
{
	string banghui;
	object lingpai;
	if( !ob || environment(ob) != environment() ) return;
	if((string)(banghui=ob->query("banghui")))      {
		lingpai=new("/obj/lingpai");
		lingpai->create(banghui);
		if(lingpai->query("no_use"))	{
			tell_object(ob,"土地道："+ob->query("name")+"，你的帮会文件有问题，快与巫师联系吧。\n");
		}
		else if(lingpai->query("bangzhu_id")!="???")	{
			if( lingpai->query("bangzhu_id")==ob->query("id") &&
			lingpai->query("bangzhu")==ob->query("name"))
			tell_object(ob,"土地一抱拳道：这位"+ob->query("banghui")+
			ob->query("bh_rank")+"，贵帮生意如何？\n");
			else	tell_object(ob,"土地道："+ob->query("name")+
			"，贵帮帮主身体可好？\n");
		}
		else tell_object(ob,"土地偷偷在你耳边道：贵帮主失踪多日，"+
                        RANK_D->query_respect(ob)+"只需花一千两黄金就可以买下帮主之位。\n");
		destruct(lingpai);
	}
	else	tell_object(ob,"土地对你一抱拳道：这位"+RANK_D->query_respect(ob)+"是来创建帮会的吗<creat 帮会>？\n");
}
int accept_object(object who,object obj)
{
	string banghui;
	object lingpai;
	if(! banghui=who->query("banghui"))	{
		tell_object(who,"土地笑道：我可不敢平白无故接受你的东西。\n");
		return 0;
	}
	lingpai=new("/obj/lingpai");
	lingpai->create(banghui);
	if(lingpai->query("no_use"))	{
		tell_object(who,"土地叹道："+who->query("name")+"，你的帮会文件有问题，快与巫师联系吧。\n");
		destruct(lingpai);
		return 0;
	}
	if(lingpai->query("bangzhu_id") != "???")	{
		tell_object(who,"土地十分惊讶，说道：贵帮帮主还活的好好的，我可不改把帮主之位卖给"+
		RANK_D->query_respect(who)+"啊。\n");
		destruct(lingpai);
		return 0;
	}
	if(! obj->query("money_id"))	{
		tell_object(who,"土地皱眉道：这些破烂我没兴趣。\n");
		destruct(lingpai);
		return 0;
	}
	if(obj->value()<10000000)	{
                 tell_object(who,"土地道：至少一千两黄金，不然我如何向上面交待？\n");
		destruct(lingpai);
		return 0;
	}
	lingpai->set("bangzhu",who->query("name"));
	lingpai->set("bangzhu_id",who->query("id"));
	lingpai->save();
	destruct(lingpai);
         this_player()->set("title",YEL+this_player()->query("banghui")+"帮主"NOR);
	command("chat "+who->query("name")+
"花了一千两黄金，买下了"+banghui+"帮主之位。\n");
	return 1;
}
// by gslxz@mhsj 1/7/2001
int create_banghui(string str)
{
	object me,lingpai;
	int count;

	me=this_player();
	if((string)me->query("banghui"))	{
		tell_object(me,"你已经是"+me->query("banghui")+"的人了，不能另创帮会。\n");
		return 1;
	}
	if(me->query("combat_exp")<3000000)	{
		tell_object(me,RANK_D->query_respect(me)+"的实战经验还差"+
		(string)(3000000-me->query("combat_exp"))+"点，暂时无法开帮立会。\n");
		return 1;
	}
	if(! count=me->query("oldsix/have_create"))	count=0;
	if(count>=2)	{
		tell_object(me,"土地怒道：你以为帮会是创着玩吗？想再建帮会，下辈子吧！！\n",);
		return 1;
	}
	
	if(! str)	{
		tell_object(me,"你要创建什么名字的帮会？\n");
		return 1;
	}
	if(! check_name(str,me)	)	return 1;

	if(file_size("/data/guild/"+str+".o")!=-1) {
		tell_object(me,"非常抱歉，你起的帮会名早就有了。\n");
		return 1;
	}
	lingpai=new("/obj/lingpai");
	lingpai->create(str);
	lingpai->set("bangzhu",me->query("name"));
	lingpai->set("bangzhu_id",me->query("id"));
	lingpai->set("player",([me->query("id"):me->query("name")]));
	lingpai->set("npc",([]));
	lingpai->set("area",([]));
	lingpai->set("money",0);
	lingpai->save();
	destruct(lingpai);

	me->set("banghui",str);
	me->set("bh_rank","领袖");
       me->set("title",YEL+me->query("banghui")+"帮主"NOR);
            count++;
	me->set("oldsix/have_create",count);
            me->save();
       	command("chat 恭喜"+me->query("name")+"的帮会「"WHT+str+HIC"」创建成功！\n");
	return 1;
}
