// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mÒõÑô½ç[2;37;0m");
  set ("long", @LONG

ÒşÔ¼±±·½ÏÖ³öÒ»×ùºÚÉ«³ÇÂ¥£¬¹âÏßÌ«°µ£¬¿´²»´óÇå³ş¡£Ğí¶àÍö»êÕı
¿Ş¿ŞÌäÌäµØÁĞ¶ÓÇ°½ø£¬ÒòÎªÒ»½ø¹íÃÅ¹Ø¾ÍÎŞ·¨ÔÙ»ØÑô¼äÁË¡£ÖÜÎ§³ß
¸ßµÄÒ°²İËæ·çÒ¡°Ú£¬²İÖĞ·¢³öºôºôµÄ·çÉù¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"new-out2",
  "north" : __DIR__"new-out6",
  "west": __DIR__"new-out8",
  "east": __DIR__"new-out4",
]));
	set("no_fight", 1);
	set("no_magic",1);
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pang" : 1,
]));

  setup();
}
