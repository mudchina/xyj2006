//Cracked by Roath
//  ÑıÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "¿ÍÌü");
  set ("long", @LONG

Á±èĞ¸ß¿Ø£¬ÆÁÃÅÉÏ£¬¹ÒÒ»ÖáÊÙÉ½¸£º£µÄºáÅú»­£¬ÕıÖĞ¼ä·Å×ÅÒ»¸ö
¹ÅÍ­ÊŞÂ¯¡£Á½±ß½ğÆáÖùÉÏ£¬Ìù×ÅÒ»¸±´óºìÖ½µÄ´ºÁª£¬ÉÏÊé£º
[32m
        Ë¿Æ®ÈõÁøÆ½ÇÅÍí£¬Ñ©µãÏãÃ·Ğ¡Ôº´º¡£

[m
LONG);
  set("exits", ([
        "west"  : __DIR__"kitchen",
         "east" : __DIR__"born",
         "south": __DIR__"inroom",
         "out": __DIR__"road4",
          ]));
  set("objects", ([
        __DIR__"npc/oldwoman":1,
        ]));
  setup();
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","kill");
        add_action("do_none","steal");
        add_action("do_none","ji");
}

int do_none()
{
        object ob = this_object();

        tell_object(ob,HIC"ÀÏÂèÂè´ÈÏéµÄ¿´×ÅÄã¡£\n"NOR);
        return 1;
}
