// Room: /d/jjf/main_shufang.c

inherit ROOM;

void create ()
{
  set ("short", "叹兵斋");
  set ("long", @LONG
唐太宗曾经御笔亲封秦将军一对家传锏，钦准他持锏上殿面君。
这对金装锏可以上打昏君，下打谗臣，因此他把这对锏供在太宗的
生像前，燃香祝祷。除此之外，屋中并无其它东西，越发显得庄严。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"main_cabinet",
]));

  setup();
}
