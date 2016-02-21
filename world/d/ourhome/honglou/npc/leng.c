
inherit F_VENDOR_SALE;
void create()
{
  set_name("冷子兴", ({"leng zixing","leng","zixing"}));
  set("title", "古董商");
  set("gender", "男性");
  set("combat_exp", 10000);
  set("age", 46);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set("vendor_goods", ([
      "camera": "/d/obj/misc/camera",
      "mallet": "/d/obj/misc/mallet",
      "buwawa": "/d/obj/misc/buwawa",
      "pillow": "/d/obj/misc/pillow",
    ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  add_money("silver", 5);
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
     remove_call_out("greeting");
     call_out("greeting", 3, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  command ("hmm");
}

