// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("biqiu_kusi_kusi");
  set_name("库司库司", ({"kusi kusi", "kusi", "boss"}));
  set("shop_id", ({"kusi"}));
  set("shop_title", "库司");
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "tangmian": "/d/qujing/biqiu/obj/tangmian",
        "niutang": "/d/qujing/biqiu/obj/niutang",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
