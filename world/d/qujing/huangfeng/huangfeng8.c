// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng8.c


inherit ROOM;

void create ()
{
  set ("short", "黄风岭");
  set ("long", @LONG

天高云淡，雾重风轻。满眼的苍松翠柏，碧草琼花。一条
小溪绕路奔流，水声叮咚，果然一派秀丽景色。西边是通
往西天的取经路。

LONG);

  set("exits", ([
        "west" : "/d/qujing/baigudong/sroad1",
        "southeast" : __DIR__"huangfeng7",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
