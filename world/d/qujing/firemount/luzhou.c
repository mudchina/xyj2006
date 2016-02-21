// rewritten by snowcat
// Room: luzhou

inherit ROOM;

void create ()
{
  set ("short", "沙漠绿洲");
  set ("long", @LONG

这里四季常热，远不似西北边陲的景象。不想依然水草肥美，五谷
年年照收。当地百姓安居乐业，倒也怡然自得。

LONG);

  set("exits", ([
    "west" : __DIR__"shalu2",
    "east" : __DIR__"luzhou2",
  ]));
  set("outdoors", "firemount");

  setup();
}
