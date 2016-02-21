// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  reload("qinfa_qian_guafu");
  set_name("Ç®¹Ñ¸¾", ({"qian guafu", "qian", "guafu", "fu"}));
  set("shop_id", ({"guafu", "fu"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
    "kuang" : "/d/obj/misc/kuang",
    "shaozhou" : "/d/obj/misc/shaoba",
    "bag" : "/d/obj/misc/bag",
  ]));
  setup();
  carry_object("/d/qujing/qinfa/obj/dao");
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}
