//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "三门");
  set ("long", @LONG

三门金光闪闪，乃是金边檀香木门一对，门两边有赤金丹顶凤
一对。大殿左右各摆着雕花金佛鼎。北面通向古寺的二道门，
东西为侧殿，南面就是大雄宝殿。

LONG);

  set("exits", ([
        "north"   : __DIR__"ermen",
        "south"   : __DIR__"daxiong",
        "west"   : __DIR__"sidian33",
        "east"   : __DIR__"sidian35",
      ]));
  set("objects", ([
        __DIR__"npc/pusa" : 8,
     ]));

  setup();
}

