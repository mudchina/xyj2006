#include <ansi.h>

inherit NPC;

void create()
{
        set_name("¹¬±ø", ({ "gong bing", "bing" }) );
        set("gender", "ÄÐÐÔ");
        set("age", 35);
        set("combat_exp", 200000+random(20000));
  set("daoxing", 50000);

        set("attitude", "heroism");

        set("str", 30);
        set("max_kee", 600);
        set("max_gin", 600);
        set("force", 600);
        set("max_force", 600);
        set("force_factor", random(50)+25);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("blade", 80);

        setup();

        carry_object("/d/qujing/baoxiang/obj/wandao")->wield();
        carry_object("/d/qujing/baoxiang/obj/zhanpao")->wear();
}

void check_kill (object me);
void check_follow (object me);

void init()
{
  check_follow (this_player());
  remove_call_out("check_kill");
  call_out("check_kill",1,this_object());
}

void check_follow (object who)
{
  object me = this_object();

  if (who->query_temp("obstacle/baoxiang")!="given_letter")
    return;
  if (me->query("following")!=who->query("id"))
  {
    command("follow "+who->query("id"));
    me->set("following",who->query("id"));
    me->set_temp("no_return",1);
    remove_call_out("remove_no_return");
    call_out("remove_no_return",3600,me);
  }
}

void check_kill (object me)
{
  object where = environment(me);
  object who1 = present ("shan yao 1",where);
  object who2 = present ("shan yao 2",where);
  object who3 = present ("shan yao 3",where);
  object who4 = present ("shan yao 4",where);
  object who5 = present ("shan yao 5",where);
  object who6 = present ("shan yao 6",where);

  if (who1 && (! interactive(who1)))
  {
    if (me->query("killing")==0)
    {
      command ("kill shan yao");
      me->set("killing",1);
    }
    if (who1)
    {
      who1->kill_ob(me);
      me->kill_ob(who1);
    }
    if (who2)
    {
      who2->kill_ob(me);
      me->kill_ob(who2);
    }
    if (who3)
    {
      who3->kill_ob(me);
      me->kill_ob(who3);
    }
    if (who4)
    {
      who4->kill_ob(me);
      me->kill_ob(who4);
    }
    if (who5)
    {
      who5->kill_ob(me);
      me->kill_ob(who5);
    }
    if (who6)
    {
      who6->kill_ob(me);
      me->kill_ob(who6);
    }
  }
}

void remove_no_return(object me)
{
  me->set_temp("no_return",0);
}

ÿ