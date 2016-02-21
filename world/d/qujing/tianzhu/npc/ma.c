// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_ma_laoban");
  set_name("ÂíÀÏ°å", ({"ma laoban", "ma", "laoban"}));
  set("title_id", ({"laoban", "ma"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 90000);
  set("age", 38);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set("vendor_goods", ([
        "fan": "/d/obj/food/rice",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/toujin")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

