// by happ@YSZZ
 
inherit NPC;
#include "star.h"

 
void create()
{
        set_name("艾欧里亚", ({"aiolia", "shi zi"}));
        set("long", "狮子座。像一头黄金狮子般，极富正义与勇气。在冥界之战中，
曾一拳杀死五名冥斗士，在与地伏星莱米的激战中，最终取得胜利。誓死守护着狮子座。\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
          set("combat_exp",10000000);
        set("daoxing",10000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "艾欧里亚说道：不知何时能再见到雅典娜！\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("unarmed", 280);
        set_skill("sword", 280);
        set_skill("westsword",280);
        set_skill("boxing",280);
        set_skill("balei",280);
        set_skill("spells",280);
        set_skill("jinniu", 280);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 5000);
        set("force", 9000);
        set("max_mana",5000);
        set("mana",9000);
        set("mana_factor",50);
        set("force_factor", 150);
        set("max_kee", 2500);
        set("max_gin", 2500);
        set("max_sen", 2500);

        setup();
        carry_object(__DIR__"obj/shz_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        
        object me=this_player();
		::init();
        add_action("do_nod", "nod");
		if (me->query_temp("12gong/cike") != "done")
			{
           	command("say 来得好,我等你很久了,能够来到狮子宫的人一定是女神挑选出
来的勇士,战胜我才能证明你的力量和勇气!你准备好了吗?(nod)\n\n\n");
        	}
if (me->query_temp("12gong/cike") == "done")
	{
	command("say 好大的胆子,竟敢来刺杀[女神] 雅典娜,先过我这一关！\n");
    message_vision(HIY"\n怒气冲天的艾欧里亚全身黄金斗气大盛,一头凶猛的黄金狮子已经向你冲了过来!!!\n"NOR,me);	
	kill_ob(me);
    set_skill("dodge", 300);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("unarmed", 300);
        set_skill("sword", 300);
        set_skill("westsword",300);
        set_skill("boxing",300);
        set_skill("balei",300);
	}
}


void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;

 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
if(!present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIC"$N张开大嘴，竟然幻出一头黄金狮子，罩向$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"黄金拳头如雨点般落在$N的身上！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIC"$N大吼一声，居然把黄金斗气反弹了回去。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N手指太阳，只见阳光突然变强，照得人睁不开眼！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIC"$N感觉到浑身如针扎般刺痛。\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIC"阳光照在$N的身上，$N感到无限的暇意。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIC"$N使出[闪电光速拳]，犹如一头黄金狮子向$n扑去。\n",ob,me);
                              
                if(random(2)==0)

                {
              message_vision(HIY"$N不知如何是好，已然中了无数重拳！\n"NOR,me);
              me->start_busy(1);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N闭上眼睛，凭对方发出的斗气判断攻击方向,躲过了这致命的一击！\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/juxie")=="done") && (ob&&ob->query("12gong/shizi")!="done"))
        {
        if (ob->query_temp("12gong/cike") == "done")
			
			 message("chat",HIY+"【黄金十二宫】艾欧里亚(Aiolia):"+ob->name()+
             "强闯过第五宫狮子座，黄金圣斗士誓死保护女神-雅典娜。\n"NOR,users());
             else
         message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
             "闯过了第五宫狮子座，继续向处女宫前进。\n"NOR,users());
			 ob->start_busy(3);
			 ob->set("12gong/shizi","done");
             ob->add("12gong/number",1);
             ob->add("combat_exp", 10000);
             tell_object(ob,"你赢得了十年道行");

        }
       ::die();
       return 0;
}


int do_nod(string arg)
{
	
	object me=this_player(), npc=this_object(), ob;
	if (me->query_temp("12gong/cike") != "done")
	//string myname=me->query("id");
    {
		command("say 小心了!!!\n");
        kill_ob(me);
        message_vision(HIY"\n艾欧里亚全身黄金斗气大盛,就像一头凶猛的黄金狮子!\n"NOR,me);	
 	}
return 0;

}

void unconcious()
{
  die();
}
