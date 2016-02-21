// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("ºü°¢Æß´óÍõ", ({ "huaqi dawang", "huaqi", "dawang", "wang" }));
  set("title", "Ñ¹Áú¶´");   
  set("long", "Ò»Î»Å¤Ñü°ÚÍÎµÄÑ¹Áú¶´ÑýÍõ£¬ÉíÉÏÒþÒþµØ·¢³öºü³ô¡£\n");
  set("gender", "ÄÐÐÔ");
  set("age", 64);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 1400);
  set("max_gin", 1400);
  set("max_sen", 1400);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 60);
  set("max_mana", 1000);
  set("mana", 1000);
  set("mana_factor", 60);
  set("combat_exp", 650000);
  set("daoxing", 800000);

  set_skill("spells", 70);
  set_skill("dao", 70);
  set_skill("unarmed", 75);
  set_skill("puti-zhi", 75);
  set_skill("dodge", 60);
  set_skill("jindouyun", 60);
  set_skill("parry", 65);
  set_skill("force", 60);
  set_skill("wuxiangforce", 60);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
  if ("/d/qujing/pingding/obj/shengreal"->in_mud())
    carry_object("/d/qujing/pingding/obj/shengfake");
  else
    carry_object("/d/qujing/pingding/obj/shengreal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/pingding_huaqi_killed",1);
    call_out ("taishang_appearing",1,ob);
  }
  message_vision ("\n$N·­µ¹ÔÚµØÏÖÁËÕæÉí£¬ÊÇÒ»Ö»ºüÀê¾«¡£\n",me);
  message_vision ("ºüÀê¾«ËÀÁË¡£\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void taishang_appearing (object who)
{
  object taishang = new ("/d/qujing/pingding/npc/taishang");

  taishang->announce_success (who);
  destruct (taishang); 
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

ÿ