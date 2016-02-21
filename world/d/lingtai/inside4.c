// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

虽说道士们清茶淡饭吃的并不好，但他们却经常周济附近一些贫
苦的村民．边上的架子上堆着蔬菜，一口大水缸立在墙角．一个
胖胖的道士正在烧火，炉上热气腾腾，不知煮的什么．你可以要
些(yao)吃的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houyuan",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bowl" : "锅里是热气腾腾的包子，你要饿了也可以拿些去吃．
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wanfeng" : 1,
  "/d/ourhome/obj/hulu" :1,
]));
  set("clean_up", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
int valid_leave()
{
        if((present("bao zi", this_player())))
            return notify_fail("吃完包子再走吗！\n");
        if((present("lv hulu", this_player())))
	    return notify_fail("你不能把葫芦带走！\n");
    return ::valid_leave();
}

