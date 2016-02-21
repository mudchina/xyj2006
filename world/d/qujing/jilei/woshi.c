// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "卧室");
  set ("long", @LONG

卧室里面摆设精美，一个花石案上摆着稀罕的玉玩物，墙边立
着一个雕镂紫檀长柜，后面的墙上挂着麒麟皮龙角。西北方面
有一门通向外面。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"dating",
"enter" : "/d/qujing/jilei/bed.c",
      ]));
  set("objects", ([
        __DIR__"npc/yumian" : 1,
        __DIR__"npc/niumo" : 1,
        __DIR__"npc/jinjing" : 1,
      ]));

  setup();
}



