inherit NPC;
#include "star.h"
#include "tomud.h"
void get_date();
 
void create()
{
        set_name("穆先生", ({"mu"}));
        set("long", "传说中的白羊宫黄金战士，守护着白羊座,极富正义与智慧的黄金圣斗士，并擅长修理圣衣。
在十二宫之战中，帮助星矢他们领悟第七感。冥界之战中，击败最强的冥斗士之一，地妖
星的巴比隆。 \n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("attitude", "friendly");
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",7800000);
          set("daoxing",7800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "穆先生说道：不知何时能再见到雅典娜！\n"   
        }));
          set_skill("dodge", 250);
          set_skill("force", 250);
          set_skill("parry", 250);
          set_skill("unarmed", 250);
          set_skill("sword", 250);
         set_skill("westsword",250);
  //        set_skill("huangjin-step",250);
		  set_skill("balei",250);
		  set_skill("boxing",250);
         
        set_skill("baiyang", 350);
        map_skill("sword","westsword");
		map_skill("parry","westsword");
		map_skill("dodge","balei");
        map_skill("unarmed","boxing");
        map_skill("spells","baiyang");
         set("max_force", 2000);
         set("force", 4000);
         set("max_mana",3000);
         set("mana",6000);
         set("mana_factor",50);
         set("force_factor", 50);
       set("max_kee", 2000);
       set("max_gin", 2000);
        set("max_sen", 2000);

        setup();
        carry_object(__DIR__"obj/by_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 

void init()
{
        
        object me=this_player();
		::init();
        if (me->query_temp("12gong/cike") != "done")
			{
				
				
				remove_call_out("greeting");
                call_out("greeting", 3, me);
        }
if (me->query_temp("12gong/cike") == "done")
	{
	command("say 好大的胆子,竟敢来刺杀[女神] 雅典娜,先过我这一关！\n");
    kill_ob(me);
    }
}



void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
    
     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
      
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIR"$N双手一挥，一团烈火直冲$n而去！\n",ob,me);

        if(random(2))
        
                {
              message_vision(HIR"$N被$n的烈火烧个焦头焦脸！\n"NOR,me,ob);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIR"$N轻而易举的躲过了$n的攻击！\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N吹了起横笛，顿时一只白羊向$n直冲而去！\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N被白羊撞了个人仰马翻！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N对着白羊大喝一声：停！白羊乖乖从旁边溜开了！\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N运起[星屑旋转功],黄金斗气冲向$n \n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N被[星屑旋转功]击中,顿时血流如注，顷刻染红了全身！\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N看准黄金斗气的方向，纵身跃起，躲过这致命一击！\n"NOR,me);
        }
        break;

  }
 //       if( present(me,environment()) )  return ;

        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");
        
        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        ob->start_busy(3);
        message("chat",PTEXT(HIY+"【黄金十二宫】穆先生(Mu):"+ob->name()+
        "强闯我白羊宫,此人要刺杀女神雅典娜,大家全力截住他!\n"NOR),users());
        ob->set("12gong/baiyang","done");
        ob->add("12gong/number",1);
         ob->add("combat_exp", 10000);
        tell_object(ob,"你赢得了十年道行");
        
        }
       ::die();
}


void greeting(object me)
{
     if( !me || !visible(me) || environment(me) != environment() ) return;
     if(!me->query("12gong/baiyang")) 
	{command("say " + "努力去战斗吧,你的小宇宙在战斗中将得到提升,这里的黄金圣斗士不同于\n"+
		 "你见过的那些东方妖怪,他们利用自身的小宇宙爆发能瞬间提升战斗力,你们要小心.我看我\n"+
		 "只能帮你提高你的盔甲防御力了,要取得黄金圣衣,自己去证明自己的能力吧!\n");
	 me->add_temp("apply/armor",100);
	 message("chat",PTEXT(HIY+"\n\n【黄金十二宫】雅典娜(Athena):"+me->name()+
        "通过白羊宫奖励道行十年!\n\n"NOR),users());
	 me->set("12gong/baiyang","done");
        me->add("12gong/number",1);
   me->add("daoxing", 10000);
        tell_object(me,"你的盔甲防御力增强了\n");
		tell_object(me,"你赢得了十年道行\n");
	    
	}
    
	 me->move("/d/12gong/by2jn1"); 
     tell_object(me,"你被穆先生用意念送出了白羊宫!\n");
}

void unconcious()
{
  die();
}
