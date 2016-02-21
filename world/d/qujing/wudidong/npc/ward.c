// ward.c

inherit NPC;

void create()
{
  set_name("ÓüÊØ", ({"ward", "yushou", "monster"}));
  set("long","¿´ÓüµÄÐ¡Ñý£¬°òÀ«ÑüÔ²£¬ÕÅÑÀÎè×¦£¬Í¦ÅÂÈË¡£\n");
  set("gender", "ÄÐÐÔ");
  set("age", 40+random(15));
  set("attitude", "aggressive");
  set("shen_type", 1);
  set("combat_exp", 100000);
  set("daoxing", 150000);

  set_skill("unarmed", 40);
  set_skill("parry", 70);
  set_skill("dodge", 70);
  set_skill("sword", 70);
  set_skill("qixiu-jian", 70);
  set_skill("lingfu-steps", 75);
  map_skill("sword", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("parry", "qixiu-jian");
  set("max_kee", 550);
  
  setup();
  add_money("silver", 20);
  carry_object("/d/obj/weapon/sword/tiejian")->wield();
  carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(1) ) {
  case 0:
    say("ÓüÊØ´óº°£º¾¹¸ÒË½´³½ûµØ£¬É±ÎÞÉâ£¡\n");
    break;
  }
}
ÿ