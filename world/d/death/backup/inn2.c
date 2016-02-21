// This is a room made by roommaker.

inherit ROOM;

void create ()
{
  set ("short", "黑店");
  set ("long", @LONG

屋里相当冷清，外面的浓雾还不时地从半开着的门缝飘进来。地面
上散着一些破旧的物品，不过光从外表已经无法分辨出那是些什么
东西了。墙上(wall)刻着一些潦草的字体，墙角的一盏灯笼挣扎似
地发出一阵阵微弱的光芒，也始得那些字看来格外的诡异。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"walk",
]));
  set("sleep_room", 1);
  set("hell", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "几行你勉强分辨得出来的字:
我被困在这里了.... 我要回家啦!!!!!!!!!!!
                      ^^^^
                        靠自己啦...
什么叫靠自己啊?!?!? 这里连个活人都没有...

看到你自己时问一下吧... 自己人都会互相帮忙的说.. 
                                    ^^^^
                                 你... 确... 定?!?!
喔.. 
",
]));

  setup();
}
