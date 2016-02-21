// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gongmen.c

inherit ROOM;

void create ()
{
  set ("short", "宫门");
  set ("long", @LONG

车迟国宫门南开，门边镶有赤金钉，门上嵌着白玉檐。庄严肃穆。
门洞里可供皇家马车双行，门楼上雕砌玉麒麟金龙朱雀，祥云缥
缈霞光万道。

LONG);

  set("exits", ([
        "west"         : __DIR__"gong5b",
        "east"         : __DIR__"gong5d",
        "south"        : __DIR__"zhong",
        "north"        : __DIR__"zhaomen",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "south")
    return 0;
  return ::valid_leave(who,dir);
}
