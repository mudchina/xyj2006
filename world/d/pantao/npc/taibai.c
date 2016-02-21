// created 5/30/1997 by snowcat
#include <ansi.h>

inherit NPC;

#define DEBUG 0

#define MYFILE "/d/pantao/npc/taibai.c"

#define MAXPOSITION 7

#define LEVEL_NONE 0
#define LEVEL_ASKED 1
#define LEVEL_RANKED 2
#define LEVEL_FEAST 3

int interval_set = 0;
string YAOCHI = 0;

void create()
{
  string saying = "Ì«°×½ğĞÇ×ÔÑÔ×ÔÓïµÀ£º";

  set_name("Ì«°×½ğĞÇ", ({"tai bai", "tai", "bai" }));
  set("title", "³¤¸ı");
  set("gender", "ÄĞĞÔ");
  set("age", 10000);
  set("per", 30);
  set("long", "Î÷·½³¤¸ıÌ«°×½ğĞÇ¡£\n");
  set("combat_exp", 10000000);
  set("daoxing", 2000000);

  set_skill("force", 500);
  set_skill("spells", 500);
  set_skill("unarmed", 500);
  set_skill("dodge", 500);
  set_skill("parry", 500);
  set("gin", 50000);
  set("max_gin", 50000);
  set("kee", 50000);
  set("max_kee", 50000);
  set("sen", 50000);
  set("max_sen", 50000);
  set("force", 15000);
  set("max_force", 15000);
  set("mana", 15000);
  set("max_mana", 15000);
  set("force_factor", 1000);
  set("chat_chance",3);
  set("chat_msg",({
    saying+"ÖîÏÉÈç²»Ê¶ÀÏ·ò£¬¿ÉÎÊÎÊÀÏ·òhelpÒ»ÊÂ±ãÊÇ¡£\n",
    saying+"½ìÊ±ó´ÌÒ»á·âÉñÅÅ°ñ¹«¿ªÑçÇë£¬ÈôÊÇÖîÏÉÔÚÏÂ½ç£¬Ê¹accept±ã¿É¡£\n",
    saying+"ÈôÊÇÓĞÒâ´òÌıó´ÌÒ»á·âÉñ°ñ£¬ÇëÎÊ±ãÊÇ¡£\n",
    saying+"ÖîÏÉÈôÏëÈë·âÉñ°ñ£¬ÏÈ´øÀÏ·ò¼ûÌìÉñ£¬ÔÙfightÌôÕ½¡£\n",
    saying+"ÌìÉñµ«»ñÓù×¼ÅÅ¶¨ĞÂ°ñºó£¬·âÉñÌ¨±ãÊÇ°İ°ñÇëÑçÖ®´¦¡£\n",
    saying+"·âÉñÌ¨°İĞÂ°ñºó±ã¿É¸°ó´ÌÒÑç£¬Ê¹feast±ãÊÇÁË¡£\n",
    saying+"ÈôÊÇÖîÏÉÓû»Ø·µÏÂ½çÊ¹back±ã¿É£¬ÀÏ·òÇ×ÉíÏàËÍ¡£\n",
    saying+"ó´ÌÒ»áºóÖîÏÉÈçÓĞÒâĞ»¶÷É¢Ï¯£¬Ê¹finish±¨ÇëÍõÄ¸ÄïÄï¶÷×¼¡£\n",
  }));
  setup();
}

int execute_help();
int execute_ask();
int qualified(object me); 
//More than 1/4 of real players with 10k+ experience is required
//to attend the meeting. Modified by Wuliao

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_exert", "exert");
  add_action("do_perform", "perform");
  add_action("do_bian", "bian");
  add_action("do_confirm", "confirm");
  add_action("do_feast", "feast");
  add_action("do_back", "back");
  add_action("do_finish", "finish");
  set("inquiry", ([
        "here":   "´ËÄËÑş³Øó´ÌÒÔ°Æß´óÌìÉñµî£¬¸÷Â·ÏÉÈËÊ¥ÏÍÌìÉñÄêÄê¾Û´ËÇĞ´èÉñÒÕÁĞ°ñ·âÉñ£¬ÍõÄ¸ÄïÄïËêËêÔÚ´ËÉèó´ÌÒÊ¤»áÑçÇëÖÚÏÉÉñ¡£\n",
        "?":      (: execute_help() :),
        "help":   (: execute_help() :),
        "ó´ÌÒ":   (: execute_ask() :),
        "ó´ÌÒ»á": (: execute_ask() :),
        "ó´ÌÒÑç": (: execute_ask() :),
        "·âÉñ":   (: execute_ask() :),
        "·âÉñ°ñ": (: execute_ask() :),
      ]));
  if (YAOCHI == 0)
  {
    /*
    YAOCHI = __DIR__;
    YAOCHI[strlen(YAOCHI)-4] = 0;
    YAOCHI = YAOCHI + "yaob";
    */
    YAOCHI = "/d/pantao/yaob";
  }
}

string randomize (string *strs)
{
  return strs[random(sizeof(strs))];
}

string get_name (object who)
{
  return who->query("name");
}

