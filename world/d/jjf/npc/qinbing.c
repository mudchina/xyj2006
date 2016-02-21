// qinbing.c
// created 6-4-97 pickle

inherit NPC;

void create()
{
  set_name("亲兵", ({ "qin bing", "qin", "bing", "qinbing"}));
  set("gender", "男性");
  set("age", 19+random(30));
  set("title", "将军府");
  set ("long", @LONG
这些亲兵都是在沙场上立过无数汗马功劳的强将。
他们不原受封为官，宁肯跟随保护旧主。
LONG);

  set("combat_exp", 160000+random(40000));
  set_skill("blade", 79);
  set_skill("force", 50);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("wuhu-blade", 100);
  set_skill("lengquan-force", 50);
  set_skill("unarmed", 80);
  //map_skill("force", "lengquan-force");
  map_skill("parry", "wuhu-blade");
  set("max_sen", 200);
  set("max_kee", 500+random(200));
  set("force", 400);
  set("max_force", 350);
  set("force_factor", 15);

  create_family("将军府", 3, "蓝");
  setup();

  carry_object("/d/obj/weapon/blade/kandao")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();

  setup();
}
	


