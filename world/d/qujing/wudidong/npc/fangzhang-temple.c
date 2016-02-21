// fangzhang.c
// created by mes, updated 6-21-97 pickle

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("Ô²Çå",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","·½ÕÉ");
  set("gender", "ÄĞĞÔ");
  set("age", 80);
  set("long","Ò»¸ö°×°×ÅÖÅÖµÄÀÏºÍÉĞ£¬ºÍÎôÈÕÀÎ·¿ÄÇÄ£Ñù¼òÖ±ÊÇÅĞÈôÁ½ÈË¡£\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
		   "name" : "ÀÏÄÉÊÇÕâÀïµÄÖ÷³Ö£¬·¨ºÅÔ²Çå¡£\n",
		   "¾®" : "²»ÖªÎªºÍ£¬ÔºÀïÄÇ¿Ú¾®ÓĞÊ±·¢³ö¡°¹¾ßË¹¾ßË¡±µÄ¹ÖÉùÒô£¬\n
ËÂÀïÃ»ÈË»áË®£¬ËùÒÔÒ²ÎŞ·¨ÏÂÈ¥¿´¸öÃ÷°×¡£",
		   "Ê¯¾®" : "²»ÖªÎªºÎ£¬ÔºÀïÄÇ¿Ú¾®ÓĞÊ±·¢³ö¡°¹¾ßË¹¾ßË¡±µÄ¹ÖÉùÒô£¬\n
ËÂÀïÃ»ÈË»áË®£¬ËùÒÔÒ²ÎŞ·¨ÏÂÈ¥¿´¸öÃ÷°×¡£",
		   ]));
  set("chat_chance",2);
  set("chat_msg",({
    "Ô²Çå×ÔÑÔ×ÔÓï£¬ËµµÀ£º¡°ÔºÀïµÄÊ¯¾®ÖĞÁËĞ°ÁË¡£¡±\n",
 }));
  setup();
  carry_object("/obj/cloth")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
}
void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  say(CYN "Ô²ÇåÄîÁËÉù·ğ£¬Ï²µÀ£º¡°Ô­À´ÊÇ¶÷¹«¼İµ½£¬ÇëÉÏ×ø£¬ÇëÉÏ×ø¡£¡±\n" NOR);
}
 

ÿ