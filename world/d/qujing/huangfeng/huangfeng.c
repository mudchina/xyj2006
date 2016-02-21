// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng.c


inherit ROOM;

void create ()
{
  set ("short", "黄风岭");
  set ("long", @LONG

天高云淡，雾重风轻。满眼的苍松翠柏，碧草琼花。一条
小溪绕路奔流，水声叮咚，果然一派秀丽景色。东面高处
一道瀑布飞悬，隐隐的似乎有水声传来。

LONG);

  set("exits", ([
        "southdown" : __DIR__"tulu3",
        "northup" : __DIR__"huangfeng1",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "northup")
    return 0;
  return ::valid_leave (who, dir);
}
