// by snowcat 12/8/1997         

inherit NPC;

void create()
{
  set_name("·½ÕÉ", ({"fang zhang", "zhang"}));
  set("title", "²¼½ğìøËÂ");
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 50000);
  set("daoxing", 100000);

  set("age", 70);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  set("inquiry", ([
    "name" : "²¼½ğìøËÂ·½ÕÉÒ²¡£",
    "here" : "²¼½ğìøËÂÒ²¡£",
    "²¼½ğìøËÂ" : "²¼½ğìøËÂÄË²¼½ğìøËÂÒ²¡£",
    "¹«Ö÷" : "¹«Ö÷£¿Õâ¸ö¡­¡­",
  ]));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/obj/cloth/sengxie")->wear();
  set_temp("no_return",1);
}

void check_king ();
void check_room ();

void init ()
{
  call_out ("check_king",4);
  call_out ("check_room",6);
}

void check_king ()
{
  object me = this_object();
  object king = present ("guo wang",environment(me));

  if (! king)
    return;

  if (! king->query("my_saver"))
    return;

  if (me->query("seen_king"))
    return;

  me->set("seen_king",1);
  call_out ("reset_seen_king",600); 
  message_vision ("$N¼ûµ½$n£¬»ÅÃ¦¸©·ü½Ó°İ¡£\n",me,king);
  message_vision ("$NËµµÀ£º·½ÕÉ´óÊ¦£¬¹«Ö÷ºÎÔÚ£¿\n",king);
  call_out ("following",5,me,king); 
}

void reset_seen_king ()
{
  set("seen_king",0);
}

void following (object me, object king)
{
  message_vision ("\n$N¹òÔÚ$nÃæÇ°Ëµ£ºÔÚìø·¿ÀïÒ²¡­¡­\n",me,king);
  command ("follow "+king->query("my_saver")->query("id"));
}

void check_room ()
{
  object me = this_object();
  object where = environment (me);

  if (where->query("short") != "ºóÔº")
    return;

  if (where->query("is_open"))
    return;

  remove_call_out ("opening");  
  call_out ("opening",1,me,where);  
}

void opening (object me, object where)
{
  if (environment(me) != where)
    return;
  if (where->query("is_open"))
    return;
  where->set("is_open",1);
  where->set("exits", ([
              "north"   : "/d/qujing/tianzhu/siyuan",
              "south"   : "/d/qujing/tianzhu/zhaifang",
              "northwest"   : "/d/qujing/tianzhu/baodian",
              "southeast"   : "/d/qujing/tianzhu/chanfang",
            ]));
  message_vision ("$NÓÃ²ü¶¶µÄÀÏÊÖ²¦¿ªÒ»´ÔÇàÌÙ¡£\n",me);
  message_vision ("$NĞ¡ĞÄµØ½«Ğ¡Ä¾ÃÅ´ò¿ª¡£\n",me);
}
ÿ