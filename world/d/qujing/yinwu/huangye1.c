// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "荒野");
  set ("long", @LONG

荒野四处辽阔，远方可见群山峻岭峭壁，近处有小路进出大小
森林树木。风吹过洒洒之声不断，流水潺潺，时闻苍狼嗥叫，
时闻饿虎咆哮。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"jiankou2",
        "northwest"    : __DIR__"caopo4",
        "southwest"    : __DIR__"huangye5",
        "southeast"    : __DIR__"huangye6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

