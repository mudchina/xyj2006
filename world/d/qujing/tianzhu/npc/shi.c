// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_shi_laoban");
  set_name("史老板", ({"shi laoban", "shi", "laoban"}));
  set("shop_id", ({"laoban", "shi"}));
  set("shop_title", "老板");
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "zhulan": "/d/qujing/tianzhu/obj/zhulan",
        "zhulou": "/d/qujing/tianzhu/obj/zhulou",
        "zhupa": "/d/qujing/tianzhu/obj/zhupa",
        "zhubian": "/d/qujing/tianzhu/obj/zhubian",
        "zhudao": "/d/obj/weapon/blade/zhudao",
        "zhujian": "/d/obj/weapon/sword/zhujian",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

