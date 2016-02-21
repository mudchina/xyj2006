// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "石洞");
  set ("long", @LONG

石洞里又是一番天地，但见冷气森森刺骨寒，一层层蜘蛛网叠
将着坠下来，密密麻麻铺天盖地。你不禁打了一个寒战，倒吸
一口寒气。

LONG);

  set("exits", ([
        "north"    : __DIR__"shiyuan",
        "southwest"    : __DIR__"dongnei",
      ]));
  setup();
}

