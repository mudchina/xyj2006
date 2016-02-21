// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  reload("zhuzi_wan_koufu");
  set_name("万口福", ({"wan koufu", "wan"}));
  set("shop_id", ({"wankoufu", "wan", "koufu"}));
  set("gender", "男性");
  set("shop_title", "万口福");
  set("combat_exp", 10000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ([
        "lachang": "/d/obj/food/dishes/dish01",
        "ziji": "/d/obj/food/dishes/dish02",
        "menrou": "/d/obj/food/dishes/dish03",
        "xunyu": "/d/obj/food/dishes/dish04",
        "paigu": "/d/obj/food/dishes/dish05",
        "rousi": "/d/obj/food/dishes/dish06",
        "daxia": "/d/obj/food/dishes/dish07",
        "kaoya": "/d/obj/food/dishes/dish08",
        "sue": "/d/obj/food/dishes/dish09",
        "jiding": "/d/obj/food/dishes/dish10",
        "dusi": "/d/obj/food/dishes/dish11",
        "feipian": "/d/obj/food/dishes/dish12",
        "zhugan": "/d/obj/food/dishes/dish13",
        "cuichang": "/d/obj/food/dishes/dish14",
        "yaohua": "/d/obj/food/dishes/dish15",
        "tourou": "/d/obj/food/dishes/dish16",
        "dongsun": "/d/obj/food/dishes/dish17",
        "doufu": "/d/obj/food/dishes/dish18",
        "fuzhu": "/d/obj/food/dishes/dish19",
        "shucai": "/d/obj/food/dishes/dish20",
        "shourouzhou": "/d/obj/food/dishes/dish21",
        "zhushenggeng": "/d/obj/food/dishes/dish22",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
  remove_call_out ("heheing");
  call_out ("heheing",5+random(10),this_object());
}

void heheing (object who)
{
  if (random(2))
    command("hehe");
  else
    command("bow");
}
