// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_wei_dasao");
  set_name("Îº´óÉ©", ({"wei dasao", "wei", "dasao", "sao"}));
  set("shop_id", ({"dasao", "sao", "wei"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 30);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "xiancai": "/d/qujing/tianzhu/obj/xiancai",
        "douya": "/d/qujing/tianzhu/obj/douya",
        "huacai": "/d/qujing/tianzhu/obj/huacai",
        "shansun": "/d/qujing/tianzhu/obj/shansun",
        "mogu": "/d/qujing/tianzhu/obj/mogu",
        "muer": "/d/qujing/tianzhu/obj/muer",
      ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

