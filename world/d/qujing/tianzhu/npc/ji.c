// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_ji_meier");
  set_name("¼¾Ã·¶ù", ({"ji meier", "ji", "meier"}));
  set("shop_id", ({"jimeier", "ji", "meier"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 20);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "yunxue": "/d/qujing/tianzhu/obj/yunxue",
        "pixue": "/d/qujing/tianzhu/obj/pixue",
        "ji": "/d/qujing/tianzhu/obj/shanji",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

