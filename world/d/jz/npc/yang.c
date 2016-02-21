//Cracked by Roath
 
inherit F_VENDOR_SALE;

void create()
{
  set_name("伙计", ({"huoji"}));
  set("shop_id", ({"huoji"}));
  set("shop_title", "小伙计");
  set("gender", "男性" );
  set("age", 18);
  set("per", 25);
  set("combat_exp", 1000);
	set("daoxing",1000);	
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("per", 15);
  set("vendor_goods", ([
           "fuchen":   "/d/jz/obj/fuchen",
           "dadao" :     "d/jz/obj/dadao",
           "zhujian":     "/d/jz/obj/zhujian",


      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
  ::init();
        add_action("do_vendor_list", "list");
}
