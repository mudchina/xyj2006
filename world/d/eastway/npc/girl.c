// created 7/17/1997 by snowcat

inherit NPC;

void create()
{
  set_name("浣衣女", ({"girl"}));
  set("gender", "女性");
  set("age", 22);
  set("combat_exp", 1500);
  set_skill("unarmed", 5);
  set_skill("dodge", 5);
  set_skill("parry", 5);
  set("force", 10);
  set("max_force", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  add_action ("do_look","look");
  call_out ("wash",random(2)+2);
  ::init();
}

int wash ()
{
  object where = environment(this_object());

  remove_call_out ("wash");

  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
  call_out ("wash",random(10)+30);
  if (where->query("short") != "仙泉")
  {
    //command ("rascal");
    return 1;
  }
  if (is_fighting())
    return 1;
  switch (random(8))
  {
    case 0:
      command ("remove skirt");
      break;
    case 1:
      command ("wear skirt");
      break;
    case 2:
    case 3:
    case 4:
      command ("cure");
      set("gin",query("max_gin"));
      set("kee",query("max_kee"));
      set("sen",query("max_sen"));
      break;
    case 5:
    case 6:
    case 7:
      command ("bath");
      set("gin",query("max_gin"));
      set("kee",query("max_kee"));
      set("sen",query("max_sen"));
      break;
  }
  return 1;
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  if (
      arg &&
      me == present(arg,environment(me)) &&
      who->query("gender") != "女性" &&
      where && 
      where->query("short") == "仙泉")
  {
    message_vision ("$N朝着$n吃惊地呀了一声，立刻将身体藏入水中。\n",me,who);
    return 1;
  }
  return 0; // to invoke normal look
}

