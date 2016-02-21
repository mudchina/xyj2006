//Cracked by Roath
//yugan.c

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("Óã¸Í", ({"yu gan"}));
        set_weight(1000);
                set("unit", "°Ñ");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N°Ñ$nÎÕÔÚÊÖÖÐ£®\n");

        setup();
}
void init()
{
  add_action("do_fish", "fish");        
}
int do_fish()
{
   object me=this_player();
     string env;
    if( me->query("fish") )
        return notify_fail("ÄãÏÖÔÚ²»ÕýÔÚµöÂð£¿\n");
    if( interactive(me) &&me->query("combat_exp") > 1000000 )
        return notify_fail("Äã»¹ÊÇÈ¥ÕÒµãÆäËüÊÂÇé¸É°É£¬µöÓãÂï£¬¾ÍÈÃ¸øÐ¡±²¸É°É¡£\n");
    if ( time() - me->query("last_fish") < 60 )
        return notify_fail("ÎÒ¿´Äã»¹ÊÇ¹ý»áÔÙÀ´µö°É¡£\n");
    if(me->is_busy())
        return notify_fail("ÄãÕýÃ¦×ÅÄØ£¡\n");
    env=environment(me)->query("short");
    if(env!="[1;33mµöÓãÌ¨[m")
        return notify_fail("ÕâÎ»¿Í¹ÙÊÇ²»ÊÇÍ·ÄÔ·¢ÈÈ£¿\n");
    if((int)me->query("kee") <80)
        return notify_fail("ÄãÏÖÔÚ¾«Éñ×´¿ö²»ºÃ£¬ÊÇµö²»ÉÏÀ´ÓãµÄ£¡\n");
    me->set("fish");
    message_vision( CYN "$N´©ºÃÓã¶ü£¬ÓÃÁ¦Ò»Ë¦£¬°Ñ¹³×ÓË¦µ½ÁËºÓÖÐ¼ä¡£\n" NOR, me);
    me->start_busy(5);
    call_out("zhai1",1,me);
    call_out("zhai2",3+random(2),me);
    call_out("finish_zhai",5,me);
    return 1;
}
void zhai1(object me)
{
   message_vision( GRN "$N¶¢×ÅÓã¸¡£¬µ«ÊÇËüºÃÏó¸ù±¾¾ÍÃ»ÓÐ¶¯¹ý¡£\n"NOR, me);
}
void zhai2(object me)
{
   message_vision( YEL "$N¿´µ½Óã¸¡ºÃÏó¶¯ÁËÒ»ÏÂ£¬×ÐÏ¸¿´£¡ÓÐÓãÉÏ¹³ÁË£¡\n", 
me); 
}
void finish_zhai(object me)
{
   object ob;    
   if ( random(3) == 1) {
   tell_object(me,"Õæµ¹Ã¹£¬ÄãÊ²Ã´Ò²Ã»ÓÐµöÉÏÀ´¡£\n");
   return 0;  }
   if ( me->query("combat_exp") < 1000000 ) {
   if ( me->query("combat_exp") < 10000 )
   ob = new("/d/jz/obj/fish1");
   if ( me->query("combat_exp") < 100000)
   ob = new("/d/jz/obj/fish2");
   else 
   ob = new("/d/jz/obj/fish3");
        }   
   ob->move(environment(me));      
   tell_object(me,"ÄãµöÉÏÁËÒ»Ìõ" + ob->query("name") +"¡£\n");
   me->add("combat_exp",20+random(5));
   me->add("potential",2);
   me->delete("fish");
   me->set("last_fish",time());
}                                                 
