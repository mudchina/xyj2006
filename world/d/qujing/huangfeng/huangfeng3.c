// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng3.c


inherit ROOM;

void create ()
{
  set ("short", "黄风岭");
  set ("long", @LONG

天高云淡，雾重风轻。满眼的苍松翠柏，碧草琼花。一条
小溪绕路奔流，水声叮咚，果然一派秀丽景色。几只小兽
听见人声从草中跳出，一转眼跑得不知所踪。

LONG);

  set("exits", ([
        "southwest" : __DIR__"huangfeng2",
        "east" : __DIR__"huangfeng4",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
