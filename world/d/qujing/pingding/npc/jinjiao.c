// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("½ð½Ç´óÍõ", ({ "jinjiao dawang", "jinjiao", "dawang", "wang" }));
  set("title", "Á«»¨¶´");   
  set("long", "Ò»Î»ÉñÌ¬°ÁÈ»µÄÁ«»¨¶´ÑýÍõ¡£\n");
  set("gender", "ÄÐÐÔ");
  set("age", 56);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 1800);
  set("max_gin", 1800);
  set("max_sen", 1800);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 80);
  set("max_mana", 1200);
  set("mana", 1200);
  set("mana_factor", 80);
  set("combat_exp", 950000);
  set("daoxing", 1000000);

  set_skill("spells", 90);
  set_skill("dao", 90);
  set_skill("unarmed", 95);
  set_skill("puti-zhi", 95);
  set_skill("dodge", 80);
  set_skill("jindouyun", 80);
  set_skill("parry", 95);
  set_skill("force", 90);
  set_skill("wuxiangforce", 90);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
  if ("/d/qujing/pingding/obj/hulureal"->in_mud())
    carry_object("/d/qujing/pingding/obj/hulufake");
  else
    carry_object("/d/qujing/pingding/obj/hulureal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);

  if (ob)
  {
    ob->set_temp("obstacle/pingding_jinjiao_killed",1);
    call_out ("taishang_appearing",1,ob);
  }
  message_vision ("\n$NÎÞ¿ÉÄÎºÎµØÏÖÁËÕæÉí£¬Ô­À´ÊÇÌ«ÉÏÀÏ¾ýµÄ½ð½ÇÍ¯×Ó¡£\n",me);
  message_vision ("\n½ð½ÇÍ¯×Ó¾ÏÁË¸ö¹ª£ºÊ±³½ÒÑµ½£¬È¥¼ûÌ«ÉÏÀÏ¾ýÒ²¡£\n",me);
  message_vision ("½ð½ÇÍ¯×ÓÍùÍâ±¼È¥",me);
  if (fabao)
  {
     message_vision ("£¬¶ªÏÂÒ»Ö»$n¡£\n",me,fabao);
     fabao->move(environment(me));
  }
  else
    message_vision ("¡£\n",me);
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