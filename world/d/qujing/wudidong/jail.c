// Room: /u/mes/dong1.c

inherit ROOM;

void create ()
{
  set ("short", "狱门");
  set ("long", @LONG

这儿就是无底洞的地牢了。厚重的铁门上开了一个半尺见方的圆孔，
仅够传递饭菜水钵。里面传来的呻吟声痛苦万状，动人心魄。门口站
着两个膀大腰圆的小喽罗，手中拿着明晃晃的长剑，寸步不离铁门左
右。
LONG);

  set("exits", ([ /* sizeof() == 2 */
               "north" : __DIR__"monk1",
		 "south" : __DIR__"trap",
		 ]));
  set("outdoors", 0);
  set("objects", ([ /* sizeof() == 1 */
		   __DIR__"npc/ward" : 2,
		   ]));
  
  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="north" && objectp(present("ward", environment(me))))
    return notify_fail("狱守喊道："+RANK_D->query_rude(me)+"，哪里走！\n");
  return ::valid_leave(me, dir);
}
