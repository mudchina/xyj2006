// gate.c

inherit ROOM;

void create()
{
  set ("short", "刘家布店");
  set ("long", @LONG

这里的东西虽不高级，却相当符合当地人的口味．逢年过节来光顾
的人还真不少．屋中横放一张七尺多长的柜台，柜台后的架子上是
一匹匹的布料和成衣．
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road2",
]));

set("objects", ([
                __DIR__"npc/pangsao": 1]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


