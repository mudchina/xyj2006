// jiading.c 家丁

inherit NPC;

void create()
{
  set_name("小童", ({ "xiao tong", "xiaotong", "tong", "xiao"}));
  set("gender", "男性");
  set("age", 7+random(8));
  set("long", "秦府的小童都是自小就打好了武功根底，个个手下都有点功夫。\n");

  set("combat_exp", 4000);
  set_skill("dodge", 20);
  set_skill("unarmed", 20);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}
	
