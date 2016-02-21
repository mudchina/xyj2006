// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng1.c


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
	"northup" : __DIR__"huangfeng6",
        "southdown" : __DIR__"huangfeng",
        "eastup" : __DIR__"huangfeng2",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
