// by mon

inherit NPC;

int say_mifa(object me);
int say_chumo(object me);
int say_qujing(object me);
int do_leave();

void create()
{
  set_name("¶þÀÉÕæ¾ý", ({"er lang","erlang","er"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("long", @LONG
Ëû¾ÍÊÇ´óÃû¶¦¶¦µÄÏÔÊ¥¶þÀÉÕæ¾ý£¬¾Ý´«ÊÇµ±ÄêÓñµÛµÄÃÃÃÃ
Ë¼·²ÏÂ½ç£¬ÓëÑî¾ýËùÉúµÄº¢×Ó¡£Ö»¼ûËû£º

  ÒÇÈÝÇå¿¡Ã²ÌÃÌÃ£¬Á½¶ú´¹¼çÄ¿ÓÐ¹â¡£
  Í·´÷ÈýÉ½·É·ïÃ±£¬Éí´©Ò»Áìµ­¶ì»Æ¡£

LONG
);
  set("combat_exp", 10000000);
  set("daoxing", 5000000);

  set("per", 100);
  set_skill("dodge", 200);
  set("max_sen",1000);
  set("max_gee",1000);
  set("max_gin",1000);
  set("force",1000);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",200);
  set_skill("spells",200);
  set_skill("stick",200);
  set("inquiry",([
    "µÃµÀÃØ·¨": (: say_mifa :) ,
    "µÃµÀ": (: say_mifa :),
    "µÀÐÐ": (: say_mifa :),
    "ÃØ·¨": (: say_mifa :),
    "join": (: say_mifa :),
    "³ýÄ§": (: say_chumo :),
    "½µÑý": (: say_chumo :),
    "È¡¾­ÈË": (: say_qujing :),
    "È¡¾­": (: say_qujing :),
//    "leave": (: do_leave :),
//    "²»Áé": (: do_leave :),
  ]));
  set("chat_chance",2);
  set("chat_msg",({
    "Õæ¾ý×ÔÑÔ×ÔÓïµÀ£ºÕâÇóµÀÖ®Êõ£¬³ýÁËÇÚÑ§¿àÁ·£¬ÈôÄÜµÃÎÒÕâµÃµÀÃØ·¨£®£®£®\n",
    "Õæ¾ý¶ÔÄãËµ£º³ýÄ§½µÑý£¬¿ÉÊÇÄÜµÃµÀÉýÌìµÄ°¡£¡\n",
    "Õæ¾ýËµµÀ£ºµ±½ñÈ¡¾­Ö®·çÈÕÊ¢£¬È¡¾­ÈËÂï£¬ËäËµÁúÉß»ìÔÓ£¬¿É±Ï¾¹£®£®£®\n",
    "Õæ¾ýËµµÀ£ºÎÒÕâ·¨¶ùÒªÊÇ²»Áé£¬¾¡¹ÜÀ´ÕÒÎÒ¡£\n",
  }));

  setup();

}

void init()
{ object me=this_player();
  ::init();
//  add_action("do_agree","agree");
//  add_action("do_listen","listen");
  me->delete_temp("pkgroup");

}

int say_mifa(object dummy)
{ object me=this_player();
  message_vision("¶þÀÉÕæ¾ýºÙºÙÒ»Ð¦£¬Ëµ£º"
  +"ÄãÈôÄÜ¹»É±ËÀÆäËûÇóµÀÖ®ÈË£¬×Ô¿ÉÎüÈ¡ÆäµÀÐÐ£¬»¯Îª¼ºÓÐ¡£\n"
  +"²»¹ýÄãÒ²»á³ÉÎª±ðÈËµÄÄ¿±ê£¬È·ÊÇÐ×ÏÕÒÑ¼«¡£\n",me);
// ÄãÈçÓÐÒâ£¬µ±¸½¶úÉÏÀ´(listen)¡£\n",me);
  me->set_temp("pkgroup/listen",1);
  return 1;
}

int say_chumo(object me)
{
  message_vision("¶þÀÉÕæ¾ýËµµÀ£º"
  +"½µÑý³ýÄ§£¬ÄËÉÏÉÏÖ®µÀ£¬ÈôÄÜÒÀÎÒÖ®ÃØ·¨£¬¶ÔÄãµÄµÀÐÐ¿ÉÊÇ´óÓÐºÃ´¦¡£\n",me);
  return 1;
}

int say_qujing(object me)
{
  message_vision("¶þÀÉÕæ¾ýËµµÀ£º"
  +"ÕâÈ¡¾­Ö®ÈËÄË½ð²õ×Ó»¯Éí£¬ÈôÄÜÒÀÎÒÖ®ÃØ·¨£¬É±¶øÊ³Ö®£¬¿ÉÊÇÊÜÒæ·ËÇ³ÄÄ¡£\n",me);
  return 1;
}

int do_leave()
{
  object me=this_player();
  int gain,lose;

  if(!me->query("kill")) return 0;

//  gain=me->query("pkgroup/gain");
//  lose=me->query("pkgroup/lose");
//  if(gain==1 && lose==1) {
//    message_vision("¶þÀÉÕæ¾ý³¯$N·ÉÆðÒ»½Å£¬ÂîµÀ£º"+
//      RANK_D->query_rude(me)+"ÓÖÃ»ÊÔ¹ý£¬ÔõÖª²»Áé£¿£¡\n",me);  
//  } else {
//    if(5*gain>4*lose) {
    if(me->query("PKS")) {
//      message_vision("¶þÀÉÕæ¾ý¶Ô$NËµ£ºÄãÕâµÀÐÐ²»ÊÇÔö¼ÓÁËÂð£¿Ë­Ëµ²»Áé£¡²»ÄÜÍË¡£\n",me);
        message_vision("¶þÀÉÕæ¾ý¶Ô$NËµ£ºÄãÐÐÐ×É±ÁËÈË£¬ÎÒÒ²²»ÄÜ»¤×ÅÄãÁË£®£®£®\n",
	  me);
    } else {
      message_vision("Õæ¾ý¶Ô$NÌ¾ÁË¿ÚÆø£ºÄãÕâ²»ÖÐÓÃµÄ"+
        RANK_D->query_rude(me)+"£¡Äã×ß°É£¬ÔÙÒ²±ðÀ´¼ûÎÒ£¡\n",me);
//      me->add("combat_exp",-me->query("pkgroup/join_bonus"));
//      if(me->query("combat_exp")<0) me->set("combat_exp",0);
      me->delete("kill");
      me->save();
    }
//  }
  return 1;
}

int do_listen(string arg)
{ object me=this_player();
  if(me->query("pkgroup/gain")) {
    write("¶þÀÉÕæ¾ýºßÁËÒ»Éù£¬Ã»ÀíÄã¡£\n");
    return 1;
  }
  if(me->query_temp("pkgroup/listen")) {
   if(me->query_temp("pkgroup/paid")) {
     message_vision("$NÉÏÇ°×ßÁË¼¸²½£¬Õæ¾ýÔÚ$N¶ú±ßÇÄÉùËµÁËÐ©Ê²Ã´¡£\n",me);
     write("¶þÀÉÕæ¾ýËµ£º´Ó´ËÒÔºó£¬Äã¿ÉÒÔÉ±ËÀwho -kËùÏÔÊ¾µÄÍæ¼Ò£¬²¢"
       +"\nÄÜµÃµ½ËûÃÇµÄÒ»²¿·ÖµÀÐÐ£¬µ±È»£¬ËûÃÇÒ²¿ÉÒÔÉ±ËÀÄã£¬ÄãÍ¬ÒâÂð(agree)£¿\n");
     me->set_temp("pkgroup/agree",1);
   } else {
     message_vision("Õæ¾ý´êÁË´êÊÖÖ¸£¬¶Ô$NÒõÐ¦µÀ£ºÕâÎ»"
     +RANK_D->query_respect(me)
     +"¿ÉÖªÊ²Ã´ÊÇÈËÊÂÂð£¿\n",me);
   }
   return 1;
  } else return 0;
}

int do_agree(string arg)
{  object me=this_player();
   int dx,dx1;

   if(me->query_temp("pkgroup/agree")) {
     message_vision("Õæ¾ý¶Ô$NËµµÀ£ººÃ£¡ÄãºÃ×ÔÎªÖ®°É£¡\n",me);
     me->delete_temp("pkgroup/agree");
     me->set("pkgroup/lose",1);
     me->set("pkgroup/gain",1);

     //temporary bonus for joining pk.
     if(!me->query("pkgroup_left")) {
     dx=me->query("combat_exp");
     dx1=220-dx;
     if(dx1>0) {
       me->set("combat_exp",220);
       me->set("pkgroup/join_bonus",dx1);
       write("ÄãµÄµÀÐÐÔö¼ÓÁË£¡\n");
     }
     }

     me->save();
     return 1;
   }
   return 0;
}

int accept_object (object who, object ob)
{
//  if((!ob)||ob->value()<100000) {
//    message_vision("Õæ¾ýÌ§Í·ÇÆÁË$NÒ»ÑÛ£¬Ã»ËµÊ²Ã´¡£\n",who);
//    return 1;
//  } else {
    who->set_temp("pkgroup/paid",1);
    message_vision("Õæ¾ý³¯$NµãµãÍ·£ºÕâ»¹²î²»¶à¡£\n",who);
    return 1;
//  }
}


ÿ