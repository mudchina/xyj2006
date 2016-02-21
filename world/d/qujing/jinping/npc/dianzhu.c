// by snowcat 12/8/1997

inherit F_VENDOR_SALE;

void create()
{
  reload("jinping_dian_zhu");
  set_name("µêÖ÷", ({"dian zhu", "zhu"}));
  set("shop_id", ({"dianzhu", "zhu"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "hulu": "/d/qujing/jinping/obj/hulu",
        "ji": "/d/qujing/jinping/obj/ji",
        "doufu": "/d/qujing/jinping/obj/doufu",
        "mianjin": "/d/qujing/jinping/obj/mianjin",
        "gao": "/d/qujing/jinping/obj/gao",
        "bing": "/d/qujing/jinping/obj/bing",
        "guan": "/d/qujing/jinping/obj/guan",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

