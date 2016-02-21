//tomcat 2000/03/05
// swk.c

#include <ansi.h>


inherit NPC;
inherit F_MASTER;

void create()
{
	set_name( HIW "孙悟空" NOR, ({ "sun wukong", "wukong","swk"  }) );
	set("long",
		"一个身不足五尺，瘦瘦干干，满身黄毛的猢狲。\n");

	set("age", 30);
	
	set("max_gin", 8000);
	set("max_kee", 8000);
	set("max_sen", 8000);
        set("gin", 8000);
	set("kee", 8000);
	set("sen", 8000);

	set("max_force", 8000);
	set("force", 16000);
	set("max_mana", 8000);
	set("mana", 16000);
         set("force_factor", 350);
        set("mana_factor", 300);

	set("str", 100);
	set("cor", 100);
	set("cps", 100);
	set("spi", 100);
	set("int", 100);
	set("con", 100);
	set("kar", 100);
	set("per", 100);

	set("combat_exp", 8000000);
	set("daoxing", 8000000);

        
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 280);
	set_skill("stick", 300);
	set_skill("spells", 280);
	set_skill("dao", 280);
	set_skill("puti-zhi", 250);
        set_skill("sword", 300);
        set_skill("liangyi-sword", 300);
	set_skill("wuxiangforce", 280);
	set_skill("force", 280);
	set_skill("qianjun-bang", 300);
	set_skill("jindouyun", 280);
	
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

       set("title", HIR"齐天大圣"NOR);
	set("apply/attack", 100);
	set("apply/defense", 100);
	set("apply/armor", 100);
	set("apply/damage", 100);
        create_family("方寸山三星洞", 1, "蓝");
	setup();

	carry_object("/d/obj/weapon/stick/fake-jingubang.c")->wield();
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	
        if( (string)ob->query("family/family_name")=="方寸山三星洞") {
	if ((int)ob->query("daoxing") < 1000000 ) {
  	command("say 你道行太低了。\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "老祖说了不要我收你为徒了！\n");
	command("sigh");
	return;
	}

        if (ob->query("obstacle/number") < 26) {
	command("say 这位" + RANK_D->query_respect(ob) + "拜我为师，要先先历尽取经劫难！\n");
	command("sigh");
	return;
	}
	
	if( (int)ob->query_skill("dao", 1) < 180 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我道家仙法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 没有老祖的同意，我不能收你为徒" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
ob->set("title", RED"齐天大圣亲传弟子"NOR);
}

