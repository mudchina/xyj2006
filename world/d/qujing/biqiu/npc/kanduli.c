// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("biqiu_kan_duli");
  set_name("¿²¶¼Á¦", ({"kan duli", "duli", "boss"}));
  set("shop_id", ({"kanduli", "duli"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "shaoe": "/d/qujing/biqiu/obj/shaoe",
        "zhengya": "/d/qujing/biqiu/obj/zhengya",
        "baijiu": "/d/obj/food/baijiu",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
