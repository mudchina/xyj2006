// created 11/20/1997 by snowcat

inherit NPC;

string *names = ({
  "°×ÍÃ¾«",
  "»ÒÍÃ¾«",
  "ºÚÍÃ¾«",
  "³àÍÃ¾«",
  "»ÆÍÃ¾«",
  "³¤Ã«ÍÃ¾«",
  "¶ÌÃ«ÍÃ¾«",
  "¾íÃ«ÍÃ¾«",
});

void jump_away ();

void create()
{
  set_name(names[random(sizeof(names))], ({ "tu jing", "tu", "jing" }));
  set("long", "Ò»Î»ÍÃÄ£ÍÃÑùµÄÅ®×Ó¡£\n");
  set("gender", "Å®ÐÔ");
  set("age", 20);
  set("attitude", "peaceful");
  set("per", 29);
  set("max_kee", 1800);
  set("max_gin", 1800);
  set("max_sen", 1800);
  set("force", 1800);
  set("max_force", 1800);
  //set("force_factor", 10);
  set("max_mana", 1100);
  set("mana", 1100);
  set("mana_factor", 80);
  set("combat_exp", 2540000);
  set("daoxing", 2000000);

  set_skill("spells", 50);
  set_skill("moonshentong", 90);
  set_skill("unarmed", 140);
  set_skill("baihua-zhang", 135);
  set_skill("dodge", 110);
  set_skill("moondance", 95);
  set_skill("parry", 115);
  set_skill("force", 90);
  set_skill("moonforce", 90);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("dodge", "moondance");
  map_skill("force", "moonforce");
  set("chat_chance_combat", 2);
  set("chat_msg_combat", ({ (: jump_away :) }) );

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void jump_away ()
{
  string s;
  object room;
  object me = this_object();
  
  s = sprintf ("/d/qujing/maoying/shanpo%d.c",random(10)+1);
  room = load_object(s);
  message_vision ("à²µØÒ»Éù£¬$NÏòÍâÌøÈ¥¡­¡­\n",me);
  me->move(room);
  if (present("tu jing 6",environment(me)))
    destruct (me);
  else
    message_vision ("$Nà²µØÒ»ÉùÌøÁË¹ýÀ´¡­¡­\n",me);
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N·­µ¹ÔÚµØ£¬»¹Ô­ÎªÒ»Ö»Ò°ÍÃ£¬ÏòÍâÒ»´Ú¡£\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

ÿ