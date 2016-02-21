// rewritten by snowcat on 4/12/1997

inherit F_VENDOR_SALE;

void create()
{
  reload("firemount_vendor");
  set_name("小贩", ({"vendor"}));
  set("shop_id", ({"xiaofan", "vendor"}));
  set("gender", "男性");
  set("age", 18);
  set("long","一位少年男子，正推着一辆红车儿。\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
  set_skill("dodge", 30);
  set("vendor_goods", ([
         "watermelon" : "/d/obj/food/watermelon",
         "kaoji"       : "/d/obj/food/kaoji",
         "putaogan"    : "/d/obj/food/putaogan",
         "hulu"        : "/d/obj/food/hulu",
         "jiudai"      : "/d/obj/food/niupi-jiudai",
       ]) );
  set("chat_chance",40);
  set("chat_msg",({ 
        "卖西瓜！～～\n",
        "卖烤鸡！～～\n",
        "卖葡萄干！～～\n",
        "卖葫芦！～～\n",
        "卖酒袋！～～\n",
        (:random_move:)
      }));
  setup();

  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 500);

}

void init()
{
  object ob;

  ::init();
  add_action("do_vendor_list", "list");
}

