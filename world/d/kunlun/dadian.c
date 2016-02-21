inherit ROOM;

void create()
{
        set("short", "´óµî");
        set("long", @LONG
    ÕâÀïÊÇÓñĞé¶´µÄ´óµî£¬µîÄÚÎå¹âÊ®É«£¬½ğ±Ì»Ô»Í£¬²»Ê±ÓĞ
¼¸¸öÏÉÈËÀ´ÍùÓÚ´Ë´¦£¬ÁÙ´°¿É¼ûÔºÖĞ´äÖñ¸Í¸Íµ¹£¬½ğÁ«¶ä¶ä£¬
É·ÊÇÆ¯ÁÁ¡£¬


LONG );
        set("exits", ([
                "south" : __DIR__"wuchang",
                "northwest" : __DIR__"mishi",
        ]));
          set("kunlun", 1);
  set("objects", ([ // sizeof() == 1 //
 __DIR__"npc/luya" : 1, 
__DIR__"npc/zhangmen" : 1, 
 ]));
  set("valid_startroom", 1);
  setup();
}

