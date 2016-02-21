// Room: /d/qujing/wudidong/bedroom.c

inherit ROOM;

void create()
{
  set("short", "寝室");
  set("long", @LONG

整个小庙里，也就这里还干净一些，房顶也不漏水。庙里仅剩的几个
和尚就都挤在这里。屋里处了一张长长的竹床，和挂着的几件破僧衣
之外，什么都没有。也不知这几个和尚吃什么度日。
LONG
      );
  set("objects", ([ /* sizeof() == 1 */
		   __DIR__"npc/fangzhang-temple" : 1,
		   ]));
  set("outdoors", 0);
  set("exits", ([ /* sizeof() == 2 */
		 "southeast" : __DIR__"houyuan",
		 "west" : __DIR__"temple-qiandian",
		 ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
