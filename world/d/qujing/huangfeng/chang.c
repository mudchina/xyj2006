// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/chang.c

inherit ROOM;

void create ()
{
  set ("short", "储物仓");
  set ("long", @LONG

这里的妖怪们储藏物品的地方。角落里堆着几具被吃光了
肉的兽骨。空气中充溢着食物腐烂散发出的臭味。

LONG);

  set("exits", ([
        "south" : __DIR__"dong5",
      ]));
       
  setup();
}
