//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_zui(object me);
void create()
{
       set_name(HIY"春三十娘"NOR, ({"chun sanshiniang", "chun", "sanshiniang","niang"}));
       set("long",
"盘丝大仙座下的大弟子。本是一只蜘蛛精,随盘丝大仙修成正果,因帮助孙悟空盗取盘丝洞至宝月光宝合而
与其师妹白晶晶势成水火。很多年之后,她有个绰号叫做桃花娘子。\n");
       set("title", HIM"桃花娘子"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 22);
	set("int", 30);
       set("max_kee", 2900);
//       set("max_gin", 2600);
       set("max_sen", 2800);
       set("force", 1500);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 800000);
       set("daoxing", 800000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 100);
       set_skill("unarmed", 100);
       set_skill("dodge", 100);
       set_skill("force", 100);
       set_skill("parry", 100);
       set_skill("sword", 100);
       set_skill("spells", 100);
       set_skill("whip", 150);
   set_skill("pansi-dafa", 130);
   set_skill("lanhua-shou", 120);
   set_skill("jiuyin-xinjing", 100);
   set_skill("qingxia-jian", 150);
   set_skill("yueying-wubu", 100);
   set_skill("yinsuo-jinling", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
//   set("chat_chance_combat", 50);
   set("inquiry", ([
          		  "醉生梦死" : (: give_zui :),
]));
   set("chat_chance",5);
    set("chat_msg", ({
        HIG"春三十娘轻声告诉你:桃花过处，寸草不生！\n"NOR,
        HIG"春三十娘轻声告诉你:我以为在这世界上有一种人是不会有忌妒心的,因为她太骄傲了。在我出道的时候,我认识一个人,他叫孙
悟空，他喜欢在东边出没，他后来有个绰号叫齐天大圣。我认识他的那年，盘丝洞的桃花开得很美。\n"HIC,
        HIG"春三十娘轻声告诉你:我叫春三十娘,我的职业是替人解决麻烦,就是帮助别人杀人！\n"NOR,
                HIG"春三十娘轻声告诉你:自从离开盘丝洞之后，我去了这个沙漠。我很想知道沙漠这边有什么，走过来发现其实什么也没有，除了
沙漠还是沙漠。我于是开始了另一种生活。在这种生活中，只有仇恨，只有杀人和被杀！\n"NOR,
                HIG"春三十娘轻声告诉你:其实醉生梦死只不过是一坛清水，你越想知道自己是不是已经忘记的时候，你反而记得越清楚。\n"NOR,
                HIG"春三十娘轻声告诉你:那个人走的当天一直在下雨。每次下雨，我就会想起他，我一直不相信自己会想他。\n"NOR,
        }));

create_family("盘丝洞", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
	carry_object("/d/pansi/obj/qin");
}

void attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="盘丝洞") {
   if (((int)ob->query("daoxing") < 100000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们盘丝洞发扬光大。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "盘丝洞桃花娘子座下弟子");
	   ob->set("class", "yaomo");
   return;
   }
}

string give_zui(object me)
{
	me=this_player();
	me->set_temp("need_zui", 1);
	return "醉生梦死只不过是坛清水,你真的想要吗?(yes)？\n";
}

void init()
{
	add_action("do_yes", "yes");
}
int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("need_zui")) 
	{
		message_vision("$N答道：想要！\n\n", me);
		if( query("no_zui") == 0 )
		{
                        message_vision("春三十娘说道：好！那我给了你吧！\n", me);
			me->set_temp("need_zui", 0);

			carry_object("/d/pansi/obj/zui");
			command("give zui to " + me->query("id"));
			set("no_zui", 1);
			call_out("regenerate", 480);
		}
		else
		{
                        message_vision("春三十娘说道：一坛清水罢了,怎么这么多人想要,我已经给了别人。\n", me);
		}

		return 1;
	}
	return 0;
}

int regenerate()
{
	set("no_zui", 0);
	return 1;
}

