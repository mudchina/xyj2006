// Room: /d/ourhome/mbox.c
// 96/10/03 by none

inherit ROOM;

void create()
{
	set("short", "º¦³æµçĞÅ¾Ö");
	set("long", @LONG

    ÕâÀïÊÇº¦³æµçĞÅ¾Ö¡£(instructions)Ã

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "instructions" : "
    ÅÆ×ÓÉÏĞ´µÀ£º
    ÇëÏò¶şÊ®°ËĞÇÆ°³æĞ¡½ãÑ¯ÎÊ¼ÄĞÅ»òÊÕĞÅµÄ³ÌĞò¡£

",
]));
	set("exits", ([ /* sizeof() == 1 */
		"kedian" : "/d/ourhome/kedian",
	]));
	set("objects", ([
		__DIR__"npc/28star": 1,
                __DIR__"npc/firefly" : 1,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "Äã½«ĞÅÏä½»»Ø¸ø¶şÊ®°ËĞÇÆ°³æĞ¡½ã¡£\n");
		destruct(mbox);
	}
	return 1;
}
