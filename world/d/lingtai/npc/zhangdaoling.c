//puti.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
       set_name("张道陵", ({"zhang daoling", "zhang", "daoling"}));
       set("long", "张道陵乃是天上的天师，此刻偷闲在山边观观景色。\n");
       set("title", "天师");
       set("gender", "男性");
	set("class", "taoist");
       set("age", 60);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "老神仙");
       set("per", 30);
	set("int", 30);
	set("str", 25);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 1000);
       set("mana",1900);
       set("mana_factor", 50);
       set("combat_exp", 800000);
  set("daoxing", 1000000);


        set("eff_dx", 250000);
        set("nkgain", 400);



       set_skill("literate", 100);
       set_skill("unarmed", 105);
       set_skill("dodge", 135);
       set_skill("parry", 135);
	set_skill("sword", 135);
	set_skill("spells", 135);
	set_skill("dao", 120);
	set_skill("changquan", 120);
	set_skill("wuxiangforce", 120);
	set_skill("force", 120);
	set_skill("sanqing-jian", 135);
	set_skill("chaos-steps", 135);
	map_skill("spells", "dao");
	map_skill("unarmed", "changquan");
	map_skill("force", "wuxiangforce");
	map_skill("sword", "sanqing-jian");
	map_skill("parry", "sanqing-jian");
	map_skill("dodge", "chaos-steps");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: consider :)
        }) );



create_family("逍遥派", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/heao")->wear();
	carry_object("/d/lingtai/obj/faguan")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng");
}

void init()
{
       object me,ob;
    me=this_player();
	ob=this_object();

        ::init();
        
		if (me->query_temp("fangcun/qiansi_gongxi")==1) 
		{
                remove_call_out("greeting");
                call_out("greeting", 1, me);
                call_out("destroy", 60, ob);
        }
        
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="方寸山三星洞") {
	command("say RANK_D->query_respect(ob) + 已是身处名门，还需多加努力才是，怎可又投我门下？\n");
	return;
	}
	command("shake");
	command("say 老夫不收外门弟子，却可指点你一条明路，这山上有个老神仙，法力无边，你投奔他去吧！\n");
        return;
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
                message_vision("\n\n"NOR,ob);
				command ("say "+RANK_D->query_respect(ob)+"恭喜恭喜,领悟盘龙八式指日可待了！" );
}


void die()
{

        if( environment() ) {
        message("sound", "\n\n张道陵脸色突变，道：天上点卯，恕不奉陪！\n\n", environment());
	command("drop all");
	message("sound", "\n张道陵化成一股紫烟冲上天去。。。\n\n", environment());
        }

        destruct(this_object());
}

int accept_fight(object me)
{	me= this_object();
	if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 50 ) {
		if( (int)me->query("kee")*100/(int)me->query("max_kee") >= 90 ) {
		
			command("say 好吧，不过老夫马上就要走了，只斗片刻！\n");
        		command("unwield sword");
        		command("enable unarmed none");
			return 1;
			}
		command("say 好吧，不过老夫马上就要走了，只斗片刻！\n");
               	command("wield sword");
                command("enable unarmed changquan");
               	return 1;
	}
        command("say 良景如斯，无心斗而。\n");
        return 0;
}

void consider()
{

        int i, flag = 0;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                        flag++;
                if(     !query_temp("weapon") ) {
                command("say 阁下功夫超群，老道只好动粗了！\n");
                        command("wield sword");
			command("enable unarmed changquan");
                        break;
                }
        }
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

