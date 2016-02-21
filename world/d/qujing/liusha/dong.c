//Cracked by Roath
//  ÑıÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.7

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "ºÚ¶´");
  set ("long", @LONG

Ë®Á÷ÕıÔÚÒÔÓÚÂ×±ÈµÄËÙ¶ÈĞ¹Ïòµ×¶Ë£¬Ë®Á÷µÄÇãĞ¹²úÉúÁË¾Ş´óµÄÎüÒıÁ¦£¬
Ææ¹ÖµÄÊÇ£¬ĞıÎĞµÄÖĞ¼ä¾¹È»Á¢×ÅÒ»¸ùÊ¯Öù£¬Ë®Á÷Ëæ×ÅÊ¯Öù´ò×ª£¬²»¶Ï
µÄÏÂĞ¹¡£Èç¹û²»ÊÇÕâ¸ùÊ¯Öù£¬´ó¸ÅĞ¹¿ÚÔç±»ÌîÉÏÁË¡£Ğ¹¿ÚÏÂÃæÉî²»¼û
µ×£¬Èç¹ûÄã²»Æ´Ãü£¨[1;35mout[m£©µÄ»°£¬¹À¼ÆÂíÉÏ¾ÍÒªµ½ÕæÕıµÄµØÓüÁË£¡£¡

LONG);
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("down");
        call_out("down",2,ob);
        add_action("do_out","out");
}
int do_out()
{
    object ob = this_player();

    string place = "/d/qujing/liusha/hedi1";
    place[strlen(place)-1] = '0'+random(11);

    message_vision(HIC"Ö»¼û$NÊÖ½Å²¢ÓÃ£¬ÈÌ×ÅÌÛÍ´£¬·ÜÁ¦µØÑØ×ÅÊ¯ÖùÏòÉÏÅÀ¡£\n"NOR,ob);
    ob->move(place);
    return 1;
}

void down(object ob)
{

        message_vision(HIW"$N¾õ×Ô¼ºµÄÉíÌåÒÑ¾­½û²»×¡ĞıÎĞµÄÎüÒıÁË£¬$NºÃÏó¿´¼ûÀ´×ÔµØÓüµÄĞ¡¹íÔÚÏòÄãÕĞÊÖ¡£\n",ob);
        message_vision("Ëæ×Å$N×îºóÒ»Ë¿Á¦Á¿µÄºÄ¾¡£¬$NµÄÉíÌå¾Í¿ìÒª±»ºÚ°µÍÌÃ»ÁË£¡£¡£¡\n"NOR,ob);
        ob->add("kee",-50);
//        ob->start_busy(2);
}

