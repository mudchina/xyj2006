// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_xiner_niang");
  set_name("ÐÁ¶ùÄï", ({"xiner niang", "xiner", "niang"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 28);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "luweigan": "/d/qujing/tianzhu/obj/luweigan",
        "youzhagan": "/d/qujing/tianzhu/obj/youzhagan",
        "chougan": "/d/qujing/tianzhu/obj/chougan",
        "doufugeng": "/d/qujing/tianzhu/obj/doufugeng",
        "lucha": "/d/qujing/tianzhu/obj/lucha",
        "hongcha": "/d/qujing/tianzhu/obj/hongcha",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/yinjie")->wear();
  carry_object("/d/qujing/tianzhu/obj/yunxue")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

