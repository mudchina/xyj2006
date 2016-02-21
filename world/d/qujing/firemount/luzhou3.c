// rewritten by snowcat on 4/11/1997
// room: luzhou3

inherit ROOM;

void create ()
{
  set ("short", "沙漠绿洲");
  set ("long", @LONG

这里四季常热，远不似西北边陲的景象。不想依然水草肥美，五谷
年年照收。当地百姓安居乐业，倒也怡然自得。旁边还有一小井，
想是为了取水的。

LONG);

  set("exits", ([
        "southeast" : __DIR__"qujinglu",
        "west"      : __DIR__"luzhou2",
      ]));
  set("outdoors", "firemount");
  set("resource", ([
        "water" : 1,
      ]));

  setup();
}