string get_respect (object who)
{
    if(!who) return " ";
  return "ÕâÎ»"+RANK_D->query_respect(who);
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"¡ô "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬²»¿ÉËæ±ã¶¯´Ö£¡\n",me,who);
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬²»¿ÉËæ±ãÍıÄîÉ±ÈË£¡\n",me,who);
    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg == "transfer")
    return 0;

  message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                  "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬Ôõ¿ÉËæ±ãÂÒÊ©·¨Êõ£¡\n",me,who);
  return 1;
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "sheqi tai bai" &&
      arg != "sheqi tai" &&
      arg != "sheqi bai")
    return 0;

  message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                  "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬Ôõ¿ÉËæ±ãÂÒÊ©ÄÚ¹¦£¡\n",me,who);
  return 1;
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                  "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬Ôõ¿ÉËæ±ãÂÒÊ©Íâ¹¦£¡\n",me,who);
  return 1;
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                  "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬Ôõ¿ÉËæ±ã¹âÌì»¯ÈÕÊ©µÁĞĞÇÔ£¡\n",me,who);
  return 1;
}

int do_bian(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                  "£¬ÌìÌÃ·ÇÍ¬ÏÂ½ç£¬Ôõ¿ÉËæ±ã±äÈË±ä¹í£¡\n",me,who);
  return 1;
}

int execute_help ()
{
  object who = this_player();
  object me = this_object();

  switch (me->query_temp("pantao/level"))
  {
    case LEVEL_NONE:
    {
      message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                      "ÈôÓĞÒâ´òÌıó´ÌÒ»á·âÉñ°ñ£¬ÇëÎÊ±ãÊÇ¡£\n",me,who);
      break;
    }
    case LEVEL_ASKED:
    {
      message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                      "²»·Á´øÀÏ·òÈ¥¼ûÈÕÔÂ½ğÄ¾Ë®»ğÍÁÌìÉñ£¬"+
                      "ÈôÓĞÒâÌôÕ½Ê¹fight±ãÊÇÁË¡£\n",me,who);
      break;
    }
    case LEVEL_RANKED:
    {
      message_vision ("$NËµµÀ£ºÖîÏÉÖĞÈôÓĞÏÉÈËÒâÓû¼ÌĞøÌôÕ½ÌìÉñ£¬"+
                      "´øÀÏ·òÈ¥¼ûÈÕÔÂ½ğÄ¾Ë®»ğÍÁÌìÉñ±ã¿É¡£\n",me,who);
      message_vision ("$NÓÖ²¹³äµÀ£º·âÉñĞÂ°ñÒÑ»ñÓù×¼ÅÅ¶¨£¬Ò²ÇëĞÂÈÎÌìÉñ"+
                      "Ï¸ÎÊÖîÏÉ£¬ÈôÖîÏÉ½ÔÎŞÒâÔÙÕ½±ã¹²È¥·âÉñÌ¨°İ°ñÇëÑç¡£"+
                      "·âÉñÌ¨ÉÏÊ¹feast±ãÊÇÁË¡£\n",me,who);
      break;
    }
    case LEVEL_FEAST:
    {
      message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                      "ÈôÓĞÒâ»Ø·µÏÂ½çÊ¹back£¬"+
                      "ÈôÓĞÒâ¼¯ÌåĞ»Ñç¹²·µÏÂ½ç£¬Ê¹finish±¨ÇëÍõÄ¸ÄïÄï¶÷×¼¡£\n",
                      me,who);
      break;
    }
  }
  return 1;
}

void reset_interval ()
{
  interval_set = 0;
}

int execute_ask ()
{
  object who = this_player();
  object me = this_object();

  if (who->query("combat_exp")+who->query("daoxing") < 200000)
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "ËäÊÇÏÉ¿Í£¬È´µÀĞĞ²»×ã£¬ÄÑÒÔÊÚÏÉÂ¼·âÌìÉñ¡£\n",me,who);
    return 1;
  }

  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "£¬ÀÏ·òÕıÃ¦ÄÑÒÔ·îÅã¡£\n",me,who);
    return 1;
  }

  if(me->query_temp("pantao/level") < LEVEL_ASKED)
  {
    if (interval_set)
    {
      message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                      "£¬ó´ÌÒÊ¤»áÊ±³½Î´µ½£¬ÇëÏÂ´ÎÔÙÀ´°É¡£\n",me,who);
      return 1;
    }

    message_vision ("$N¶Ô$nËµ£º"+get_respect(who)+
                    "£¬ó´ÌÒÊ¤»áĞëÓĞ·âÉñÅÅ°ñÑİÀñÔÚÏÈ·½¿É£»\n"+
                    "´ËÄË´óÊÂ·ÇÍ¬Ğ¡¿É£¬ÀÏ·òĞëÏÈÆô×àÓñµÛ£¬"+
                    get_respect(who)+"ÈôÔ¸ÒâÇëÊ¹confirm¡£\n",me,who);
    me->set_temp("pantao/confirm",1);
    return 1;  
  }
  // LEVEL_ASKED, LEVEL_RANKED
  if(me->query_temp("pantao/level") < LEVEL_FEAST)
  {
    remove_call_out ("continue_asked");
    call_out ("continue_asked",1,me,who);
    return 1;  
  }
  message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                  "£¬ó´ÌÒ»áÒÑ¾­¿ªÑç¡£\n",me,who);
  return 1;
}

