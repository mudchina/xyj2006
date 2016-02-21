// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/linzhong.c


inherit ROOM;

void create ()
{
  set ("short", "林中");
  set ("long", @LONG

树林里黑乎乎的。黑暗中你只能闻到阵阵令人作呕的血腥气
味。脚底软软的，可能是什么东西的尸体吧。你越想越怕，
只想快些离开这个地方。

LONG);

  set("exits", ([
        "north" : __DIR__"shanlu2",
              ]));
//  set("outdoors", __DIR__);
        
  setup();
}
