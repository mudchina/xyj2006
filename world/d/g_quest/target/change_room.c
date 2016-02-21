// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖÞ
// inside2.c
#include "ansi.h"

inherit ROOM;
void init();
void dance(object where);
void finish_dance(object where);
void check_time(object where);
/* void send_drug(object where); */
int do_enjoy();

void create ()
{
  set ("short", "³¤Ë¼¹Ý");
  set ("long", @LONG

·¿ÖÐÖéÁ±µÍ´¹£¬°¸ÉÏÂ¯ÖÐµã×ÅÒ»Êø³ÁÏã£¬ÇáÑÌôÁÈÆ¡£µ±µØ·ÅÖøÒ»ÕÅ»¨Àæ´ó
ÀíÊ¯´ó°¸£¬°¸ÉÏ¶ÑÖø¸÷ÖÖÃûÈË·¨Ìû£¬²¢Ê®Êý·½±¦Ñâ£¬¸÷É«±ÊÍ²£»ÄÇÒ»±ßÉè
Öø¶·´óµÄÒ»¸öÈêÒ¤»¨ÄÒ£¬²åÖøÂúÂúµÄË®¾§ÇòµÄ°×¾Õ»¨¡£Êé°¸ÕýÖÐÁÌ×Å¼¸ÕÅ
¾îÖ½(paper)£¬×Ö¼£¾êÐã£¬ËÆÊÇæÏ¶ð°Ù°ãÎÞÀµÖ®ÖÐËùÍ¿¡

LONG);
   set("item_desc", ([ /* sizeof() == 1 */
  "paper" : "Ö½ÉÏ·´·´¸´¸´µØÐ´×ÅÒ»¾ä»°£ºÌì²»ÀÏ£¬ÇéÄÑ¾ø£¬ÐÄËÆË«Ë¿Íø£¬ÖÐÓÐÇ§Ç§½á¡£
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"huilang.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/change.c" : 1,
 "/d/obj/flower/juhua.c":1,
]));
/* set("valid_startroom",1); */
  setup();
}

void init()
{
   object where=this_object();
   remove_call_out("check_time");        
   check_time(where);
   add_action("do_enjoy","enjoy");
}


void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   
/*
  if(local[3]==1&&(!query("senddrug"))) send_drug(where);
    if(local[3]==2)delete("senddrug");
*/
   if(phase==3&&(!query("dance"))) dance(where);
   if(phase==4&&query("dance")) finish_dance(where);
   call_out("check_time",60,where);
}
void dance(object where)
{
message("channel:es",HIG+"¡¾ÔÂ¹¬¡¿æÏ¶ð(Chang e)£ºÃ®Ê±Õû,¸ÃÁ·ÎèÁË¡£\n"+NOR,users());
   tell_object(where,"æÏ¶ðÇáÌáÉ´È¹£¬»º»º²½ÈëÎè³Ø,Õæ¸öÊÇ£º\n");
   tell_object(where,"ÌìµØÎªÖ®±äÉ«£¬Éñ¹íÎªÖ®¶¯ÈÝ£¡\n");
   tell_object(where,"´ËÎèÖ»ÎªÌìÉÏÓÐ£¬ÈË¼äÄÜÓÐ¼¸»Ø¼û?\n");
   tell_object(where,"²»Í÷ÖíÎòÄÜÒ»·¬³ÕÇé.\n");
   set("dance",1);
     set ("long", @LONG
ÕâÀïÊÇæÏ¶ðµÄ¾ÓËù£¬Ò²ÊÇÏÉ×ÓÁ·ÎèµÄµØ·½£¬ÏÖÔÚÖÜÎ§Ï¡Ï¡À­À­×ø×Å¼¸Î»ÏÉ×Ó,
±»æÏ¶ðµÄÏÉ×ËËùÕÛ·þ£¬ÕýÐÀÉÍ(enjoy)µÄÈç×íÈç³Õ.
LONG);
}

