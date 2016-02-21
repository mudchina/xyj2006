//Created by Canoe on 2001.03.10
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG "新闻发布室" NOR);
        set("long",@LONG


用post发布新闻!请不要轻易Discard! 发布前请慎重!

LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"wizroom",
]));
 set("objects", ([ /* sizeof() == 2 */
//  __DIR__"obj/shu" : 1,
//  __DIR__"npc/shenling" : 1,
]));
        setup();
call_other("/obj/board/ann_b", "???");
}

