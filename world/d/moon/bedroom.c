//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ÎÔ·¿");
  set ("long", @LONG

Ò»¼äµ­ºşÂÌÉ«µÄ·¿¼ä, ÈıÃæÊÇÊé¼Ü, ÉÏÃæ°ÚÂúÁËÔÓÆßÔÓ°ËµÄÊé£¬¶ÔºşµÄÒ»
Ãæ¿ªÁËÒ»ÉÈÖñ´°, ´°Ç°·Å×ÅÒ»¼ÜÎåÏÒÇÙ£¬Ç½±ßÓĞÒ»ÕÅÑÀÓñÉ«µÄÈíé½(bed)£
®
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "Ò»ÕÅÑÀÓñÉ«µÄÈíé½£¬ËúËÄÖÜµñ×ÅÖñÒ¶¸ñ£¬¿´ÉÏÈ¥¼«Îª¾«ÖÂ(gosleep,gobed,bed)¡£ 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"rain",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$NÏÆ¿ªÉ´ÕÊ£¬×¼±¸ÉÏ´²ÁË¡£\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\nÉ³ÕÊÇáÇáÒ»¶¯£¬$N×êÁË½øÀ´¡£\n" NOR, me);
                return 1;
}


