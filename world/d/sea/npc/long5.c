// long1.c
// created 6-6-97 pickle

#include <skill.h>
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("螭吻",({"chi wen","chi","wen","long","chiwen","dragon"}));
  set("long","龙生九子不成龙，各有所好：螭吻乃第五子，平生好望。\n");
  set("gender", "男性");
  set("age", 32);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 800);
  set("force", 1100);
  set("max_force", 1100);
  set("force_factor", 70);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",30);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 130);
  set_skill("dodge", 130);
  set_skill("force", 140);
  set_skill("parry", 150);
  set_skill("rake", 150);
  set_skill("spells", 120);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 130);
  set_skill("dragonforce", 100);
  set_skill("skyriver-rake", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("rake","skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonrake");
  carry_object("/d/sea/obj/longzhu5");
}

int accept_fight(object me)
{
  command("ok");
  command("say 那就玩玩吧！");
  command("wield rake");
  return 1;
}

void die()
{
     object me,who,longzhu,longjin;
     string whoid;
	  me=this_object();
	  if(me->query_temp("longzhu_kill"))
	{
	  sscanf(me->query_temp("longzhu_kill"),"%s",whoid);
	  if (!present(whoid,environment()))
	  return ::die();
	  who=present(whoid,environment());
     if((who->query("fangcun/panlong_longgong")=="begin")&&(who->query_temp("fangcun/panlong_longgong_longzhu")!="done")&&(environment()))
	  {
	       message_vision("\n\n$N拱手道："  + RANK_D->query_respect(who) + "武功高强，这颗黄龙珠就送给你了．\n\n",me,who);
           message_vision("$N给$n一颗黄色的龙珠．\n",me, who);
	 	   message_vision(HIC"$N喃喃地念了几句咒语。\n"NOR,me, who);
    	   message_vision(HIC"\n只见$N脚下突然涌起一股水波，水流过后，$N随之不见了！\n"NOR,me,who);
           longzhu=new("/d/sea/obj/longzhu5");
		   longzhu->move(who);
		   destruct(me);
		   return;    
	  }
	}
	 if(me->query_temp("longjin_kill"))
	{
		  whoid=me->query_temp("longjin_kill");
    	  if (!present(whoid,environment()))
        	  return ::die();
	  	  who=present(whoid,environment());
          if((who->query("fangcun/panlong_hell_18")=="done")&&(who->query("fangcun/panlong_hell_longjin")=="begin")&&(environment()))
		{
			  longjin=new("/d/sea/obj/longjin");
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
      ::die();

}





