// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("宫妃", ({"gong fei", "fei", "girl"}));
  set("gender", "女性");
  set("combat_exp", 10000);
  set("age", 15);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);

  set("can_sleep",1);
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
}

void check_hair ()
{
  object me = this_object();

  if (me->query("disable_type") == "<睡梦中>" &&
      me->query_temp("disabled"))
  {
    call_out("check_hair",1);
    return;
  }

  if (me->query_temp("has_said"))
    return;

  message_vision ("$N突然下意识地摸了摸头：天呐，脑袋全剃光了！\n",me);
  message_vision ("$N一阵眩晕，差点摔倒在地！\n",me);
  me->set_temp("has_said",1);
}
