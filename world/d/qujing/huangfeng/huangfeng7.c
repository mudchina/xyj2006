// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng7.c


inherit ROOM;

void create ()
{
  set ("short", "黄风岭");
  set ("long", @LONG

天高云淡，雾重风轻。满眼的苍松翠柏，碧草琼花。一条
小溪绕路奔流，水声叮咚，果然一派秀丽景色。这里就是
八百里黄风岭了。

LONG);

  set("exits", ([
        "northwest" : __DIR__"huangfeng8",
        "southeast" : __DIR__"huangfeng6",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
