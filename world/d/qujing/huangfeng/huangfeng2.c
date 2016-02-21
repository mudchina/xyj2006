// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/huangfeng2.c


inherit ROOM;

void create ()
{
  set ("short", "黄风岭");
  set ("long", @LONG

瀑布脚下是一深潭，潭水清澈。一条白亮亮的水流泻入潭中，
发出巨大的轰鸣声。飞溅的水珠打在你的脸上身上。远远望见
北面上坡上有一洞口，还有一两个人影进出其中。

LONG);

  set("exits", ([
        "westdown" : __DIR__"huangfeng1",
        "northeast" : __DIR__"huangfeng3",
        "northup" : __DIR__"dongkou",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
