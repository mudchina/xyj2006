//puti.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);
void create()
{
       set_name("ÔÆÑôÕæÈË", ({"master yunyang", "master", "yunyang"}));
       set("long", "ÔÆÑôÕæÈËÓëÆÐÌá×æÊ¦ÊµÊÇ°ëÊ¦°ëÓÑ£¬Ò²ÊÇÈýÐÇ¶´ÄÚÍâ×Ü¹Ü£®
ÒòÆä×³ÄêÊ±½µÄ§³ýÑýÎÞÊý£¬ÈË³Æ¡¸Ð¡ÌìÊ¦¡¹£®\n");
       set("gender", "ÄÐÐÔ");
	set("title", "Ð¡ÌìÊ¦");
	set("class", "taoist");
       set("age", 70);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏµÀ³¤");
       set("per", 30);
	set("int", 30);
	set("str", 30);
	set("cps", 30);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 2300);
       set("max_force", 1200);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 60);
       set("combat_exp", 800000);
	set("daoxing", 1500000);


        set("eff_dx", 250000);
        set("nkgain", 400);

       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
	set_skill("stick", 120);
	set_skill("spells", 120);
	set_skill("dao", 120);
	set_skill("puti-zhi", 120);
	set_skill("wuxiangforce", 120);
	set_skill("force", 120);
	set_skill("qianjun-bang", 120);
	set_skill("jindouyun", 120);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

        set("inquiry", ([
		"ÏÂÉ½": (: expell_me :),
		"leave": (: expell_me :),
]) );

create_family("·½´çÉ½ÈýÐÇ¶´", 1, "À¶");
setup();

        carry_object("/d/lingtai/obj/xiangpao")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") {
	if (((int)ob->query("daoxing") < 100000 )) {
	command("say ÎÒÃÇÐÞÕæÖ®Ê¿×îÖØµÄ¾ÍÊÇµÀÐÐ£¬" + RANK_D->query_respect(ob) + "»¹Ðè¶à¼ÓÅ¬Á¦²ÅÊÇ¡£\n");
	return;
	}
        command("smile");
	command("say ºÃ¼«£¬ºÃ¼«£¬Ê±ÏÂÑýÄ§µ±µÀ£¬¹í¹ÖºáÐÐ¡£Ïó"  + RANK_D->query_respect(ob) +
"ÕâÑùµÄÕýÒåÖ®Ê¿È´ÊÇÉÙ¼û£¡\n");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
       command("recruit " + ob->query("id") );
       message("system", HIY"·½´çÉ½ÓÖ¶àÁËÒ»¸öµÜ×Ó  "+this_player()->name()+HIW"
                ·½´çÉ½µÄÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
	return;
	}
	command("shake");
	command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") {
                command("say Äã¼ÈÊÇÖ´ÒâÏÂÉ½£¬ÎªÊ¦È´ÓÐ¼¸¾ä»°Ëµ¡£");
                me->set_temp("betray", 1);
		command("say ÎÒ·½´çÉ½Ò²ÊÇÃûÃÅÕýÅÉ£¬µÀ¼ÒÕý×Ú¡£¹úÓÐ¹ú·¨£¬É½ÓÐÉ½¹æ£¡");
                return ("¼ÈÊÇÒª³öÉ½£¬È´ÐèÊÜÉ½¹æ³Í·££¬Äã¿ÉÔ¸Òâ(agree)?");
        }
        return ("Æ¶µÀ²»Öª¡£");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{		if (this_player()->query("family/family_name") == "·½´çÉ½ÈýÐÇ¶´" )
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ðµÀ£ºµÜ×ÓÔ¸Òâ¡£\n\n", this_player());
		this_player()->add("betray/count", 1);
		this_player()->add("betray/fangcun", 1);
                command("say ¼ÈÊÇÎÒ·½´çÉ½³ØÇ³ÈÝ²»ÏÂòÔÁú£¬Äã±ãÏÂÉ½È¥°É£¡");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("dao") )
		    this_player()->delete_skill("dao");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙÐÕ");
		this_player()->save();
                command("say ½­ºþ·ç²¨£¬ÉÆ¶ñÎÞÐÎ£¬ºÃ×ÔÎªÖ®¡£¡£¡£\n");
                return 1;
                }
        return 0;}
        	else return notify_fail("Ê²Ã´£¿\n");
}
ÿ
