//Cracked by Roath
inherit ROOM;
void create ()
{
        set ("short", "½­ÖÝÖª¸®");
        set ("long", @LONG

ÀëÀÏÔ¶Äã¾Í¿´µ½Ò»¿éØÒ£º

[31m        ¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
        ¡ö                                      ¡ö
        ¡ö  [1;37m    ½­      ÖÝ      Öª      ¸®   [0;31m   ¡ö
        ¡ö                                      ¡ö
        ¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö[m
LONG);
        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"xw-2",
                "west"  : __DIR__"datang",
        ]));
        set("objects",
        ([ //sizeof() == 1
                __DIR__"npc/yayi" : 4,
        ]));
   set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{       if (dir == "west") {
        if (objectp(present("yayi", environment(me)))) {
  if(!present("zhuang zhi", me) && me->query("office_number") < 300 )
return notify_fail("ÑÃÒÛºÈµÀ£ºÃ»ÓÐ×´Ö½£¨zhuang zhi£©£¬ÎªºÎÂÒ´³£¿ËÙËÙÀëÈ¥£¡\n");
                }
        return ::valid_leave(me, dir);
        }
        return 1;
}
