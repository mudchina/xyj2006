inherit ROOM;

void create ()
{
  set ("short", "凌云阁");
  set ("long", @LONG

    这座大殿里金碧辉煌紫气瑞瑞，根根玉柱雕麒麟，殿窗是金钉
银檐，殿顶亦上是金银鸳鸯双双对对，正中有一白玉玛瑙莲花
台。东南方是休息室。北面传来阵阵练武声。
LONG);

  set("exits", ([
        "southeast" :  __DIR__"sleeproom",         "north"   : __DIR__"wuchang",
        "south"   : __DIR__"shijie2",
      ]));
  set("objects", ([
/* sizeof() == 1 */
  "/d/kunlun/npc/jinzha" : 1,
     ]));

  setup();
}
