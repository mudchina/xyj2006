// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/leiyi.c

inherit ROOM;

void create ()
{
  set ("short", "雷雨殿");
  set ("long", @LONG

殿里供着石像，分别为雷雨之神。殿心有一张嵌玉桌，上面插有
祈牌祈签。桌边放置有四个绣花软面蒲团，以供王室贵族祈祷时
使用。

LONG);

  set("exits", ([
        "south"        : __DIR__"qiyu",
        "west"         : __DIR__"jinluan",
      ]));

  set("objects",([
        __DIR__"npc/taijian" : 1,
      ]));
  setup();
}

