// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "ÌúÉÈ¹«Ö÷"
inherit NPC;
inherit F_MASTER;

int test_player (object who);

void create()
{
  string dir;
  set_name(NAME, ({"tieshan gongzhu", "gongzhu", "princess"}));
  set("title", "»ğÑæÉ½ºìÂÚÂŞÉ²");
  set("gender", "Å®ĞÔ");
  set("age", 28);
  set("per", 18);
  set("long", "»ğÑæÉ½ÌúÉÈ¹«Ö÷¡£\n");
  set("rank_info/respect", "ºìÂÚ¹«Ö÷");
  set("combat_exp", 400000);
  set("daoxing", 800000);

  set_skill("snowsword", 80);
  set_skill("sword", 80);
  set_skill("dragonfight", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("spells", 80);
  set_skill("dragonstep", 80);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_gin", 1000);
  set("max_kee", 1000);
  set("max_sen", 1000);
  set("force", 1500);
  set("max_force", 1500);
  set("mana", 1500);
  set("max_mana", 1500);
  set("force_factor", 40);
  set("eff_dx",80000);
  set("nkgain",140);
  create_family("´äÔÆÉ½°Å½¶¶´",2,"µÜ×Ó");
  set("inquiry", ([
        "name":   "Äã×ĞÏ¸¿´¿´ÎÒÊÇË­£¡",
        "here":   "ÄãÕÒÍÁµØÈ¥ÎÊ£¡",
        "»ğÑæÉ½": "ºßºß£¬Ö»ÓĞÒ»Ñù·¨±¦ÄÜÕò×¡»ğÑæÉ½¡£",
        "·¨±¦":   "ÎÒºÜÉÙ°Ñ×æ´«¼ÒÕäËæ±ãÔùÓèÍâĞÕ¡£",
        "ÌúÉÈ":   (: test_player :),
      ]));

  setup();
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  carry_object(dir+"obj/skirt")->wear();
  carry_object(dir+"obj/tieshan")->wield();
}

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
}

void announce_success(object who)
{//disabled announce and reward...
  int i;

  if (who->query("daoxing")<4000)
  {
    tell_object (who,"ÄãµÄµÀĞĞ²»¹»£¬Ê²Ã´¶¼Ã»ÓĞµÃµ½£¡\n");
    return;
  }  

  if (who->query("obstacle/firemount") == "done")
  {
    tell_object (who,"ÄãÒÑ¾­¹ıÁËÕâÒ»¹Ø£¬Ê²Ã´¶¼µÃ²»µ½ÁË£¡\n");
    return;
  }  
  i = random(600);
  message_vision (HIY "Ò»ÍÅºìÉ«ÔÆÎíÆ®À´£¬ÏÔÏÖ³ö"+NAME+"¡£\n" NOR,who);
  who->add("obstacle/number",1);
  who->set("obstacle/firemount","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"ÆËÃğÁË»ğÑæÉ½°Ë°ÙÀï´ó»ğ£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ıÎ÷ĞĞÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");
  who->save();
  message_vision (HIY NAME+"»¯ÎªºìÉ«ÔÆÎíÉıÆğ£¬ÏòÄÏ±ßÆ®È¥¡£\n" NOR,who);
}

void return_object (object who, object ob)
{
  command ("give "+who->query("id")+" "+ob->query("id"));
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "palm bone")
  {
    command("shake");
    call_out("return_object",1,who,ob);
    return 1;    
  }

  if (who->query("combat_exp")<4000)
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£ºÄãµÀĞĞ²»¹»£¬Õâ°Å½¶¹ÇÅÂÊÇ¼Ù»õ¡£\n",me,who);
    call_out("return_object",1,who,ob);
    return 1;
  }  

  message_vision ("$N½ÓÏÂ°Å½¶¹Ç£¬¶Ô$nÁ¬ÉùµÀĞ»¡£\n",me,who);
  who->set("obstacle/firemount_bone",who->query("obstacle/firemount_bone")+1);
  if (who->query("obstacle/firemount_bone") > 9)
  {
    call_out("give_tieshan",1,me,who);
  }
  return 1;
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}

void attempt_apprentice(object who)
{
  if (who->query("combat_exp")<4000)
  {
    inform_player ("$NÏò$nÒ¡ÁËÒ¡Í·£ºÄãµÀĞĞ²»¹»£¬¹«Ö÷ÅÂÊÇ½Ì²»ÁËÄã¡£\n",who);
    return;
  }  
  return; // now disabled
  command("recruit " + who->query("id") );
}

