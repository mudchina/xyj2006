// modified by smile 12/12/1998
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("女子", ({"nu zi", "nu", "zi"}));
  set("gender", "女性");
    set("long",@LONG
冰肌藏玉骨，衫领露酥胸。柳眉积翠黛，杏眼闪银星。
月祥容仪俏，天然性格清。体似燕藏柳，声如莺啭林。
LONG);
  set("age", 18);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 480000);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  set_skill("unarmed", 60);
  set_skill("gouhunshu", 60);
  set_skill("tonsillit", 60);
  set_skill("ghost-steps", 60);
  set_skill("jinghun-zhang", 60);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 750);
  set("max_kee", 750);
  set("max_sen", 750);
  set("force", 800);
  set("max_force", 800);
  set("mana", 1200);
  set("max_mana", 850);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/baigudong/obj/mifan");
  carry_object("/d/qujing/baigudong/obj/mianjin");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

  if (present("nu zi 2",where) ||
      present("fu ren",where) ||
      present("gong gong",where))
  {
    if (where->query("short") == "山石坡")
    {
      load_object("/obj/empty");
      me->move("/obj/empty");
    }
    call_out ("destruct_me",1,me);  
  }
  else
  {
    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
  }
}

void destruct_me (object me)
{
  destruct (me);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;
  if (! who ||environment(who) != environment(me))  return;

  if (who && interactive(who))
  {
     message_vision ("$N对$n娇声道：“$p，一路辛苦了，吃点奴家做的米饭吧!\n",me,who);
  }
}

void unconcious()
{
  die();
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
    ob->set_temp("obstacle/baigudong_nuzi_killed",1);
  message_vision ("\n$N一声惨叫，扑翻在地死了。\n",me);
  command ("drop mi fan");
  command ("drop mian jin");
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(where);
  load_object("/obj/empty");
  me->move ("/obj/empty");
  call_out ("continuing",3,me,where);  
}

void continuing (object me, object where)
{
  object laofuren = new (__DIR__"furen");

  laofuren->move(where);
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
 
