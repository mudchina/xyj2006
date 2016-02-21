//Cracked by Roath
 

inherit NPC;
#include <ansi.h>

void create()
{
          set_name("黄风怪", ({"huangfeng guai","yao guai","guai"}));
          set("long","一个身高六丈的妖怪，手中执一把三股叉。\n");
          set("gender", "男性");
          set("age", 50);
          set("combat_exp", 800000);
          set("daoxing", 800000);
          set("per", 20);
          set("str", 30);
          set("max_kee", 3000);
          set("max_sen", 1000);
          set("force", 3000);
          set("max_force", 1500);
          set("force_factor", 80);
          set("max_mana", 1000);
          set("mana", 1600);

          set_skill("unarmed", 120);
          set_skill("dodge", 120);
          set_skill("force", 120);
          set_skill("parry", 120);
          set_skill("fork", 150);
          set_skill("spells", 150);
  
          set_skill("mihouxinjing", 150);
          set_skill("wuxing-quan", 120);
          set_skill("dragonforce", 190); 
          set_skill("fengbo-cha", 150);
          set_skill("dragonstep", 180);
          set_skill("puti-zhi",120);
          map_skill("spells", "mihouxinjing");
          map_skill("unarmed","wuxing-quan");
          map_skill("force", "dragonforce");
          map_skill("fork", "fengbo-cha");
          map_skill("parry","fengbo-cha");
          set("class","dragon");
          setup();
          add_money("gold", 10);
         carry_object("/d/qujing/huangfeng/obj/fork")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
   remove_call_out("checking");
  call_out("checking",3,this_object());
}
void destruct_me (object me)
{
  destruct (me);
}

void checking(object me)
{
  object obj;
  string dan= "dingfeng dan";
  object ob = query_temp("my_killer");
  if (!objectp(obj = present(dan, ob)))
  {
  object where = environment(me);
  object room = load_object("/d/kaifeng/tieta");
  message_vision(HIY"只见黄风怪大嘴一鼓，吹起了三昧神风。\n"NOR,ob);
  message_vision(HIY"只见$N如狂风中的风沙一样飞上了天空。\n"NOR,ob);
  ob->apply_condition("eyeill",50);
  ob->move(room);
  }
  return ;
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
    ob->set_temp("obstacle/hfg_killed",1);
    call_out ("lingji_appearing",1,ob);
  }
  message_vision(HIM"只见黄风怪摔倒在地，现了本形。原来是只黄毛貂鼠！\n"NOR,ob);
  message_vision(HIM"天上传来灵吉菩萨的声音：孽畜！还不跟我回去伏法。\n"NOR,ob);
         call_out ("destruct_me",3,me);
}
void lingji_appearing (object who)
{
  object lingji = new ("/d/qujing/huangfeng/npc/lingji");

  lingji->announce_success (who);
  destruct (lingji); 
}
void unconcious ()
{
  die ();
}
