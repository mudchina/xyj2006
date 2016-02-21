// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("卡妙", ({"kamus", "bao ping"}));
        set("long", "冰河的师祖。十二宫之战中为让冰河领悟第七感，被冰河杀死。
富有牺牲精神的黄金圣斗士,守护着水瓶座.\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",55);
        set("per",30);
        set("str",73);
        set("int",64);
        set("combat_exp",10000000);
        set("daoxing",10000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "卡妙说道：不知何时能再见到雅典娜！\n"   
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
        set_skill("renma", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_force", 5000);
        set("force", 10000);
        set("max_mana",7000);
        set("mana",14000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 2100);
        set("max_gin", 2100);
        set("max_sen", 2100);

        setup();
        carry_object(__DIR__"obj/bp_cloth")->wear();
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
        message_vision(HIY"$N高举宝瓶，一真飓风自$n的脚下升起！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"$N根本就控制不住自己，随风升起，然后又重重的摔了下来。！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIW"$N真气下沉，勉强抵御住$n的飓风。\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N突然冲天而去，放出绝对零度的冻气,直逼向你！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N居然被$n的冻气冻伤,全身都僵硬了起来！\n"NOR,me,ob);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIG"$N就地一滚，刹那间地面结出了一层冰。\n"NOR,me,ob);
        ob->start_busy(1);
         }
        break;

        case 2:
        {
        message_vision(HIC"$N举起双手，黄金小宇宙爆发:曙光女神之宽恕！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N被黄金斗气击中,顿时头破血流！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIG"$N听风辨位，躲过了这致命的一击。\n"NOR,me);
         }
        break;

        case 3:
        {
        message_vision(HIW"$N喊了一声：绝对零度！只见一股寒流直袭$n\n"NOR,ob,me);

        if(random(2)==0)
                {
              message_vision(HIW"$N被寒流击中，冻的肢体麻木，似乎要断了一般！\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIW"$N不停的运动自己的身体，以保持一点温暖。\n"NOR,me);
         }
        break;
  }
        if( random(6) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        
		if((ob&&ob->query("12gong/mojie")=="done") && (ob&&ob->query("12gong/baoping")!="done"))
	{
		if (ob->query_temp("12gong/cike") != "done")
		{
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "闯过了第十一宫水瓶座，向黄金战士努力！\n"NOR,users());
        ob->set("12gong/baoping","done");
        ob->add("12gong/number",1);
        ob->add("daoxing", 10000);
        tell_object(ob,"你赢得了十年道行");

        }
         else
		{
			 ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】卡妙(Kamus):"+ob->name()+
        "强闯过了我水瓶宫，就要突破黄金十二宫的防线了！\n"NOR,users());
        ob->set("12gong/baoping","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 10000);
        tell_object(ob,"你赢得了十年道行");
	    }
	   
     }
::die();
}

void unconcious()
{
  die();
}