int do_confirm ()
{
  object who = this_player();
  object me = this_object();

  if (! me->query_temp("pantao/confirm"))
    return notify_fail("Ê²Ã´£¿\n");

  me->set_temp("pantao/confirm",0);
  message_vision ("$N»Ø´ğÔ¸Òâ¡£\n",who);

  announce (me,who->query("name")+get_respect(who)+"ÓĞÇëÁË£¡\n");
  message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                  "£¬ÀÏ·òÕâ¾ÍÆô×àÓñµÛ£¬ÑûÇë¸÷Â·ÏÉÈËÊ¥ÏÍÌìÉñÉÏÌìÀ´·âÉñÅÅ°ñ¡£"+
                  "ÔÙ±¨ÇëÍõÄ¸ÄïÄïó´ÌÒÊ¤»áÇëÑçĞÂ¿Í£¡\n",me,who);
  message_vision ("ÏéÔÆÆ®Æğ£¬$NÀëÈ¥¡£\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  remove_call_out ("make_asked");
  call_out ("make_asked",10,me,who);
  return 1;
}

void make_asked (object me, object who)
{
  int i;
  object *list;

  if (!who ||
      !environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("ÏéÔÆÆ®Âä£¬$NÌø³öÔÆÀ´¡£\n",me);
    return;
  }

  announce (me,"ÓñµÛÓùÖ¼£ºÑûÇë¸÷Â·ÏÉÈËÊ¥ÏÍÉÏÌìÀ´·âÉñÅÅ°ñÑİÀñ£¡");
  announce (me,"·â°ñÑİÀñÖ®ºó£¬ÍõÄ¸ÄïÄï¶÷Éèó´ÌÒ´ó»áÇëÑçĞÂ¿Í£¡\n");
  announce (me,"ÖîÎ»ÏÂ½çÏÉÏÍÈôÏë¸°»á£¬Ê¹accept tai baiã¿É£¬ÀÏ·òÇ×ÉíÏàÓ­£¡\n");

  interval_set = 1;
  call_out ("reset_interval", 28800); // 8h
  me->set_temp("no_return",1);
  me->set_temp("pantao/level",LEVEL_ASKED);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("ÏéÔÆÆ®Âä£¬$NÌø³öÔÆÀ´¡£\n",me);
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);

  me->set_temp("invite","public");
  list = users();
  i = sizeof(list);
  while  (i--)
  {
    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    list[i]->set_temp("accept",0);
  }
  remove_call_out ("inviting");
  call_out ("inviting",1,me);
}

void continue_asked (object me, object who)
{
    if(!who) return;

  message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                  "¿É´øÀÏ·òÈ¥¼ûÆßÎ»ÌìÉñ£¬"+
                  "Èô¾õºÏÒâ±ã¿ÉÓëÌìÉñ»áÕ½¡£\n",me,who);
  message_vision ("$N»º²½¸úÉÏ£¬¾ö¶¨Óë$nÍ¬ĞĞ¡£\n",me,who);
  who->set_leader(me);
  me->set_leader(who);
}

void inviting (object me)
{
  int i;
  object *list;

  if (me->query_temp("pantao/level") == LEVEL_NONE)
    return;

  if (DEBUG)
    return;

  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  if (me->query_temp("pantao/is_busy"))
  {
    return;
  }

  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (environment(list[i])->query("unit")) // not a room
      continue;
    if (list[i]->is_fighting())
      continue;
    if (list[i]->is_busy())
      continue;
    if (list[i]->query_temp("no_move"))
      continue;
    if (list[i]->is_ghost()) // Checking a ghost or not. 
      continue;
    if (!living(list[i]))
      continue;
    if ((string)list[i]->query_temp("accept")!=me->query("id"))
      continue;

    list[i]->set_temp("accept",0);
    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    message_vision("$NËµµÀ£ºÇëÉÔºò£¬ÀÏ·ò·îÖ¼Ó­½Ó"+list[i]->query("name")+
                   "¸°»á£¬¼´·µ¡£\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set_temp("pantao/from",there);
    message_vision("Ò»ÍÅÏéÔÆÆ®Æğ£¬$N·ÉÈ¥¡­¡­¡£\n",me);
    //me->move(there);
    message_vision("Ö»¼ûÒ»ÍÅÏéÔÆÆ®ÏÂ£¬Ì«°×½ğĞÇ´ÓÀïÃæ×ß³ö¡£\n",list[i]);
    message_vision("Ì«°×½ğĞÇ¶Ô$NËµµÀ£ºÀÏ·ò·îÖ¼Ó­½Ó$N¸°»á£¡\n",list[i]);
    message_vision("ÏéÔÆÓµ×ÅÌ«°×½ğĞÇºÍ$NÌÚ¿Õ¶øÆğ£¬ĞìĞì·ÉÈ¥¡­¡­¡£\n",list[i]);
    //me->move(here);
    list[i]->move(here);
    message_vision("¡­¡­ÏéÔÆĞìĞì½µÂä£¬$NºÍ$n´ÓÀï×ß³ö¡£\n",me,list[i]);
    list[i]->set_leader(me);
    break;
  }
}

