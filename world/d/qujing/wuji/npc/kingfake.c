// gao.c

inherit NPC;

void create()
{
  set_name("¹úÍõ", ({"guo wang", "wang", "king"}));
  set("long", "Í·´÷Ò»¶¥³åÌì¹Ú£¬ÑüÊøÒ»Ìõ±ÌÓñ´ø£¬Éí´©Ò»Áì·ÉÁúÎè·ïô÷»ÆÅÛ¡£\n");
  set("title", "ÎÚ¼¦¹ú");
  set("gender", "ÄĞĞÔ");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 500000);

  set("max_kee", 1000);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 10);
  set("max_mana", 800);
  set("mana", 1200);
  set("mana_factor", 30);
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("force", 70);
  set_skill("parry", 70);
  set_skill("fork", 70);
  set_skill("spells", 70);
  set_skill("seashentong", 70);
  set_skill("dragonfight", 70);
  set_skill("dragonforce", 70);
  set_skill("fengbo-cha", 70);
  set_skill("dragonstep", 70);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");
  set("eff_dx",-30000);
  set("nkgain",180);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void autokill (object me)
{ 
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  if (me->is_fighting())
    return;

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  message_vision ("$N¶Ô$n´óºÈÒ»Éù£º¡°Ñı¹ÖÄ§Í·£¬¾¹¸ÒÆÛÊÀµÁÃû±ä×öëŞµÄÄ£Ñù£¡¡±\n",
                  me,king2);
  message_vision ("$NÓë$nÁ¢¿ÌËº´òÁËÆğÀ´£¡\n",me,king2);
  me->kill_ob(king2);
  king2->kill_ob(me);
}

void init ()
{
  autokill (this_object());  
}

void die ()
{
  object me = this_object ();
  object longpao = present("long pao",me);
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  message_vision ("$N·¢³öÒ»Éù³¤³¤µÄ°§Ãù£¬ÔÚ³¾ÍÁÀïÏÖÁËÇàÃ«Ê¨×ÓµÄÔ­Éí£¡\n",me);
  message_vision ("\nÇàÃ«Ê¨×ÓµÉ×ÅÁğÁ§ÕµºìÑÛ£¬´­×Å´ÖÆø¡£\n",me);
  me->set_name("ÇàÃ«Ê¨×Ó", ({"blue lion", "lion"}));
  me->delete("title");
  me->delete("long");
  if (longpao)
    destruct (longpao);  
  me->setup();
  me->remove_all_killer();
  me->set("gin",2000);
  me->set("kee",2000);
  me->set("sen",2000);
  call_out("destruct_me",5,me);

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  king2->announce_success();
}

void destruct_me (object me)
{
  message_vision ("Ò»µÀ½ğ¹âÕÕ×¡$N£¬½«$Nà§µØÒ»ÉùÊÕÈ¥¡£\n",me);
  message_vision ("ÌìÉÏÔ¶Ô¶´«À´ÎÄÊâÆĞÈøµÄĞ¦Éù¡£\n",me);
 
  destruct (me);   
}
ÿ