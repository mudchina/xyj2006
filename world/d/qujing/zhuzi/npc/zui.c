// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  reload("zhuzi_zui_fangxiu");
  set_name("×í·½ÐÝ", ({"zui fangxiu", "zui"}));
  set("shop_id", ({"zuifangxiu", "fangxiu", "zui"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 40);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ([
        "jiudai": "/d/obj/food/niupi-jiudai",
        "jiunang": "/d/obj/food/jiunang",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
  call_out ("drinking",2+random(2),this_object());
}

void drinking (object who)
{
  if (random(2))
    command("drink");
  else
    command("drink zui fangxiu");
}