int execute_approve_fight(object who, object ob)
{
  object *all, *list, *inv;
  int i, j;
  object me = this_object();

  if (who->query("combat_exp")+who->query("daoxing") < 100000)
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "µÀĞĞ²»×ã£¬²»¿ÉÍıÓëÌìÉñ½ÏÁ¿¡£\n",me,who);
    return 0;
  }
  all = users();
  i = sizeof(filter_array(all, (:qualified:))); //modified by wuliao
  list = all_inventory(environment(me));
  j = sizeof(filter_array(list, (:qualified:))) - 1;
  // only interactive players count.

  if ((i/4-j) > 0 && (! DEBUG)) 
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£ºÎ÷ÓÎ¼ÇÏÖÓĞ"+chinese_number(i)+"Î»¸ßÊÖ£¬"
                    "´Ë´¦½öÓĞÊıÎ»ÏÉÏÍÔÚÑû£¬"+
                    get_respect(who)+"¿É·ñÔÙÑû"+chinese_number(i/4-j)+
                    "Î»ÏÉÏÍ¸°»á£¿\n",me,who);
    return 0;
  }
  announce (me,"·âÉñ°ñÑİÀñ£º"+who->query("name")+"Óë"+ob->query("name")+
            "ÓÚ"+environment(me)->query("short")+"Õù°ñ½ÏÁ¿£¡\n");
  
  me->set_temp("pantao/is_busy",1);
  me->set_leader(0);
  return 1;
}

int execute_fight_result (object who, object ob, int success)
{
  object me = this_object();
  int i, y, d, h;

  reset_eval_cost();
  call_out("reset_is_busy",5,me);

  if (! success)
    return 1;
  if (!ob)
    return 1;
  if (!present(ob, environment(me)))
    return 1;

  announce (me,ob->query("name")+environment(me)->query("short")+
            "´óÕ½"+who->query("name")+"£¬¶á°ñ»ñÊ¤£¡\n");
  announce (me,"ÀÏ·ò³Ï·îÓùÖ¼£¬·â"+ob->query("name")+"Îª"+
            who->get_honor_str()+"£¡\n");
  i = ob->query("pantao/wins")+1;
  ob->set("pantao/wins",i);
  i = (10 + MAXPOSITION - who->get_position_int())*(999+random(9))/i;
  ob->add("daoxing",i);
  y = i/1000;
  d = (i - y*1000) / 4;
  h = (i - y*1000 - d*4) * 3;
  if (y > 0)
    tell_object(ob,"ÄãµÄµÀĞĞÔö¼ÓÁË"+chinese_number(y)+"Äê"+
                chinese_number(d)+"Ìì"+chinese_number(h)+"Ê±³½£¡\n\n");
  else if (d > 0)
    tell_object(ob,"ÄãµÄµÀĞĞÔö¼ÓÁË"+
                chinese_number(d)+"Ìì"+chinese_number(h)+"Ê±³½£¡\n\n");
  else if (h > 0)
    tell_object(ob,"ÄãµÄµÀĞĞÔö¼ÓÁË"+
                chinese_number(h)+"Ê±³½£¡\n\n");
  me->set_temp("pantao/current_player",ob->query("id"));
  me->set_temp("pantao/level",LEVEL_RANKED);
  message_vision ("$NÂúÁ³Ğ¦ÈİµØËµµÀ£ºÈô»¹ÓĞÏÉÈËÒâÓû¼ÌĞøÌôÕ½ÌìÉñ£¬"+
                  "¾Í´Ë´øÀÏ·òÈ¥¼ûÌìÉñ¡£\n",me);
  message_vision ("$NÓÖµÀ£ºÓñ»Ê´óµÛÓù×¼·âÉñĞÂ°ñ£¬ĞÂÈÎÌìÉñ$n"+
                  "¿ÉÑ¯ÎÊÖîÏÉ¸÷Î»£¬Èç½ÔÎŞÒâÔÙÕ½¿ÉÒ»Í¬·âÉñÌ¨°İ°ñÇëÑç¡£"+
                  "È¥ÁË·âÉñÌ¨ÉÏÊ¹feast±ã¿É¡£\n",me,ob);
  message_vision ("$N»º²½¸úÉÏ£¬¾ö¶¨Óë$nÍ¬ĞĞ¡£\n",me,ob);
  me->set_leader(ob);
  return 1;
}

void reset_is_busy(object me)
{
  me->set_temp("pantao/is_busy",0);
}

int is_tian_shen (object who)
{
  int i;

  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = __DIR__"tian"+sprintf("%d",i);
    object ob = find_object(npc);
    reset_eval_cost();
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob->query("current_player") == who->query("id"))
      return 1;
  }
  return 0;
}

