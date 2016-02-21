//create by guoth
// Room: /d/xueshan/mishi.c

inherit ROOM;

void create()
{
  set("short", "密室");
  set("long", @LONG

看起来密室很久没有人来了，到处都是灰尘．正前方有一张
大木桌，桌上供着一个牌位，两边烛台上的香烛早已燃尽。
LONG
    );
        set("item_desc", ([ /* sizeof() == 2 */
  "table" : "桌上都是灰，什么也看不清。
",
  "牌位" : "牌位上写着：雪山之祖 孔雀明王之位。
",
]));
        set("exits", ([ /* sizeof() == 1 */
  "out" : "/d/xueshan/eroad3",
]));

           if ("/d/xueshan/obj/pingreal.c"->in_mud())
        set("objects", ([ /* sizeof() == 1 */
  "/d/xueshan/obj/pingfake.c" : 1,
  ]));
else
          set("objects", ([ /* sizeof() == 1 */
    "/d/xueshan/obj/pingreal.c" : 1,
  ]));

          set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