void finish_dance(object where)
{
   tell_object(where,"æÏ¶ð×ß³öÎè³Ø£¬ÇáÑÔµÀ£º½ñÌì¹¦¿Îµ½´Ë½áÊø¡£\n");
   set("dance",0);
     set ("long", @LONG
·¿ÖÐÖéÁ±µÍ´¹£¬°¸ÉÏÂ¯ÖÐµã×ÅÒ»Êø³ÁÏã£¬ÇáÑÌôÁÈÆ¡£µ±µØ·ÅÖøÒ»ÕÅ»¨Àæ´ó
ÀíÊ¯´ó°¸£¬°¸ÉÏ¶ÑÖø¸÷ÖÖÃûÈË·¨Ìû£¬²¢Ê®Êý·½±¦Ñâ£¬¸÷É«±ÊÍ²£»ÄÇÒ»±ßÉè
Öø¶·´óµÄÒ»¸öÈêÒ¤»¨ÄÒ£¬²åÖøÂúÂúµÄË®¾§ÇòµÄ°×¾Õ»¨¡£Êé°¸ÕýÖÐÁÌ×Å¼¸ÕÅ
¾îÖ½(paper)£¬×Ö¼£¾êÐã£¬ËÆÊÇæÏ¶ð°Ù°ãÎÞÀµÖ®ÖÐËùÍ¿¡£
LONG);
}

int do_enjoy()
{
   object me=this_player();
   
   if(me->is_busy())
      return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
   if(!query("dance"))
      return notify_fail("æÏ¶ð»¹Ã»Á·ÎèÄØ£¬ÄãÏëÐÀÉÍÊ²Ã´?\n");
   if((string)me->query("family/family_name")!="ÔÂ¹¬")
      return notify_fail("ÍâÅÉµÜ×Ó²»µÃÀ´ÐÀÉÍ!\n");
     if(me->query("faith")>5000)
      return notify_fail("ÄãµÄÐÞÎªÒÑ¾­×ã¹»¸ß£¬²»ÓÃÔÙÉÍÎèÁË¡£\n");      
   
    tell_object(me,"ÄãÔÚÅÔÎÅÌý£¬ÈôÓÐËùÎò£¬²»½ûÃ¼»¨ÑÛÐ¦¡£\n");
me->start_busy(4+random(1));
  me->add("faith",1);
  me->improve_skill("moonshentong",random((int)(me->query("spi")+me->query("int"))/2),1);
  me->add("combat_exp",30);
  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);   
   tell_object(me,"Äã¾õµÃÔÂ¹¬ÏÉ·¨½ø²½ÁË£¡\n");
   return 1;       
}

/*
void send_drug(object where)
{
    object master=present("chang e",where);
    object daoshi,ob,cart;
    
    if(master){
        set("senddrug",1);
        tell_room(where,"ÔÆÑôÕæÈËËµµÀÓÖÊÇÔÂ³õ£¬¸ÃÍù³¤°²³ÇµÄÒ©ÆÌËÍÒ©²ÄÁË¡£");
        tell_room(where,"ÔÆÑôÕæÈËÌ¾ÁËÒ»¿ÚÆø£¬½Ó×ÅËµµÀÏÖÔÚÑýÄ§ºáÐÐ£¬²»ÖªÄÄÎ»µÜ×ÓÔ¸»¤ËÍÒ©²Ä£¿");
    }
    
    say("Ò»¶ÓÒ©²Ä³µ´ÓÄÚÔºÊ»³ö¡£\n");
        
    ob=new(__DIR__"obj/cart");
    ob->move(where);
    cart=ob;
        
    daoshi=new(__DIR__"npc/drugdao");
    daoshi->move(where);
    daoshi->get_quest(__DIR__"npc/dartway1");
    daoshi->set_cart(cart);
    daoshi->wait_go(where);
        
    ob=new(__DIR__"obj/yaocai");
    ob->move(cart);
}
*/