int do_feast ()
{
  object me = this_object();
  object who = this_player();

  message_vision("$NÇëÇó$n±ü±¨ÍõÄ¸¿ªÑç¡£\n",who,me);
  if (me->query_temp("pantao/level") == LEVEL_FEAST)
  {
    message_vision ("$NËµµÀ£ºó´ÌÒ»áÒÑ¾­¿ªÊ¼ÁË¡£\n",me);
    return 1;
  }
  if (me->query_temp("pantao/level") != LEVEL_RANKED)
  {
    message_vision ("$NËµµÀ£º·âÉñĞÂ°ñÉĞÎ´Óù×¼£¬ÀÏ·òÔõ¸Ò¾ª¶¯ÍõÄ¸ÄïÄï¡£"+
                    "$n¿É·ñÔ¸ÓëÆß´óÌìÉñ½ÌÁ¿£¿"+
                    "ÈôÊÇÓ®ÁË£¬ÀÏ·òÁ¢¿Ì×àÇëÓñ»Ê´óµÛÓù×¼¡£\n",me,who);
    return 1;
  }
  if (! is_tian_shen(who))
  {
    message_vision ("$NËµµÀ£º$n·ÇÌìÉñÒ²£¬¿É·ñÇëĞÂÈÎÌìÉñÀ´°İ°ñÇëÑç£¿\n",me,who);
    return 1;
  }
  if (environment(me)->query("short")!="·âÉñÌ¨")
  {
    message_vision ("$NµÀ£ºÖîÏÉ¸÷Î»¿É·ñÍ¬È¥·âÉñÌ¨ÏÈ°İ°ñÔÙÇëÑç£¿\n",me);
    return 1;
  }
  message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                  "£¬ÀÏ·òÕâ¾Í±ü±¨ÇëÍõÄ¸ÄïÄïó´ÌÒÊ¤»áÇëÑçĞÂ¿Í£¡\n",me,who);
  message_vision ("ÏéÔÆÆ®Æğ£¬$NÀëÈ¥¡£\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move ("/obj/empty");
  remove_call_out ("make_feast");
  call_out ("make_feast",5,me,who);
  return 1;
}

void make_feast (object me, object who)
{
  int i;
  object *list;

  if (!environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("ÏéÔÆÆ®Âä£¬$NÌø³öÔÆÀ´¡£\n",me);
    return;
  }

  announce (me,"ÖÚÏÉÈËÏÍÊ¥ÌìÉñ·âÉñÌ¨°İ°ñ£¡\n");
  announce (me,"ÍõÄ¸ÄïÄï¶÷×¼¿ªÉèó´ÌÒ´ó»áÇëÑçĞÂ¿Í£¡\n\n");

  me->set_temp("pantao/level",LEVEL_FEAST);
  me->set_leader(0);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("ÏéÔÆÆ®Âä£¬$NÌø³öÔÆÀ´¡£\n",me);

  remove_call_out ("execute_start_feast");
  call_out ("execute_start_feast",1,me);
}

void execute_start_feast (object me)
{
  int i;
  object *list;

  message_vision ("$NËµµÀ£ºÇëÖîÎ»ÏÉÏÍ¸úÀÏ·òÈ¥Ñş³Ø±¦¸ó¡£\n",me);
  me->set_temp("no_return",0);
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");
  //command ("north");

  message_vision("Ö»¼ûÒ»ÍÅÏéÔÆÂıÂı¾ÛÆğ£¬ÄãºÍÖÚÉñĞìĞì·ÉÆğ¡­¡­¡£\n",me);
  list = all_inventory(environment(me));
  i = sizeof(list);
  message_vision("¡­¡­ÏéÔÆ»º»º½µÏÂ¡£\n",me);
  while  (i--)
  {
    reset_eval_cost();
    if (!interactive(list[i]))
      continue;

    list[i]->move(YAOCHI);
    message_vision("$N´ÓÏéÔÆÖĞ×ßÁË³öÀ´¡£\n",list[i]);
  }
  message_vision("$NÌ¤³öÏéÔÆ£¬ÏéÔÆÂıÂıµØÉ¢ÁË¡£\n",me);
  me->move(YAOCHI);
  me->set_temp("pantao/is_busy",1);
  remove_call_out ("continue_feast");
  call_out ("continue_feast",10,me);
}

void continue_feast (object me)
{

  command ("sigh");

  message_vision ("$NËµµÀ£ºÖîÎ»Ï¢Å­£¬ÍõÄ¸ÄïÄïÕıÔÚ´ó·¢Æ¢Æø²»ÄÜÖ÷Ñç¡£\n",me);
  //message_vision ("$NÓÌÒÉÁËÒ»ÏÂÓÖËµµÀ£º¡­Ñ©±ªÕâØË¡­°Ñó´ÌÒÈ«¶¼Íµ³ÔÁË£¡\n",me);

  remove_call_out ("give_gifts");
  call_out ("give_gifts",2,me);
  remove_call_out ("bring_girls");
  call_out ("bring_girls",5,me);
  remove_call_out ("auto_activities");
  call_out ("auto_activities",10,me);
  remove_call_out ("auto_gifts");
  call_out ("auto_gifts",20,me);
  remove_call_out ("auto_guests");
  call_out ("auto_guests",30,me);
  remove_call_out ("auto_signs");
  call_out ("auto_signs",40,me);
  remove_call_out ("end_feast");
  call_out ("end_feast",300,me);
  remove_call_out ("execute_auto_finish");
  call_out ("execute_auto_finish",600,me);
}

void give_gifts (object me)
{
  int i;
  object *list;

  list = all_inventory(environment(me));
  i = sizeof(list);
  while  (i--)
  {
    object ob = list[i];
    object xianyao = new ("/d/obj/food/xianyao");
    object xianzhi = new ("/d/obj/food/xianzhi");
    reset_eval_cost();
    if (!interactive(ob))
      continue;
    if (me == ob)
      continue;

    xianyao->move(ob);
    xianzhi->move(ob);
    message_vision("$N¸ø$nÒ»½ğÍë"+xianyao->query("name")+
                   "Ò»Óñºø"+xianzhi->query("name")+"¡£\n",me,ob);
  }
}

