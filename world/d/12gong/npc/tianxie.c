// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("米罗", ({"milo", "tian xie"}));
        set("long", "在十二宫之战中，打败冰河，当他发现冰河其实是正义时，帮助冰
河渡过难关。冥界之战中，由于小宇宙被哈迪斯封住，被三巨头之一的拉达曼迪斯打败。 
守护着天蝎座.\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",10000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "米罗说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("tianxie", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","tianxie");
        map_skill("dodge","balei");
        set("max_force", 2000);
        set("force", 4000);
        set("max_mana",200);
        set("mana",4000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 1500);
        set("max_gin", 1500);
        set("max_sen", 1500);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object ghost;
        object me=query_temp("my_killer");
        if( ! me ) return ;
if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                      
     switch(random(6))
     {        
        case 0:
        {
        message_vision(YEL"$N一声狂笑，蝎红毒针向$n扑去。！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(YEL"$N连中十四针,全身陷入一阵麻痹中！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
else        message_vision(YEL"$N鬼使神差般的避开了[蝎红毒针]的进攻。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N吹了一口气，一股绿色的毒气向$n喷去！\n",ob,me);

        if(random(2)==0)

                {
              message_vision(YEL"$N顿时被熏晕了头！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(YEL"$N旋转不停，不多一会毒气消失的无影无踪。\n"NOR,me);
        }
        break;

        case 2:
        {

        
    //    ghost=new("/obj/npc/ghost.c");
    //    ghost->move(environment());
    //    ghost->set("combat_exp",ob->query("combat_exp"));
    //    ghost->set("max_kee",ob->query("max_kee"));
    //    ghost->set("max_sen",ob->query("max_sen"));
    //    ghost->kill_ob(ob);
        if(random(2)==0)
			{
		message_vision(HIR"$N爆发黄金小宇宙,使出天蝎座最强的一招[安达里士]!\n",ob);
		message_vision(HIC"天蝎毒针直刺你的心脏！\n"NOR,me);
        me->add("eff_kee",-2*query("max_kee")/10);
        me->add("eff_sen",-2*query("max_sen")/10);
	        }	
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

        
        if (ob->query_temp("12gong/cike") == "done")
			
			 message("chat",HIY+"【黄金十二宫】米罗(Milo):"+ob->name()+
             "强闯过第八宫天蝎宫大家快拦住他。\n"NOR,users());
             else
         message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
             "闯过了第八宫天蝎宫，继续向射手宫前进。\n"NOR,users());
if((ob&&ob->query("12gong/tiancheng")=="done") && (ob&&ob->query("12gong/tianxie")!="done"))
        {
			 ob->start_busy(3);
			 ob->set("12gong/tianxie","done");
             ob->add("12gong/number",1);
             ob->add("combat_exp", 10000);
             tell_object(ob,"你赢得了十年道行");

        }
       ::die();
}

void unconcious()
{
  die();
}
