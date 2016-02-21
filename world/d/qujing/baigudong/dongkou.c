// create by smile 12/8/1998
// °×¹Ç¶´£¬°×¹Ç¾«µÄÆÜÏ¢µØ
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "°×¹Ç¶´");
  set ("long", @LONG
   [1;37m
        $$$                  $$$$$$$$$$$ 
       $ $                   $$       $$           $$$    $$$$$$$$$$$$$$$
      $ $                    $$$$$$   $$            $ $   $$$$$$$$$$$$$$$
     $ $$$$$$$$$$$$$         $$  $$   $$             $$$  $ $         $ $
     $ $$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$             $ $  $$$$$  $ $
     $ $         $ $     $$                $$       $$$   $ $  $$$$$  $ $
     $ $$$$$$$$$$$ $         $$$$$$$$$$$$            $ $  $ $         $ $
     $ $$$$$$$$$$$ $         $ $      $ $             $$$ $ $ $$$$$$$ $ $
     $ $         $ $         $ $$$$$$$$ $                 $ $ $ $ $ $ $ $
     $ $$$$$$$$$$$ $         $ $      $ $             $$$ $ $ $ $$$ $ $ $
     $$$$$$$$$$$$$$$         $ $$$$$$$$ $            $ $  $ $ $$$$$$$ $ $
                             $$$     $$$$           $$$   $$$       $-$ $
                                                          $$$        $$$$
[2;37;0m
      ¶´ÀïÍùÍâºôºôµÄÃ°×ÅºÚÑÌ£¬Ëæ·çÆ®À´ÕóÕóÐÈÎ¶£¬Ñ¬µÃÄãÖ±ÏëÅ»ÍÂ¡£¶´ÃÅ±ßÉÏ
    ¶Ñ×Å¼¸¸ö÷¼÷Ã£¬Ïë±ØÊÇÒ»Ð©±»¶´ÄÚÑý¾«³ÔµôµÄ¹ýÍùÐÐÈËµÄËÀºóËùÁô²Ðº¡¡£
    
LONG);

  set("exits", ([
        "southdown"   : __DIR__"dongting",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
  add_action("do_enter","enter");
}

int do_enter(string arg)  //enter baigudong,must dx>100y,and mana>1800
{
    object me;
  if(!arg) return notify_fail("ÄãÏë½øÊ²Ã´£¿\n");  
  if(arg!="dong"&&arg!="hole"&&arg!="¶´"&&arg!="°×¹Ç¶´")
      return notify_fail("ÄãÏë½øÊ²Ã´£¿\n");  

      me = this_player();
   message_vision("[1;33m$NÉîÎüÁËÒ»¿ÚÆø£¬Äó×¡±Ç×Ó£¬Íù°×¹Ç¶´³åÁË¹ýÈ¥¡£[2;37;0m\n",me);
   if(me->query("obstacle/baigudong")!="done")
    {
   if(me->query_temp("obstacle/baigudong_yao_killed")!="done"||
      me->query("combat_exp")<100000||me->query("max_mana")<1800)
     {
       message_vision("[1;31m$N³åµ½¶´¿Ú£¬Í»È»Ò»ÕóºÚÑÌ¹ö¹ý,¼ÐÔÓ×ÅÒ»¹ÉÑ¬ÈËÐÈÆø¡£\n$N¾ª½ÐÒ»Éù£¬»èµ¹ÔÚµØÉÏ!\n[2;37;0m",me);
       me->unconcious();
       return 1;
     }
    };
   message_vision("[1;35mçÔÈÆµÄºÚÑÌÒ»Åöµ½$N£¬¶ÙÊ±ËÄÉ¢¶øÈ¥\n[1;36m$NÒ»½ÅÌ¤½ø°×¹Ç¶´![2;37;0m\n",me);
     me->move(__DIR__"dongnei"); 
  return 1;     
}