void bring_girls (object me)
{
  string *strs = ({
    "×ßÁË½øÀ´",
    "×ß½øÀ´Ê©ÁË¸öÀñ",
    "½øÀ´Ê©Àñ",
    "½øÀ´ÏòÄãÊ©Àñ",
    "½øÀ´¶Ô×ÅÄãÊ©ÁË¸öÀñ",
  });
  object where = environment(me);
  int i;
  string room_dir;

/*
  room_dir = __DIR__;
  room_dir[strlen(room_dir)-4] = 0;
*/
  room_dir = "/d/pantao/";
  message_vision ("ÍâÃæº°µÀ£º²ÊÒÂÏÉÅ®µ½£¡\n",me);
  for (i = 1; i <= 7; i++)
  {
//    string room = room_dir+"ting"+sprintf("%d",i);
    string npc = room_dir+"npc/xiannu"+sprintf("%d",i);
    object ob;

    reset_eval_cost();;
//    me->move(room);
//    ob = present("xian nu",environment(me));

//    if (! ob)
      ob = new (npc);

//    message_vision ("$N×ßÁË³öÈ¥¡£\n",ob);
//    ob->set("previous_location",room);
    if(ob->move(where))
      message_vision ("$N"+randomize(strs)+"\n",ob);
  }
//  me->move(where);
}

