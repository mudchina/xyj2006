// created by snowcat.c 4/4/1997
// room: /d/nuerguo/sanchalu.c

inherit ROOM;

void create ()
{
  set ("short", "三岔路口");
  set ("long", @LONG

这里是西梁女国地界。西北方隐隐约约可见一座城镇。东行
可达子母河边。往南望去则是一座葱翠的小山丘。
LONG);

  set("exits", ([
        "northwest" : __DIR__"townc3",
        "east"      : __DIR__"westriver",
        "south"     : __DIR__"jieyang",
      ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave (object me, string dir)
{
  if ((string)me->query("id")=="woman" &&
      (dir=="east" || dir=="south")) 
    return 0;
  return 1;
}




