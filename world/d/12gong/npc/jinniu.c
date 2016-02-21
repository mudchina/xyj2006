// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("亚鲁迪巴", ({"aldebaran", "jin niu"}));
        set("long", "金牛座。最勇猛凶悍的黄金圣斗士，但经常被招式诡异的对手打败，
冥界之战中，与地暗星尼奥比同归于尽。\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",30);
        set("per",20);
        set("str",30);
        set("int",35);
        set("combat_exp",1000000);
          set("daoxing",2800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "亚鲁迪巴说道：不知何时能再见到雅典娜！\n"   
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
        set_skill("jinniu", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3000);
        set("force", 7000);
        set("max_mana",5000);
        set("mana",8000);
        set("mana_factor",100);
        set("force_factor", 100);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        setup();
        carry_object(__DIR__"obj/jn_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void init()
{
        
        object me=this_player();
		::init();
        
if (me->query_temp("12gong/cike") == "done")
	{
	set_skill("dodge", 300);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("unarmed", 300);
        set_skill("sword", 300);
        set_skill("westsword",300);
        set_skill("boxing",300);
        set_skill("balei",300);
        set_skill("spells",300);
        set_skill("jinniu", 300);
	command("say 废话少说,拿命来！\n");
    kill_ob(me);
    }
}

void check()
{
        object ob=this_object();
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
        message_vision(YEL"$N挥挥衣袖，黄土向$n卷卷而来！\n",ob,me);


       if(random(3)==0)
                {
              message_vision(YEL"$N被飞来的黄土淹没了双眼！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(YEL"$N也鼓起嘴巴，把飞来的黄土纷纷吹落在地！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N大吼道，[黄金野牛拳],$N犹如一只发狂的斗牛向$n冲来！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N被斗牛的尖角转了个大窟窿！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        }
        break;

        case 2:
        {

        message_vision(HIR"$N向$n打出绝招[巨型号角]。\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N不但不躲避，反而迎了上去！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$n看准$N出拳方向，躲开了$N的光速攻击！\n"NOR,me,ob);
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

        if((ob&&ob->query("12gong/baiyang")=="done") && (ob&&ob->query("12gong/jinniu")!="done"))
        {
        ob->start_busy(3);
        if (ob->query_temp("12gong/cike") == "done")
		message("chat",HIY+"【黄金十二宫】亚鲁迪巴(Aldebaran):"+ob->name()+
        "已经强闯过我金牛宫!\n"NOR,users());
		if (ob->query_temp("12gong/cike") != "done")
         message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "闯过了第二宫：金牛宫!奖励道行十年!\n"NOR,users());
        ob->set("12gong/jinniu","done");
        ob->add("12gong/number",1);
       ob->add("daoxing", 10000);
        tell_object(ob,"你赢得了十年道行");

        }
       ::die();
}

void unconcious()
{
  die();
}
