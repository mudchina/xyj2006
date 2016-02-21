// rewritten by snowcat on 4/11/1997
// room: luzhou2

inherit ROOM;

void create ()
{
  set ("short", "沙漠绿洲");
  set ("long", @LONG

这里四季常热，远不似西北边陲的景象。不想依然水草肥美，五谷
年年照收。当地百姓安居乐业，倒也怡然自得。

LONG);

  set("exits", ([
        "south" : __DIR__"hongse",
        "north" : __DIR__"xiaodian",
        "west"  : __DIR__"luzhou",
        "east"  : __DIR__"luzhou3",
      ]));
  set("outdoors", "firemount");

  setup();
}