void auto_activities (object me)
{
  string *strs = ({
    "Ò»°àÏÉ¶ğÔÚ¸èÉùÖĞôæôæÆğÎè",
    "¼¸Î»ÃÀ¼§ºÍ×Å½ÚÅÄÇáÇá³ª×ÅÆğ¸è",
    "Ò»ÕóÕó·ïóïÓñ¹ÜÀÖÉùçÎç¿",
    "·ç´µÀ´£¬Ñş³ØÄÚÇíÏãçÔÈÆ",
    "¾Æ¹ÙËÍÀ´Ò»Ğ©ÏÉ¾Æ",
    "ÏÉÅ®¶Ë½øÀ´¼¸ÅÌÏÉÌÒ",
    "Ò»Î»ÏÉ×Ó½øÀ´·îÉÏÏÉÈïÏÉ»¨",
    "ÏÉ×ÀÉÏµÄÇí½¬ÓñÒºÉ¢·¢×ÅÒ»Õó¾ÆÏã",
    "ÏÉÅ®³ªµÀ£º°ëºì°ëÂÌÅç¸ÊÏã",
    "ÏÉÅ®³ªµÀ£ºÑŞÀöÏÉ¸ùÍòÔØ³¤",
    "ÏÉÅ®³ªµÀ£º¿°Ğ¦ÎäÁêÔ´ÉÏÖÖ",
    "ÏÉÅ®³ªµÀ£ºÕùÈçÌì¸®¸üÆæÇ¿",
    "ÏÉÅ®³ªµÀ£º×ÏÎÆ½¿ÄÛå¾ÖĞÉÙ",
    "ÏÉÅ®³ªµÀ£ºç½ºËÇåÌğÊÀÄªË«",
    "ÏÉÅ®³ªµÀ£ºÑÓÊÙÑÓÄêÄÜÒ×Ìå",
    "ÏÉÅ®³ªµÀ£ºÓĞÔµÊ³Õß×Ô·Ç³£",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  message_vision (randomize(strs)+"\n",me);
  remove_call_out ("auto_activities");
  call_out ("auto_activities",20+random(20),me);
}

void auto_gifts (object me)
{
  object where = environment(me);
  object ob, who, gift;
  object *list;
  int i;
  string room_dir;
  
/*
  room_dir = __DIR__;
  room_dir[strlen(room_dir)-4] = 0;
*/
  room_dir = "/d/pantao/";
  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  list = all_inventory(environment(me));
  for (i = 0; i < 100; i++)
  {
    reset_eval_cost();
    ob = list[random(sizeof(list))];
    if (ob->query("id") == "xian nu")
      break;
    ob = 0;
  }
  if (! ob)
  {
    int j = random(7);
//    string room = room_dir+"ting"+sprintf("%d",j);
    string npc = __DIR__"xiannu"+sprintf("%d",j);

//    me->move(room);
//    ob = present("xian nu",environment(me));

//    if (! ob)

      ob = new (npc);
    if(ob->move(where))
      message_vision ("$N×ßÁË¹ıÀ´¡£\n",ob);
//    me->move(where);
  }
  for (i = 0; i < 100; i++)
  {
    who = list[random(sizeof(list))];
    if (interactive(who))
      break;
    who = 0;
  }
  if (who)
  {
    if (random(2))
      gift = new ("/d/obj/drug/xiantao");
    else
      gift = new ("/d/obj/drug/xianjiu");
    gift->move(who);
    message_vision ("$N¸ø$nÒ»"+gift->query("unit")+
                    gift->query("name")+"\n",ob,who);
  }
  remove_call_out ("auto_gifts");
  call_out ("auto_gifts",30+random(30),me);
}

void auto_guests (object me)
{
  string name;
  int i;
  string *names = ({
    "ÆĞÌá×æÊ¦",
    "ÔÆÑôÕæÈË",
    "æÏ¶ğ",
    "¹ÛÒôÆĞÈø",
    "»İ°¶Ê¹Õß",
    "µØ²ØÍõÆĞÈø",
    "°×ÎŞ³£",
    "ºÚÎŞ³£",
    "ÇØÇí",
    "¶«º£ÁúÍõ°½¹ã",
    "ÄÏº£ÁúÍõ°½ÇÕ",
    "±±º£ÁúÍõ°½Ë³",
    "Î÷º£ÁúÍõ°½Èò",
    "Ì«ÉÏÀÏ¾ı",
    "³à½Å´óÏÉ",
    "ÍĞËşÀîÌìÍõ",
    "ÄÄß¸",
    "ÌÆÈı²Ø",
    "ËïÎò¿Õ",
    "Öí°Ë½ä",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  for (i = 0; i < 100; i++)
  {
    reset_eval_cost();
    name = randomize(names);
    if (! me->query_temp("pantao/invited_"+name))
      break;
    name = "none";
  }
  if (name == "none")
    return;

  me->set_temp("pantao/invited_"+name,1);
  message_vision ("Ö»ÌıµÃÔ¶Ô¶Ò»Éù£º"+name+"Ç°À´¸°Ñç£¡"+"\n",me);
  remove_call_out ("continue_guests");
  call_out ("continue_guests",3+random(3),me,name);
  remove_call_out ("auto_guests");
  call_out ("auto_guests",40+random(40),me);
}

void continue_guests (object me, string name)
{
  string msg;
  int i;
  string *msgs = ({
    "ÎÅ·ç¶øÀ´¸°Ñç£¬µ«ÒòÍòÊÂ²øÉí£¬²»±ã¾ÃÁô£¡",
    "Ç°À´Ğ»Ñç£¬¾Í´Ë¸æ´Ç£¡",
    "×¨³ÌÇ°À´±í¾´£¬²»±ã¾ÃÁô£¬¸÷Î»ÓĞÇë£¡",
    "´ËÄËÇ°À´ÉêĞ»£¬¸æ´ÇÁË£¡",
    "ÌØÀ´±í¾´£¬ÎŞÒâ¾ÃÁô£¡",
    "´Ò´Ò¸ÏÀ´Ö»ÎªĞ»Ñç£¬²»ÄÜ´«±­£¬Ê§ÀñÁË£¡",
  });

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  message_vision (name+"×ßÁË½øÀ´¡£\n",me);
  message_vision (name+"ËµµÀ£º"+name+randomize(msgs)+"\n",me);
  message_vision (name+"×ßÁË³öÈ¥¡£\n",me);
}

void auto_signs (object me)
{
  string str;
  string *strs = ({
    "Ìì¿ÕÔ¶´¦ÒşÒşÔ¼Ô¼Ï¼¹âÍòµÀ£¬ºÃÏóÌìÉÏÓĞÊ²Ã´Ê¢´óÑç»á¡­¡­",
    "ÌìÉÏËÆºõÍÅÍÅÈğÆøÆ®¹ı¡­¡­",
    "Äã»Ğã±¿´¼ûÌì¹â²ÓÀÃ£¬ºÃÏóÓĞÊ²Ã´ÖØ´ó½ÚÈÕ¡­¡­",
    "Ò»ÕóÕó·ç´µÀ´£¬´«À´ÌìÉÏ·ïóïÓñ¹ÜµÄÉùÒô¡­¡­",
    "ÌìÉÏ´«À´¶Ï¶ÏĞøĞøµÄÒôÀÖÉù¡­¡­",
    "ÄãºÃÏóÌı¼ûÌìÉÏ½ğÖÓÆëÃù¡­¡­",
  });
  int i;
  object *list;

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
    return;

  if (DEBUG)
    return;

  str = randomize(strs);
  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (!living(list[i]))
      continue;

    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    tell_object(list[i],str+"\n");
  }
  remove_call_out ("auto_signs");
  call_out ("auto_signs",60+random(60),me);
}

void end_feast (object me)
{
  me->set_temp("pantao/is_busy",0);
  message_vision ("$NËµµÀ£ºÖîÎ»ÏÉÏÍ£¬ÈôÓĞÒâ»Ø·µÏÂ½çÊ¹back±ãÊÇ£¬ÀÏ·òÏàËÍ¡£"+
                  "ÈôÓĞÒâ¼¯ÌåĞ»Ñç¹²·µÏÂ½ç£¬¿ÉÈÃĞÂÈÎÌìÉñÊ¹finish"+
                  "ÇëÍõÄ¸ÄïÄï¶÷×¼¡£\n",me);
}

int execute_back(object me, object who)
{
  object here = environment(me);
  object there, there1;

  if(!who) return 1;
  
  there = load_object("/d/city/kezhan");
  there1 = load_object("/d/city/kezhan");

  if (!there)
    there = there1;

  if (here == there)
    return 1;

  who->set_temp("accept",0);
  message_vision("Ö»¼ûÏéÔÆÆ®Æğ£¬$NºÍ$nÌÚ¿Õ¶øÆğ£¬ÂıÂı·ÉÈ¥¡­¡­¡£\n",me,who);
  //me->move(there);
  if(!who->move(there1))
      who->move(there1);
  message_vision("Ö»¼ûÒ»ÍÅÏéÔÆÆ®ÏÂ£¬Ì«°×½ğĞÇºÍ$N´ÓÀïÃæ×ß³ö¡£\n",who);
  message_vision("Ì«°×½ğĞÇ¸´ÓÖ×İÆğÏéÔÆ»º»º·ÉÀë¡£\n",who);
  //me->move(here);
  message_vision("¡­¡­ÏéÔÆ·É»Ø£¬$N´ÓÀïÃæ×ß³ö¡£\n",me);
  
  return 1;
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$NÇëÇó$n¼İÔÆËÍ$N»Ø·µ¡£\n",who,me);
  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "£¬ÀÏ·òÕıÃ¦£¬Ê§ÀñÁË¡£\n",me,who);
    return 1;
  }
  execute_back (me,who);
  
  return 1;
}

int do_finish ()
{
  object me = this_object();
  object who = this_player();

  message_vision("$NÇëÇó$n±ü±¨ÍõÄ¸Ğ»Ñç¼¯Ìå»Ø·µ¡£\n",who,me);
  if (me->query_temp("pantao/is_busy"))
  {
    message_vision ("$N¶Ô$nÒ¡Ò¡Í·£º"+get_respect(who)+
                    "£¬ÀÏ·òÕıÃ¦£¬Ê§ÀñÁË¡£\n",me,who);
    return 1;
  }

  if (me->query_temp("pantao/level") != LEVEL_FEAST)
  {
    message_vision ("$NËµµÀ£ºó´ÌÒ»áÉĞÎ´¿ªÊ¼£¬ÀÏ·òÔõ¸Ò¾ª¶¯ÍõÄ¸ÄïÄï¡£\n",me);
    return 1;
  }
  if (! is_tian_shen(who))
  {
    message_vision ("$NËµµÀ£º$n·ÇÌìÉñÒ²£¬¿É·ñÇëĞÂÈÎÌìÉñÀ´Ğ»Ñç£¿\n",me,who);
    return 1;
  }
  if (environment(me)->query("short")!="Ñş³Ø")
  {
    message_vision ("$NµÀ£ºÕâÀïÄË·ÇÑş³Ø£¬ÈçºÎĞ»Ñç£¿\n",me);
    return 1;
  }
  message_vision ("$N¶Ô$nËµµÀ£º"+get_respect(who)+
                  "£¬ÀÏ·òÕâ¾Í±ü±¨ÇëÍõÄ¸ÄïÄï£¡\n",me,who);
  message_vision ("ÏéÔÆÆ®Æğ£¬$NÀëÈ¥¡£\n",me);
  //me->set("env/invisibility",9);
  me->set_temp("pantao/reappear",environment(me));
  load_object("/obj/empty");
  me->move ("/obj/empty");
  remove_call_out ("make_finish");
  call_out ("make_finish",3,me,who);
  return 1;
}

void make_finish (object me, object who)
{
    if(!who) return;

  if (!environment(who) ||
      environment(who) != me->query_temp("pantao/reappear"))
  {
    me->move(me->query_temp("pantao/reappear"));
    message_vision ("ÏéÔÆÆ®Âä£¬$NÌø³öÔÆÀ´¡£\n",me);
    return;
  }

  announce (me,"ó´ÌÒ´ó»áĞ»Ñç£¬ÍõÄ¸ÄïÄïËÍ¿Í£¡\n\n");

  //me->set("env/invisibility",0);
  me->move(me->query_temp("pantao/reappear"));
  message_vision ("ÏéÔÆÆ®Âä£¬$NÌø³öÔÆÀ´¡£\n",me);

  me->delete_temp("pantao");
  me->delete_temp("invite");
  remove_call_out ("execute_finish");
  call_out ("execute_finish",1,me);
}

void execute_auto_finish (object me)
{
  if (me->query_temp("pantao/level") != LEVEL_FEAST)
  {
    return;
  }

  announce (me,"Ê±³½ÒÑµ½£¬ó´ÌÒ´ó»áĞ»Ñç£¬ÍõÄ¸ÄïÄïËÍ¿Í£¡\n\n");

  me->delete_temp("pantao");
  me->delete_temp("invite");
  remove_call_out ("execute_finish");
  call_out ("execute_finish",1,me);
}

int execute_finish (object me)
{
  int i, j;
  object *list;

  if (me == 0)
    me = this_object();
 
  list = all_inventory(environment(me));
  i = sizeof(list);
  while  (i--)
  {
    reset_eval_cost();
    if (!interactive(list[i]))
      continue;
    if (me == list[i])
      continue;

    j = random(100)+1;
    list[i]->add("potential",j);
    tell_object(list[i],"ÄãµÄÇ±ÄÜÔö¼ÓÁË"+chinese_number(j)+"µã£¡\n"); 
    call_out ("execute_back",i*2,me,list[i]);
  }
  remove_call_out ("send_back_girls");
  call_out ("send_back_girls",1,me);
}

void send_back_girls (object me)
{
  int i;
  object where;
  object *list;

  list = all_inventory(environment(me));
  i = sizeof(list);
  while (i--)
  {
    reset_eval_cost();
    if (interactive(list[i]))
      continue;
    if (list[i]->query("id") != "xian nu")
      continue;
//    if (where = query("previous_location"))
//      list[i]->move(where);
//    else
      destruct (list[i]);
  }
}

int qualified(object me)
{
	if(!interactive(me))
		return 0;
	if(wizardp(me))
		return 0;
    if(me->query("daoxing") < 10000)
		return 0;
	return 1;
}

ÿ
