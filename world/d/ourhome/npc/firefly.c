// firefly.c by none 96/10/11

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("萤火虫", ({ "firefly" }) );
	set("gender", "女性" );
	set("age", 7);
	set("long", "这是一只可爱的萤火虫，整天飞来飞去为路人指路，
送一双绣花小鞋给她做纪念品吧。\n");
	set("combat_exp", 10);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 1);
	setup();
	set("chat_chance", 20);
	carry_object("/d/ourhome/obj/phone");
	add_money("coin", 5);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        set("chat_chance", 20);
        set("inquiry", ([
                "name" : "不是告诉你啦？我叫萤火虫。你呢？^_*\n",
                "road" : "有汽车，还有飞船，你想去哪儿？\n",
		"路"   : "有汽车，还有飞船，你想去哪儿？\n",
                "here" : "啊，你问这儿啊？好玩儿的地方可多了。哦，对了，要不要先去邮局跟你在这儿的朋友先联络一下？知道路吗？\n", 
		"邮局" : "就在小店附近啊^_*\n",
		"作业" : "问我？！你该去问你老板啊:O\n",
		"汽车" : "从小店一直往南走，千万不要朝两边儿看喔:P\n",
		"飞船" : "我有一部呢！可惜不会开:(你会开飞船吗？带我飞害虫家后花园好不好？\n",
      		"后花园" : "好多好吃的喔！\n", 
		"害虫" : "就是我们村长啊！\n",
		"萤火虫" : "远在天边，近在眼前啊^_*\n",
		"小店" : "你不是打那儿进来的吗？\n",
	 ]) );
        set("chat_msg_combat", ({
                "萤火虫哭叫道：杀人哪！杀人哪！\n",
                "萤火虫哭叫道：有土匪哪！光天化日下打劫哪！\n",
                (: command, "surrender" :),
        }) );

        set("chat_msg", ({
                "萤火虫笑盈盈地跟路上的人打招呼。\n",
                "萤火虫说道：我叫萤火虫，你是谁呀？\n",
                "萤火虫边蹦边唱：小皮球，驾脚踢，马莲开花二十一……\n",
                "萤火虫边唱边蹦：二五六，二五七，二八二九三十一……\n",
                (: random_move :)
        }) );

}

int accept_object(object me, object ob)
{
	object phone;

//    if ((string)ob->query("liquid/type")=="alcohol") {
//        if ((int)ob->query("liquid/remaining") == 0) {
     if ((string)ob->query("id")!="shoes") {
            command("smile");
            command("say 你好客气哟^_*。");
	    command("give " + ob->query("id") + "to" + me->query("id"));
            return 1;
        }
        else {
		command("joythank " + me->query("id"));
       		command("say 谢谢这位" + RANK_D->query_respect(me) + "！:)");
	        command("give phone to " + me->query("id"));
	        carry_object("/d/ourhome/obj/phone");
       		return 1;
        }
}

int accept_fight(object me)
{

//	CHANNEL_D->do_channel("萤火虫", "chat", "cry", 1);	
	command("chat* " + "萤火虫想到伤心处, 忍不住放声大哭.\n");
	command("chat 呜哇~~~有位" + RANK_D->query_respect(me) + "打我喔！:(\n");
	return 0;
}

void greeting(object ob)
{
//        if( !ob || environment(ob) != environment() ) return;
	if( !ob ) return;

        switch( random(5) ) {
                case 0:
                        tell_object( ob, GRN "萤火虫拍拍翅膀，趴在你的耳边悄声说道：你好吗？:)\n" NOR);
			tell_room( environment(), "萤火虫拍拍翅膀，趴在" + ob->name() + "耳边小声地说了些话。\n", ({ ob, ob }) );
			break;
                case 1:
                        tell_object( ob, GRN "萤火虫拍拍翅膀，趴在你的耳边悄声说道：这位" + RANK_D->query_respect(ob)
                                + "，你从哪儿来呀？:)\n" NOR);
                        tell_room( environment(), "萤火虫拍拍翅膀，趴在"
				+ ob->name() + "耳边小声地说了些话。\n", ({ ob, ob }) );
                        break;
                case 2:
                        tell_object( ob, GRN "萤火虫拍拍翅膀，趴在你的耳边悄声说道：这位" + RANK_D->query_respect(ob)
                                + "，咱俩玩儿捉迷藏，好不好？\n" NOR);
                        tell_room( environment(), "萤火虫拍拍翅膀，趴在"
                                + ob->name() + "耳边小声地说了些话。\n", ({ ob, ob }) );
                        break;
		case 3:
			tell_object( ob, GRN "萤火虫拍拍翅膀，趴在你的耳边悄声说道：天气真好喔。:)\n" NOR);
			tell_room( environment(), "萤火虫拍拍翅膀，趴在" + ob->name() + "耳边小声地说了些话。\n", ({ ob, ob }) );
			break;
		case 4:
			tell_object( ob, GRN "萤火虫拍拍翅膀，趴在你的耳边悄声说道：作业写完了吗？:)\n" NOR);
			tell_room( environment(), "萤火虫拍拍翅膀，趴在" + ob->name() + "耳边小声地说了些话。\n", ({ ob, ob }) );
        }
}