void give_tieshan (object me, object who)
{
  object tieshan = present("tie shan",me);
  string msg;

  if (tieshan)
  {
    message_vision ("$N¿àĞ¦Ò»ÏÂ£¬"+
                    "ºÜ²»ÇéÔ¸µØË«ÊÖÅõ³öÌúÉÈ£¬½»¸ø$n¡£\n",me,who);
    tieshan->move(who);
    if (who->query("obstacle/firemount")!="done")
      who->set("obstacle/firemount","won");
  }
  else
  {
    message_vision ("$NÎªÄÑµØËµµÀ£ºÌúÉÈÒÑ¾­ËÍÈËÁË£¬"+
                    "¹«Ö÷ÊµÎŞËûÎïÏàÔù¡£\n",me,who);
  }
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$NËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<4000)
  {
    inform_player (msg+"µÀĞĞ²»¹»£¬¹«Ö÷ÅÂÌúÉÈÉËÁËÄãµÄ¸ù¹Ç£¡\n",who);
    return 1;
  }  

  if (who->query("obstacle/firemount") == "won" ||
      who->query("obstacle/firemount") == "done")
  {
    give_tieshan (me,who);
    return 1;
  }  

  if (who->query("obstacle/firemount") == "fight")
    inform_player (msg+"ÓÖÀ´À²£¿ºÃ£¬¹«Ö÷·îÅã£¡\n",who);
  else    
    inform_player (msg+"Ïë±ØÊÇ¸öË¬¿ìÖ®ÈË£¬¹«Ö÷×îÏ²»¶ÈÈÄÖ£¡\n",who);

  call_out ("fight_player",3,who);
  return 1;
}

void fight_player (object who)
{
  object me = this_object();

  message_vision ("$N¶ÔÖÚÑıÒ»ºÈ£ºÉÁ¿ª£¡\n",me,who);
  who->set("obstacle/firemount","fight");
  command("fight "+who->query("id"));
} 

int accept_fight(object who)
{
  object me;
  me = this_object();

  remove_call_out("check_fight");
  call_out("check_fight", 1, me, who);
  return 1;
}

void player_win (object me, object who)
{
  object tieshan = present("tie shan",me);
  string msg;

  message_vision ("$N´ó¾ªÊ§É«£ººÃÎä¹¦£¡ºÃÎä¹¦£¡\n",me);
  give_tieshan (me,who);
  call_out ("princess_disappear",2,me);
}

void player_lose (object me, object who)
{
  message_vision ("$NÒ»ã¶£¬»ÅÃ¦·ö×¡$n£¬Á¬ÉùËµµÀ£ºÊ§ÀñÊ§Àñ£¡\n",me,who);
  call_out ("princess_disappear",2,me);
}

void check_fight (object me, object who)
{
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  my_kee = me->query("kee");
  whos_kee = who->query("kee");
  my_max_kee = me->query("max_kee");
  whos_max_kee = who->query("max_kee");

  if (me->is_fighting())
  {
    call_out ("check_fight",2,me,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

  if ((my_kee*100/my_max_kee) <= 50)
    player_win (me, who);
  else if ((whos_kee*100/whos_max_kee) <= 50)
    player_lose (me, who);

}

void princess_disappear (object me)
{
  message_vision ("$NÂıÂıµØ»¯ÎªºìÉ«ÔÆÎíÏûÊ§ÁË¡£\n",me);
  destruct (me);
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (me->is_fighting())
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£ºÒ»¸öÒ»¸öµØÀ´£¬²»ÒªÒ»Óµ¶øÉÏ£¡\n",me,who);
    return 1;
  }
  
  if (who->query("obstacle/firemount") == "fight")
  {
    me->set("kee", me->query("max_kee"));
    me->set("eff_kee", me->query("max_kee"));
    return 0; // can fight
  }

  message_vision ("$N¶Ô$nÒ¡Ò¡Í·£ºÒª´ò¼Ü³öÈ¥´ò£¡\n",me,who);
  return 1;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if(arg && present(arg,environment(me))!=me) return 0;
  message_vision ("$NÎü¿ÚÆø£¬±ïºìÁËÁ³ÄîÁË¼¸ÉùÖäÓï¡£\n",who);
  call_out("no_cast",2,who,me);
  return 1;
}

void no_cast(object who, object me)
{
  message_vision ("Ğ¡Ğ¡É½¶´ÀïÏìÆğÒ»Æ¬ÔÓÂÒµÄ»ØÒô£¬$N¿´×Å$nÒ»Ğ¦¡£\n",
                  me,who);
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N³Ã×ÅºÚ°µÉì³öÊÖ¡­¡­Ò»²»Ğ¡ĞÄÃşµ½¹«Ö÷µÄ³¤·¢¡£\n",who);
  call_out("no_steal",2,who,me);
  return 1;
}

void no_steal(object who, object me)
{
  message_vision ("$N°´Şà×¡ĞÔ×Ó£¬¶Ô$nËµ£ºÇë×Ô×ğ×Ô°®×ÔÂÉ¡£\n",me,who);
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if(arg && present(arg,environment(me))!=me) return 0;

  message_vision ("$NºöÈ»ÑÛÂ¶É±»ú£¬²ü¶¶µØº°ÁËÒ»Éù£ºÉ±£¡\n",who);
  call_out("no_kill",2,who,me);
  return 1;
}

void no_kill(object who, object me)
{
  message_vision ("É²ÄÇ¼äÉ½¶´ÀïÖÚĞ¡Ñı·×·×ÉÏ´®ÏÂÌøÎ§×Å$NÂÒ×÷Ò»ÍÅ¡£\n",who);
  message_vision ("Ö»¼û$NÀäÀäµØËµµÀ£º¾²¡­¡­Ò»ÇĞ¶¼°²¾²ÏÂÀ´ÁË¡£\n",me);
}
ÿ
