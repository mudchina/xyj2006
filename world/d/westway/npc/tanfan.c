// created by snowcat on 4/8/1997
// tanfan.c

inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("Ì¯··", ({"tan fan","fan"}));
  set("gender", "ÄÐÐÔ" );
  set("age", 45);
  set("long", "Ò»Î»ÀÁÑóÑóµÄÌ¯··¡£\n");
  set("combat_exp", 1000);
  set("attitude", "peaceful");
  set("per", 15);
  set("vendor_goods", ([
        "roubing"  : "/d/obj/food/roubing",
        "egg"      : "/d/obj/food/egg",
        "jiunang"  : "/d/obj/food/jiunang",
      ]));
  setup();
  add_money ("silver", 5);
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

