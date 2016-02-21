//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("ÀÏ¹«¹«", ({"gong gong", "gong"}));
  set("gender", "ÄÐÐÔ");
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jinghun-zhang", 50);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 700);
  set("max_kee", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("mana", 800);
  set("max_mana", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/qujing/baoxiang/obj/longtou");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
  return;

  message_vision ("$N¶Ô$nËµµÀ£º°¦°¦£¬¿É¼ûÎáÐ¡Å®ÀÏÆÞ£¿\n",me,who);
}

void unconcious()
{
  die();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/sanda_gonggong_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("\n$N·­µ¹ÔÚµØÉÏ£¬ËÀÁË£¬ÏÖ³öÒ»¶Ñ°×¹Ç¡£\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}


void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/sanda/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}
void destruct_me (object me)
{
  destruct (me);
}

/*
void check()
{
  object ob = this_player();
  object rulai;
  int i;
  if(! ob->query("obstacle/wuzhuang") )
    return;
 if (ob->query("combat_exp") < 10000)

    return;
  if (ob->query("obstacle/sanda") == "done")

    return;
  if (! ob->query_temp("kill_girl")||!ob->query_temp("kill_woman") ||
      ! ob->query_temp("man_kill") )
    return;
  i = random(500);
  ob->add("obstacle/number",1);
  ob->set("obstacle/sanda","done");
  ob->add("combat_exp",i+2000);

  rulai = load_object("/d/qujing/lingshan/npc/rulai");

  CHANNEL_D->do_channel(rulai,"chat",ob->query("name")+"»ÛÑÛÊ¶Ñý¾«£¡");
  message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+ob->query("name")+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚÁù¹Ø£¡\n"NOR,users());
  tell_object (ob,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  ob->save();
  remove_call_out("des");
  call_out("destruct",1);
  return;
}*/


