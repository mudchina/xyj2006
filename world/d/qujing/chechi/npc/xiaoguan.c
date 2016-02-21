// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("小管家", ({"guan jia", "jia"}) );
  set("gender", "男性" );
  set("age", 35);

  set("combat_exp", 9500);
  set("str", 25);
  set("attitude","heroism");
  
  set("force_factor",5);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);
  set_skill("unarmed",40);
  set_skill("dodge",40);
  set_skill("parry",40);

  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  carry_object("/d/qujing/chechi/obj/guo");
  carry_object("/d/qujing/chechi/obj/guo");
}

void init ()
{
  object ob = this_player();
  object me = this_object();
  remove_call_out("gives");
  call_out("gives",1+random(4),me,ob);
}

void gives (object me, object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() )
    return;
  me->command_function ("hi "+ob->query("id"));
  me->command_function ("give "+ob->query("id")+" guo");
}
