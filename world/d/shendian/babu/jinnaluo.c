#include <ansi.h>
inherit NPC;

string ask_tianshen();
 
void create()
{
   set_name(HIR"紧那罗"NOR, ({"jinna luo","luo"}));
      set("long", "八部天龙中的紧那罗\n");
       set("title", HIB"八部天龙"NOR);
       set("gender", "女性");
       set("age", 50);
       set("attitude", "peaceful");
       set("per", 10);
       set("max_kee", 3100);
       set("max_gin", 3100);
       set("max_sen", 3100);
       set("force", 3150);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3500);
       set("mana", 3500);
       set("mana_factor", 150);
       set("combat_exp", 4000000);
         set("daoxing", 4000000);
        set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("parry", 300);
        set_skill("spells", 300);
        set_skill("force", 300);
        set("inquiry", ([
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                ]) );
   setup();
        carry_object("/d/obj/cloth/mangpao")->wear();
}
 
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/jinnaluo") == "begin")
              return "我要的东西哪？\n";
        if ( (string)me->query_temp("babu/jinnaluo") == "done")
                return "你不是来过了吗？\n";
  command("say 我可以告诉你众神之殿在哪里！\n");
  command("grin \n");
   command("say 本人略通音律，去帮我找把五弦琴。\n");
  me->set_temp("babu/jinnaluo","begin");
  return "快去快回哦。\n";
}

int accept_object(object me, object ob)
{
  string myname=RANK_D->query_rude(me), thing=(string)ob->query("id");
   if (me->query_temp("babu/jinnaluo") == "begin")
   {
     if (ob->query("id") != "wuxian qin")
    {
      command ("say 这是什么破烂？不要。");
      call_out("dropthing", 1, thing);
      return 1;
    }
  else
    {
      command ("jump "+ me->query("id"));
      command ("say "+myname+"不错嘛。");
      command ("say 真是得来全不费工夫。");
      command ("say 我支持你去众神之殿，不过你还得去问问其他八部。");
      me->set_temp("babu/jinnaluo","done");
      call_out("destroy", 1, ob);
      return 1;
    }
  }
  else
  {
  command ("say 你给我东西干吗？");
  }
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
void dropthing(string thing)
{
  command("drop "+thing);
  return;
}
