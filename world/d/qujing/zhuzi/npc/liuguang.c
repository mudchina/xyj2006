// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("zhuzi_liu_guangtou");
  set_name("柳光头", ({"liu guangtou", "liu", "boss"}));
  
  set("shop_title","光头柳");
  set("shop_id", ({"guangtou", "liu"}));
  set("gender", "男性");
  set("long", "一位大脑袋面师傅，正顶着一大面团飞快地往滚锅里削面。\n");
  set("combat_exp", 5000);
  set("age", 40);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "jianjiao": "/d/qujing/zhuzi/obj/jianjiao",
        "shuijiao": "/d/qujing/zhuzi/obj/shuijiao",
        "miantiao": "/d/qujing/zhuzi/obj/miantiao",
        "mianpian": "/d/qujing/zhuzi/obj/mianpian",
        "miantang": "/d/qujing/zhuzi/obj/miantang",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  carry_object("/d/obj/weapon/blade/caidao")->wield();
}

void init()
{
    ::init();
  add_action("do_vendor_list", "list");
}

