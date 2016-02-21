// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("biqiu_lasu_lusi");
  set_name("拉苏律司", ({"lasu lusi", "lusi", "boss"}));
  set("shop_id", ({"lusi"}));
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 40);
  set("per", 44);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 60);
  set("vendor_goods", ([
        "jiezhi": "/d/qujing/biqiu/obj/ring",
        "xiangquan": "/d/qujing/biqiu/obj/neck",
        "wanlian": "/d/qujing/biqiu/obj/wrists",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
