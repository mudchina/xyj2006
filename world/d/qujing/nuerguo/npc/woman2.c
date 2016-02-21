// created 4/4/1997 by snowcat

inherit NPC;

int is_busy;

void create()
{
  set_name("老妇人", ({"old woman", "woman"}));
  set("age",51);
  set("gender", "女性");
  set("combat_exp", 5000);
  set_skill("unarmed", 15);
  set_skill("dodge", 15);
  set_skill("parry", 15);
  set("chat_chance",10);
  set("chat_msg",({(: random_move :)}));

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  is_busy = 0;
  add_money ("coin", 10+random(200));  
}

void init()
{
  object me;
  me = this_object();

  ::init();
  if (present("xiliang princess", environment(me)))
  {
    remove_call_out ("persuade_princess");
    call_out ("persuade_princess", 3, me);
  }
}

void persuade_princess (object me)
{
  object who;

  who = me->query_temp("help_who");

  if (! who)
    return;
  if (environment(me) != environment(who))
    return;

  if (! present ("xiliang princess",environment(me)))
    return;

  message_vision ("小公主见到$N，怔了一下：您怎么又……\n", me);
  message_vision ("$N在小公主的耳边悄声说了几句话，瞟了$n一眼。\n", me,who);
  command("follow none");
  call_out("check_result",3,me,who);
}

void check_result (object me, object who)
{
  string dir;
  object icedew;

  if (! who)
    return;
  if (environment(me) != environment(who))
    return;

  if (! present ("xiliang princess",environment(me)))
    return;

  if (random(5) == 0)
  {
    message_vision ("只见荧光一闪，小公主从宝座后拿出一东西给$N。\n", me);
    message_vision ("$N赶紧低头道了个万福。\n", me);
/*
    dir = __DIR__;
    dir[strlen(dir)-4] = 0;
*/
    dir = "/d/qujing/nuerguo/";
    icedew = new (dir+"obj/icedew");
    icedew->move(who);
    message_vision ("$N将手上的东西迅速地塞给$n，向外走去。\n", me, who);
  }
  else
  {
    message_vision ("小公主哼哼了几声，无动于衷。\n", me);
    message_vision ("$N赶紧低头谢罪，静悄悄地向外走去。\n", me);
  }
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  me->move(dir+"townb2.c");
  message_vision ("$N走了过来。\n", me);
}

int accept_object (object who, object ob)
{
  string id;
  object me;

  me = this_object();

  id = ob->query("money_id");
  if (! id)
  {
    message_vision ("$N神秘地一笑，摇了一下头。\n", me);
    return 1;
  }

  if (who->query("combat_exp")<2000)
  {
    message_vision ("$N神秘地一笑，摇了一下头。\n", me);
    return 1;
  }

  if (who->query("obstacle/number") == "done")
  {
    message_vision ("$N神秘地一笑，摇了一下头。\n", me);
    return 1;
  }

/*
  if (who->query("obstacle/nuerguo") == "marriage")
  {
    message_vision ("$N神秘地一笑，摇了一下头。\n", me);
    return 1;
  }

  if (who->query("obstacle/nuerguo") == "company")
  {
    message_vision ("$N神秘地一笑，摇了一下头。\n", me);
    return 1;
  }
*/

  if (who->query("obstacle/nuerguo") == "stomachache")
  {
    message_vision ("$N神秘地一笑，摇了一下头。\n", me);
    return 1;
  }
  
  if ( ob->value() < (2000+random(1000))) 
  {
    message_vision ("$N稍微犹豫了一下，又显出一副无动于衷的样子。\n",me);
    return 1;
  }  

  if (is_busy)
  {
    message_vision ("$N两眼有点发直，好象什么都没看见。\n",me);
    return 1;
  }  

  if (random(2) == 0)
  {
    message_vision ("$N向$n点了一下头，想了一想，又突然摇摇头。\n", me, who);
    return 1;
  }  
  is_busy = 1;
  call_out("reset_busy",60);
  message_vision ("$N向四周仔细地看了看。\n", me);
  me->set_temp ("help_who",who);
  command("follow " + who->query("id"));
  return 1;
}

void reset_busy ()
{
  is_busy = 0;
}


