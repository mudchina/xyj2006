// Room: some place in 西牛贺洲
// uphill4.c

inherit ROOM;

void create()
{
  set ("short", "观景台");
  set ("long", @LONG

这里乃是一处高崖，虽不是云悬千尺，却也是陡峭异常。周围钉
了些木桩，绑着绳子以防失足。远处可望到高家镇，一片一片的
青瓦房坐落在绿油油的麦田之中，还可以看道一些农夫正在田中
干活。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"uphill4",
]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/npc/zhangdaoling" : 1,
"/d/sea/npc/beast/beast1" : 1,

]));

	set("outdoors", 1);
        setup();
}


