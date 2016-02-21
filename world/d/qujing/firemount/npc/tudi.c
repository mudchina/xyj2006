// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("ÍÁµØ", ({"tudi","tu di"}));
  set("gender", "ÄĞĞÔ");
  set("age", 100);
  set("long","×¨¹Ü»ğÑæÉ½·½Ô°°Ë°ÙÀïµÄÀÏÍÁµØÒ¯Ò¯¡£"+
      "Ëû±¾ÊÇÀÏ¾ı¶µÂÊ¹¬ÖĞ¿´Â¯µÄµÀÊ¿£¬ÒòÊ§Ö°¶ø±»·£ÏÂ·²½ç¡£\n");
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("daoxing", 100000);
  set("no_nk_reward",1);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);

}

int allow_search()
{
  object me = this_object();
  object who = this_player();

  who->set_temp("know_palm_bone",1);
  message_vision("$NËµ£º°Å½¶¹Ç¾ÍÔÚ´äÔÆÉ½Àï£¬¿ÉÒÔÈ¥ÕÒ(search)¡£\n",me,who);
  return 1;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "here": "Õâ¶ùÓĞ»ğÑæÉ½£¬ÌúÉÈ¹«Ö÷£¬ÌúÉÈ£¬°Å½¶¹Ç¡£\n",
       "»ğÑæÉ½": "»ğÑæÉ½°Ë°ÙÀï´ó»ğ£¬·²ÈËÊµÊÇ²å³áÄÑ·É¡£\n",
       "ÌúÉÈ¹«Ö÷": "Ëı¾Í×¡ÔÚ´äÔÆÉ½ÖĞ£¬ÕæÊÇÒ»¸öÅ®ÆĞÈø¡£\n",
       "°Å½¶¹Ç": (: allow_search :),
      ]));

  if (interactive(ob = this_player()) && !is_fighting()&&       
     ob->query_temp("push_nixiang")>0)
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }       
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  say ("ÍÁµØ×÷ÁË×÷Ò¾£º²»Öª"+RANK_D->query_respect(ob)+"ÕÙÀÏĞàÀ´ÓĞºÎ¹ó¸É£¿\n");
}

ÿ
