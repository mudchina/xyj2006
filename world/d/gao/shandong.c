
inherit ROOM;

void create ()
{
  set ("short", "山洞");
  set ("long", @LONG

    石洞很小，借着墙上一支蜡烛的微弱火光，几乎很看清里面
一切，在靠墙的一张虎皮上躺着一头非常肥的猪，它似乎睡的真
香，连有人进来它都不知道。

LONG);

  set("exits", ([
        "west"   : __DIR__"shidong",
      ]));
  set("objects", ([
        __DIR__"npc/zhu"   : 1,
      ]));

  setup();
}



