// create by snowcat 10/16/1997

inherit NPC;

int give_dan ();

void create()
{
  set_name("»ÆÅÛ¹Ö", ({"huangpao guai", "guai" }));
  set("title","¿üÄ¾ÀÇ");
  set("gender", "ÄĞĞÔ");
  set("age", 120);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 1300);
  set("max_gin", 1300);
  set("max_sen", 1300);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 90);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 560000);
  set("daoxing", 800000);

  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("spells", 90);
  set_skill("force", 90);
  set_skill("gouhunshu", 90);
  set_skill("tonsillit", 90);
  set_skill("ghost-steps", 90);
  set_skill("jinghun-zhang", 90);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-150000);
  set("nkgain",200);
  set("inquiry", ([
       "µ¤": (: give_dan :),
       "ÄÚµ¤": (: give_dan :),
       "ÉáÀû×Ó": (: give_dan :),
       "ÉáÀû×ÓÄÚµ¤": (: give_dan :),
      ]));
  
  setup();
  carry_object("/d/qujing/baoxiang/obj/sppifeng")->wear();
  
}

int give_dan ()
{
  object me = this_object();
  object who = this_player();
  string *names = who->query_temp("apply/name");
  
  if (! names ||
      sizeof(names)==0 ||
      names[0]!="°Ù»¨Ğß")
  {
    message_vision ("$NËµµÀ£ºÄãÊÇºÎĞíÈËÒ²£¿\n",me);
    return 1;
  }
  if (me->query("has_given"))
  {
    message_vision ("$NËµµÀ£º»ë¼Ò£¬ÉáÀû×ÓÄÚµ¤²»ÊÇÒÑÔÚÄã´¦£¿\n",me);
    return 1;
  }
  if (me->query("has_refused"))
  {
    message_vision ("$NËµµÀ£º»ë¼ÒºÃÎŞÀí£¬ÉáÀû×ÓÄÚµ¤²»¸ø¾ÍÊÇ²»¸ø£¬ÔõºÃÎŞÀñÇ¿Çó£¿\n",me);
    return 1;
  }
  if (random(3))
  {
    me->set("has_refused",1);
    message_vision ("$NËµµÀ£º»ë¼Ò£¬ÉáÀû×ÓÄÚµ¤»¹ÊÇ·ÅÔÚÎÒÉí±ßÎªºÃ¡£\n",me);
    return 1;
  }
  else
  {
    object dan = new ("/d/qujing/baoxiang/obj/dan");
    me->set("has_given",1);
    message_vision ("$NËµµÀ£º»ë¼Ò£¬ÎÒÕâ¾Í¸ø¡£\n",me);
    message_vision ("$Nµİ¸ø$nÒ»¿ÅÉáÀû×ÓÄÚµ¤¡£\n",me,who);
    dan->move(who);
    return 1;
  }
}

void init ()
{
  object where = environment (this_object());
  object wife = present("baihua xiu",where);

  ::init();
  if (wife)
    this_object()->set_leader(wife);

  if (where && where->query("short") != "²¨ÔÂ¶´" && wife)
    this_object()->kill_ob(wife);
}

void kill_ob (object ob)
{
  object where = environment (this_object());
  object wife = present("baihua xiu",where);

  ::kill_ob(ob);
  if (! wife)
    return;
  if (wife->query("being_killed"))
    return;

  wife->set("being_killed",1);
  this_object()->kill_ob(wife);
}

void die()
{
  if( environment() )
    message("sound", "\n\n¿üÄ¾ÀÇĞÇà²µØÏòÌì¿Õ·ÉÈ¥¡­¡­\n\n", environment());
  destruct (this_object());
}
ÿ