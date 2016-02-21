//Cracked by Roath
//  ÑıÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ºÓ±ß");
  set ("long", @LONG

ºÓ±ß¾¡ÊÇ¿İÄ¾»ÆÍÁ£¬±ğÎŞËûÎï£¬¾¹È»Á¬Ò»Ö»ÂìÒÏÒ²Ã»ÓĞ¡£Ç°·½Á¢
ÁËÒ»¿éÊ¯±®£¬ÉÏĞ´×Å¡°[1;33mÁ÷É³ºÓ[m¡±Èı¸ö´ó×Ö£¬ÏÂÃæÓĞËÄ¾äÕæÑÔ¡°°Ë
°ÙÁ÷É³½ç£¬ÈıÇ§ÈõË®Éî£»¶ìÃ«Æ®²»Æğ£¬Â«»¨¶¨µ×³Á¡£¡±Ô­À´ËÄÖÜ
»ÄÎß¾¹ÊÇÕâÌõºÓËùÖÁ£¡

LONG);
  set("exits", ([
        "westup":   "/d/qujing/village/road1",
        "eastdown"  : __DIR__"river",
        ]));
  set("outdoors","hfd");
  setup();
}
void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        object zhou;
       if(( !(zhou=present("bishui zhou", me))
       ||(string)zhou->query("unit")!="ÕÅ" ) )
       return notify_fail("ÄãÒ»¸öÃÍ×ÓÔúµ½Ë®Àï£®£®£®\n"+
       "\nµ«Ã»¶à»á¶ù¾Í±»±ïµÃ°ëËÀ£¬Ö»ºÃ¸Ï½ôÅÀÉÏ°¶À´¡£\n");

        message_vision(HIY "$N×İÉíÒ»Ô¾£¬Ìø½øÁËÉî½§¡£\n" NOR, me);
        me->move(__DIR__"hedi1");
        message_vision(HIY "$N´Ó½§ÉÏÌøÁËÏÂÀ´¡£\n"NOR,me);
        return 1;
}
