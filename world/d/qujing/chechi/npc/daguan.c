// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("¹Ü¼Ò", ({"guan jia", "jia"}) );
  set("gender", "ÄÐÐÔ" );
  set("age", 35);

  set("combat_exp", 9500);
  set("str", 25);
  set("attitude","heroism");

  set("force_factor",2);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);

  set_skill("unarmed",50);
  set_skill("dodge",50);
  set_skill("parry",50);
  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("coin", 50+random(50));
}

void init ()
{
  object ob = this_player();
  object me = this_object();
  if (random(2))
    return;
  remove_call_out("gives");
  call_out("gives",1+random(5),me,ob);
}

void gives (object me, object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() )
    return;
  me->command_function ("hi "+ob->query("id"));
  me->command_function ("give "+ob->query("id")+" coin");
}
