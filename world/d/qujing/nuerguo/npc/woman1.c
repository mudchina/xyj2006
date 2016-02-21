// created 4/4/1997 by snowcat

inherit NPC;

void create()
{
  switch (random(3))
  {
    case 0:
    case 1:
    {
      set_name("少妇", ({"woman"}));
      set("age", 27);
      break;
    }
    case 2:
    {
      set_name("中年妇女", ({"woman"}));
      set("age", 38);
      break;
    }
  }
  set("gender", "女性");
  set("combat_exp", 5000);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("chat_chance",30);
  set("chat_msg",({(: random_move :)}));

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  add_money ("coin", 10+random(200));  
}

void init()
{
  object ob;

  ::init();
  if (interactive(ob = this_player()) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting",1,ob);
  }
}

void classified_greeting(object me)
{
  string name = query("name");

  if (me->query("obstacle/nuerguo") == "done")
    return;

  if (me->query("obstacle/nuerguo") == "marriage")
  {
    message_vision (name+"对$N说：大家都在议论你的婚事哩，快去见公主。\n",me);
      return;
  }  

  if (me->query("obstacle/nuerguo") == "company")
  {
    message_vision (name+"认出了$N，说道：哟，公主还在等你作伴呢。\n",me);
      return;
  }  

  if (me->query("obstacle/nuerguo") == "stomachache")
  {
    message_vision (name+"看着$N，忍不住说道：瞧瞧，肚子有点大。\n",me);
      return;
  }
  
  if (me->query("gender") == "女性")
    message_vision (name+"看了$N一眼，吃吃地笑了起来。\n",me);
  else
    message_vision (name+"指着$N笑了起来：又是一个死活要去见公主的。\n",me);
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  switch (random(6))
  {
     case 0:
       classified_greeting (ob);
       break;
  }
}

