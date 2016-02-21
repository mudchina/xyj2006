

inherit F_VENDOR_SALE;

void create()
{
  reload("wuji_xiaoer_er");
  set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
  set("shop_id", ({"xiaoer", "xiao", "er", "waiter","er"}));
  set("gender", "男性");
  set("combat_exp", 1000);
  set("age", 26);
  set("per", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set("vendor_goods", ([
    "jiudai": "/d/moon/obj/jiudai",
  ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("silver", 1);
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  switch( random(3) ) {  // 1/3 chance to greet.
    case 0:
      say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
            + "，进来歇歇脚，喝两盅吧。\n");
      break;
  }
}

int accept_object(object who, object ob)
{
  if (ob->query("money_id") && ob->value() >= 300) 
  {
    tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
    who->set_temp("rent_paid",1);
    return 1;
  }
  return 0;
}
