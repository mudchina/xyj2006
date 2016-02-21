#include <ansi.h>


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_wu_laoban");
  set_name("ÎâÀÏ°å", ({ "wu laoban", "wu", "laoban" }) );
  set("shop_id", ({"laoban"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 200);
  set("max_gin", 200);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  set("vendor_goods", ([
        "zuanjie": "/d/qujing/tianzhu/obj/zuanjie",
        "baijie": "/d/qujing/tianzhu/obj/baijie",
        "jinjie": "/d/qujing/tianzhu/obj/jinjie",
        "baojie": "/d/qujing/tianzhu/obj/baojie",
        "yinjie": "/d/qujing/tianzhu/obj/yinjie",
      ]) );

  setup();

  carry_object("/d/qujing/tianzhu/obj/piyi")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixue")->wear();
  carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

