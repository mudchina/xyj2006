// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "千花洞");
  set ("long", @LONG

你来到一个洞口，但见野花盛开万紫千红芬芳无比，洞边百藤
盘缠艳果倒缀。透过洞口可见洞内是另一番奇景，有如世外桃
源一般。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"shandao1",
        "south"    : __DIR__"huajian2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

