// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("沙加", ({"sa ga", "shi nu"}));
        set("long", "最接近神的男人，黄金圣斗士中最强者。并在冥界之战中杀死多名
冥斗士。最后，和三名黄金圣斗士同归于尽，其实他未死，而是领
悟了八感，来到冥界。守护处女座。\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",15000000);
        set("daoxing",15000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "沙加闭着双眼,静静的盘腿坐在莎罗双树下,默默的对着你.\n"   
        }));
        set_skill("dodge", 280);
        set("attitude", "friendly");
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("unarmed", 280);
        set_skill("sword", 280);
        set_skill("westsword",280);
        set_skill("boxing",280);
        set_skill("balei",280);
        set_skill("spells",280);
        set_skill("shinu", 280);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shinu");
        map_skill("dodge","balei");
        set("max_force", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 2200);
        set("max_gin", 2200);
        set("max_sen", 2200);

        setup();
        carry_object(__DIR__"obj/su_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        object me=this_player();
		::init();
		if (me->query_temp("12gong/cike") == "done")
		{
	message("chat",HIC+"【黄金十二宫】沙加(Sa ga):"+me->name()+"竟敢闯我处女宫,就让你见识一下神的力量!\n"NOR,users());
   
	message_vision(HIY"\n沙加睁开了愤怒的双眼,黄金小宇宙爆发出来.\n\n"NOR,me); 
	message("chat",HIC+"【黄金十二宫】沙加(Sa ga):处女座最大奥秘["+HIY+"天舞宝轮"+NOR""+HIC+"]\n"NOR,users());	
		add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
        set_skill("dodge", 380);
//        set("attitude", "friendly");
        set_skill("force", 380);
        set_skill("parry", 380);
        set_skill("unarmed", 380);
        set_skill("sword", 380);
        set_skill("westsword",380);
        set_skill("boxing",380);
        set_skill("balei",380);
        set_skill("spells",380);
        set_skill("shinu", 380);
       set("max_force", 5000);
        set("force", 10000);
        set("max_mana",8000);
        set("mana",16000);
        set("mana_factor",100);
        set("force_factor", 200);
        set("max_kee", 2200);
        set("max_gin", 2200);
        set("max_sen", 2200);
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
        message_vision(HIG"$N手中念珠一挥，一阵狂风呼啸而起！幻出魑魅魍魉蜂拥扑向$n\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N被鬼怪扑倒在地上，毫无半点力量！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量让开了鬼怪的进攻！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一挥手中念珠，一道金光从空中落下罩向你！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被金光了个正着，顿时堕入了[六道轮回]中！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N早就看清了金光的方向，轻轻一闪，躲开了。\n"NOR,me);
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

        if (ob->query_temp("12gong/cike") != "done")
	{
		if((ob&&ob->query("12gong/shizi")=="done") && (ob&&ob->query("12gong/shinu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "闯过了第六宫：处女宫，向黄金战士进军。\n"NOR,users());
        ob->set("12gong/shinu","done");
        ob->add("12gong/number",1);
        ob->add("daoxing", 10000);
        tell_object(ob,"你赢得了十年道行");

        }
	}
	   if (ob->query_temp("12gong/cike") == "done")
	{
       if((ob&&ob->query("12gong/shizi")=="done") && (ob&&ob->query("12gong/shinu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】沙加(Sa ga):"+ob->name()+
        "毁我莎罗双树,强闯过了处女宫。\n"NOR,users());
        ob->set("12gong/shinu","done");
        ob->add("12gong/number",1);
        ob->add("daoxing", 10000);
        tell_object(ob,"你赢得了十年道行");

        
		}
	}
	   message_vision(HIY"\n\n沙加长叹一声,缓缓盘腿坐下,远处莎罗树也缓缓倒了下去.....\n"NOR,ob);
	   call_out("wait_time",20);
	   message_vision(HIY"\n\n随着莎罗树的湮灭,沙加的也消失了!\n"NOR,ob);     
	   destruct(this_object());
	   
}

void unconcious()
{
  die();
}

int do_none()
{
        object me = this_object();

        message_vision("$N冷笑一声：你[天舞宝轮]阵里，还想有什么花样？\n",me);
        return 1;
}


void wait_time() 
{
	
     
	//  return 1;     
}