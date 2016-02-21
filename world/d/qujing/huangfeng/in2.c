//Cracked by Roath

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "¶´ÄÚ");
  set ("long", @LONG

ÕýÇ°·½ÊÇÒ»¸ö¸ßÌ¨£¬»Æ·ç¹ÖÆ½Ê±¶¼ÊÇÔÚÄÇ¸öµØ·½·¢ºÅÊ©Áî£¬
ÕâÒ²ÊÇÎÞÊýÐ¡Ñý¾«ÃÎÏëµÄÊÂÇé£¬ÓÐ³¯Ò»ÈÕ×Ô¼ºÒ²ÄÜÐÞÏÉµÃ
µÀ¡£
LONG);

  set("exits", ([
        "north"   : __DIR__"in3",
        "south": __DIR__"in1",
      ]));
      set("objects",([
        __DIR__"npc/yaojing.c":2,
      ]));
  setup();
}
void init()
{	object obj;
        object ob = this_player();
	string dan= "dingfeng dan";
	
       if (! ob->query_temp("apply/name") 
	||ob->query_temp("apply/name")[0] != "[31m»¨½ÅÎÃ×Ó[m"
	||!objectp(obj = present(dan, ob)))
        {
		
        message_vision(HIY"ºöÈ»»Æ·ç¹Ö´óº°Ò»Éù£ºÔõÃ´Ã»¼û¹ýÕâ¸öÈË£¡\n"NOR,ob);
        message_vision(HIY"Ö»¼û»Æ·ç¹Ö´ó×ìÒ»¹Ä£¬´µÆðÁËÈýÃÁÉñ·ç¡£\n"NOR,ob);
        message_vision(HIY"Ö»¼û$NÈç¿ñ·çÖÐµÄ·çÉ³Ò»Ñù·ÉÉÏÁËÌì¿Õ¡£\n"NOR,ob);
        ob->apply_condition("eyeill",50);
	ob->unconcious();
	ob->set_temp("winded",1);
	
	if( ob->query_temp("lingji1_done") == "yes" )
	{
	ob->move("/d/qujing/huangfeng/shanlu2");
        return;
	}
	ob->move("/d/qujing/huangfeng/shanlu2new");
	}
        return;
}
