// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhaomen.c

inherit ROOM;

void create ()
{
  set ("short", "朝门");
  set ("long", @LONG

朝门祥光笼罩，东边设有一只金钟，西边设有一面银鼓，门下百
种奇花异草怒放。门上是透亮琉璃瓦，门道由黛色罗纹细密石条
一路铺平。

LONG);

  set("exits", ([
        "south"        : __DIR__"gongmen",
        "north"        : __DIR__"tan",
      ]));
  set("objects", ([
        __DIR__"npc/weishi"        : 2,
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


int valid_leave(object me, string dir)
{
  object shi = present ("wei shi", environment(me));
  if (dir == "north" && shi && living (shi))
    return notify_fail (shi->query("name")+"喝道：禁行！\n");
  return ::valid_leave(me, dir);
}
