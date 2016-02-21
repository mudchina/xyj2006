//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/xiaoyao.c

inherit NPC;

void create()
{
  string str;
  int i = random(4)+1;
  set_name("小妖", ({"xiao yao","yao", "jing"}));
  set("gender", "男性");
  set("age", 20*i);
  set("long","一个守洞的妖精。\n");
  set("combat_exp", 20000*i);
  set("per", 15);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 20*i);
  set_skill("blade", 20*i);
  set_skill("fork", 20*i);
  set_skill("mace", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("rake", 20*i);
  set_skill("stick", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
  str = "/d/qujing/yinwu/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}

void die ()
{
  object me = this_object();
  object where = environment (me);

  if (! present("yao jing 4",where) &&
      where->query("short")=="平台")
  {
    object ob = new (__DIR__"xiaoyao");
    ob->move(where);
    message_vision ("\n只见从前方又跑过来一个小妖。\n",me);   
  }
  destruct (me);  
}

void unconcious ()
{
  die();
}
