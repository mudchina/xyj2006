// Room: /u/hkgroup/main
inherit ROOM;

void create ()
{
  set ("short", "´ó¹ÛÂ¥");
  set ("long", @LONG

¡¡¡¡³ç¸óÎ¡¶ë£¬²ãÂ¥¸ßÆð£¬ÃæÃæÁÕ¹¬ºÏ±§£¬ÌöÌö¸´µÀæúÐÐ¡£
ÇàËÉ·÷éÜ£¬ÓñÀ¼ÈÆÆö£»½ð»ÔÊÞÃæ£¬²Ê»Àó¤Í·¡£

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "up" : __DIR__"fairyplace",
  "west" : __DIR__"mainwest",
  "north" : __DIR__"bridge",
  "south" : __DIR__"yard2",
  "east" : __DIR__"maineast",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/leng" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
  "obj/board/honglou_b"->foo();
}
