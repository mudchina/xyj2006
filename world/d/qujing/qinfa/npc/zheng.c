// by snowcat oct 15 1997


inherit F_VENDOR_SALE;
//inherit F_VENDOR;
//inherit NPC;
void create()
{
  reload("qinfa_zheng_guafu");
  set_name("郑寡妇", ({"zheng guafu", "zheng", "guafu", "fu"}));
  set("shop_id", ({"guafu", "fu"}));
  set("gender", "女性");
  set("combat_exp", 50000);
  set("max_kee", 1000);
  set("kee", 1000);
  set("max_sen", 1000);
  set("sen", 1000);
  set("age", 30);
  set("per", 21);
  set("env/wimpy", 90);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
    "guo" : "/d/qujing/qinfa/obj/guo",
    "wan" : "/d/qujing/qinfa/obj/wan",
    "chong" : "/d/qujing/qinfa/obj/chong",
  ]));
  setup();
  set_temp("no_guo",0);
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}

int buy_object (object who, string item)
{
  object me = this_object ();

  if (item != "guo" &&
      item != "yeshen guo")
  {
    return ::buy_object (who, item);
  }

  if (me->query_temp("no_guo"))
  {
    message_vision ("$N对$n说：“对不起，新野参果待一会才能送来。”\n",me,who);
    return -1;
  }
  me->set_temp("no_guo",1);
  remove_call_out("reset_no_guo");
  call_out("reset_no_guo",900);
  return ::buy_object (who, item);
}

void reset_no_guo ()
{
  set_temp("no_guo",0);
}
