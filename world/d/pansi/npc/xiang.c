//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_for_leave();
void create()
{
       set_name("香香", ({"xiang xiang", "xiang","master"}));
       set("long",
"牛魔王的妹妹,五岳山一战之后与其兄大力牛魔王决裂,跟随桃花娘子春十三娘来到
这花果山,隐居在桃林之后的盘丝洞内,经常在这里采桃。\n");
       set("title", "盘丝洞第三代弟子");
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "牛精");
       set("per", 10);
       set("int", 30);
       set("max_kee", 2900);
//       set("max_gin", 2600);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 20);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
       set("combat_exp", 800000);
       set("daoxing", 800000);
       set("eff_dx", 800000);
       set("nkgain", 350);
       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 80);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);
       set_skill("whip", 100);
       set_skill("pansi-dafa", 100);
       set_skill("lanhua-shou", 100);
       set_skill("jiuyin-xinjing", 100);
       set_skill("qingxia-jian", 100);
       set_skill("yueying-wubu", 100);
       set_skill("yinsuo-jinling", 150);
       map_skill("spells", "pansi-dafa");
       map_skill("unarmed", "lanhua-shou");
       map_skill("force", "jiuyin-xinjing");
       map_skill("sword", "qingxia-jian");
       map_skill("parry", "qingxia-jian");
       map_skill("dodge", "yueying-wubu");
       map_skill("whip", "yinsuo-jinling");
//   set("chat_chance_combat", 50);
       set("inquiry", ([
		"出山" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
		]) );
   set("chat_chance",5);
   set("chat_msg", ({
        HIM"香香仰天长叹:桃花过处，寸草不生！\n"NOR,
        }));


create_family("盘丝洞", 3, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
    	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
/*        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们盘丝洞只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}
		else
         {*/
	  command("curtain");
	  command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，他日必有所成！\n");
	  command("recruit " + ob->query("id") );
          ob->set("class", "yaomo");
if (ob->query("gender")=="女性")
		  ob->set("title", "盘丝洞桃花阵掌阵女使");
if (ob->query("gender")=="男性")
                  ob->set("title", "盘丝洞桃花阵掌阵使");

//     }

}
void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "盘丝洞" ) {
		command("say 你既是执意下山，我却有几句话说。");
		me->set_temp("betray", "pansi");
		return ("脱离师门要需要有一定惩罚，你可愿意(agree)？");
	}

	return ("不知道。\n");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")=="pansi") {
		message_vision("$N答道：弟子愿意。\n\n", this_player());
		command("say 既是你与盘丝洞无缘，你便下山去吧！");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/pansi", 1);
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
		if( this_player()->query_skill("pansi-dafa") )
		    this_player()->delete_skill("pansi-dafa");
		if( this_player()->query_skill("jiuyin-xinjing") )
	            this_player()->delete_skill("jiuyin-xinjing");

		
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->set("title", "普通百姓");
		this_player()->set_temp("betray", 0);
		this_player()->save();
		command("say 江湖风波，善恶无形，好自为之。。。\n");
		return 1;
	}
}
