//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ĞşÎäµî");
set("long", @LONG
³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´óĞÛÎ°£¬²ã
²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£    
LONG );


set("exits", ([
  "north"   : __DIR__"weiyuegong",
  "south"   : __DIR__"xuanyuantang",
]));


set("objects", ([
]));



setup();
}
