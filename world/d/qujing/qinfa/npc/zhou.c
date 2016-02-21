// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  reload("qinfa_zhou_xiaoer");
  set_name("周小二", ({"zhou xiaoer", "zhou", "xiaoer", "xiao", "er"}));
  set("shop_title", "小二");
  set("shop_id", ({"xiaoer", "xiao", "er"}));
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
    "jiudai" : "/d/obj/food/niupi-jiudai",
    "jiunang" : "/d/obj/food/jiunang",
    "egg" : "/d/obj/food/egg",
    "mijiu" : "/d/obj/food/mijiu",
    "kaoji" : "/d/obj/food/kaoji",
  ]));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}
