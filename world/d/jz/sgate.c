//Cracked by Roath

inherit ROOM;
void create()
{
  set ("short", "[1;33mµöÓãÌ¨[m");
  set ("long", @LONG

ÒÔÇ°£¬ÕâÊÇ´ï¹Ù¹óÈËÃÇµöÓãÏíÀÖµÄµØ·½£¬Èç½ñ½­Öİ³ÇË¥ÂäÁË£¬
Õâ¸öµØ·½¸ù±¾¾ÍÃ»ÈË¿´¹ÜÁË£¬¼´Ê¹ÕâÑù£¬Ò²ÊÇÉÙÓĞÈËÀ´¡£Ì¨
µÄÅÔ±ßÓĞ¸öĞ¡ÅÆ×Ó(paizi)£¬ÉÏÃæºÃÏóĞ´Ğ©Ê²Ã´ÄÚÈİ¡£
LONG);
        set("exits", ([
        "north":__DIR__"dingan-3",
]));
        set("objects", ([
                __DIR__"npc/waiter": 1,
                ]));
        set("item_desc", ([
                "paizi": @TEXT
¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­
                    µöÓã£ºÓã¸ÍÃ¿¸¶£µÁ½°×Òø
¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­¡­
TEXT
        ]) );
  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north"&& me->query("fish") )
        me->delete("fish"); 
        return 1;
}
/*
void say()
{
        object me=this_player();
         write("ÂôÓã¸ÍµÄ¶ÔÄãËµµÀ£ºĞê~~²»Òª´òÈÅ±ğÈËµöÓã¡£\n");
        return 0;
}
*/
