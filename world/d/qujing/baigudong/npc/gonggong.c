// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("老公公", ({"gong gong", "gong"}));
  set("gender", "男性");
   set("long",@LONG
白发如彭祖，苍髯赛寿星。耳中鸣玉磐，眼里幌金星。
手拄龙头拐，身穿鹤髦轻。数珠掐手中，口诵南无经。
LONG);
  set("age", 90);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set_skill("dodge", 60);
  set_skill("parry", 70);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 65);
  set_skill("gouhunshu", 65);
  set_skill("tonsillit", 70);
  set_skill("ghost-steps", 45);
  set_skill("jinghun-zhang", 75);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 750);
  set("max_kee", 650);
  set("max_sen", 880);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1400);
  set("max_mana", 1000);
  set("force_factor", 65);
  set("mana_factor", 75);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/qujing/baigudong/obj/longtou");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

  if (present("nu zi",where) ||
      present("fu ren",where) ||
      present("gong gong 2",where))
  {
    if (where->query("short") == "山石坡")
    {
      load_object("/obj/empty");
      me->move("/obj/empty");
    }
    call_out ("destruct_me",1,me);  
  }
  else
  {
    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
  }
}

void destruct_me (object me)
{
  destruct (me);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
  return;

  message_vision ("$N对$n说道：唉唉，可见吾小女老妻？\n",me,who);
}

void unconcious()
{
  die();
}

void check_kill(object me,object who)
{
  if (! who ||
      environment(who) != environment(me))
        return;
    who->set_temp("obstacle/killed_num",0);
  if (who->query("obstacles/baigudong")=="done") return;
  if(who->query_temp("obstacle/baigudong_nuzi_killed")) 
         who->set_temp("obstacle/killed_num",who->query_temp("obstacle/killed_num")+1);
  if(who->query_temp("obstacle/baigudong_furen_killed"))
         who->set_temp("obstacle/killed_num",who->query_temp("obstacle/killed_num")+1);
  if(who->query_temp("obstacle/baigudong_gonggong_killed"))
         who->set_temp("obstacle/killed_num",who->query_temp("obstacle/killed_num")+1);
  if(who->query_temp("obstacle/killed_num")>=3) who->set_temp("obstacle/baigudong_yao_killed","done");
  message_vision("\n        突然一阵狂风刮过，顿时乌云蔽日，一股黑气从山石坡的坡顶升起。\n
     隐隐约约看到一个巨大的白骷髅现身其中，只听他一声冷笑，看我怎么收拾你！\n 
       说罢，驾起一阵狂风向西而去!\n",who);
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
    ob->set_temp("obstacle/baigudong_gonggong_killed",1);
  message_vision ("\n$N一声惨叫，翻倒在地上，死了。\n",me);
  command ("drop long tou");
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(where);
  check_kill(me,ob);
    destruct(me);
 //here,baigujing announce her will escape to baigudong
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
 

