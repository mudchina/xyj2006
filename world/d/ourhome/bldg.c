

// Room: /d/city/bldg.c

#include <ansi.h>
inherit ROOM;

/*void init(); */
int do_go(string temp2);
int do_sit(string temp3);

void create()
{

      set("short", "×¡Õ¬Çø");
	set("long", @LONG
ÖÕì¶¼ûµ½ÈËÑÌÁË¡£¿´ÆğÀ´ÕâÊÇÒ»Æ¬Ã»ÓĞ¿¡¹¤µÄ×¡Õ¬Çø¡£
ËÄÖÜÔÓ²İ´ÔÉú¡£³ıÁË¼¸ÌõÔà²»À²ßóµÄĞ¡¹·ÔÚÕâÀï¹äÀ´¹äÈ¥
Íâ£¬»¹ÓĞ¸öÁ³ÉÏ¸Ç×Å¶¥ÆÆ²İÃ±µÄÄĞÈË£¬Õı¿¿ÔÚÒ»Á¾ÀÏÒ¯
³µ(car)ÉÏ´òî§Ë¯¡£ 
LONG
	);

	set("exits", ([
		"north" : __DIR__"kedian3",
	]));
	
    set("item_desc", ([
          "car":"Ò»Á¾ÆÆÆÆÂÒÂÒµÄÀÏÒ¯³µ£¬Ö»ÓĞÁ½¸ö×ùÎ»¡£ \n",
	]));
	                                

	set("objects",([
		__DIR__"npc/driver" : 1,
		]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_go", "drive");
	add_action("do_sit", "sit");
}


int do_go(string arg)
{

	object me;
	object driver; 

	me=this_player();
	if( !objectp(driver = present("driver", environment(me))) )
           {     return notify_fail("Ë¾»úÃ»ÔÚ£¬ÄãµÃµÈ»á¶ù¡££ \n");
           }

      if( !me->query_temp("marks/sit") )  
        {	return notify_fail("Äã»¹Ã»ÉÏ³µÄØ¡£\n");
        }

 
	if (!arg)
	{
		return notify_fail("ÄãÒªÈ¥ÄÄÀï£¿\n");	
	}
	if ( file_size("/u/"+arg+"/workroom.c")<0)
	{
	   message_vision("Ë¾»ú°®´î²»ÀíµØ¶Ô$NËµµÀ£ºÎÒ²»¼ÇµÃ¸½½üÓĞÕâÒ»¼Ò¡£\n",me);
         return notify_fail(""); 
	}

		
	 			
	
	message_vision("Ë¾»úÃÍ²ÈÓÍÃÅ£¬ÀÏÒ¯³µÆ¨¹ÉááÃ°³öÒ»´®ºÚÑÌ£¬ÏòÇ°³åÈ¥¡£\n", me);
      message_vision("$N²îµãÃ»Ë¤³öÀ´¡£\n", me);
	
      me->move("/u/"+arg+"/workroom.c");
      
      message_vision("ºöÌıÒ»Éù´Ì¶úµÄÉ·³µÉù£¬Ö»¼û$NÌÚÔÆ¼İÎí°ã·ÉÁË³öÀ´¡£\n", me);
      this_player()->set_temp("marks/sit",0);
	return 1;
}


int do_sit(string arg)
{

	if ( !arg || (arg != "car") )
		return notify_fail("ÄãÒª×øÊ²Ã´£¿\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("ÄãÒÑ¾­ÉÏ³µÁË¡£\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("ÄãĞ¡ĞÄÒíÒíµØ×ê½ø³µÀï£¬Í·»¹ÊÇ±»ÅöÁËÒ»ÏÂ¡£\n");	
}


