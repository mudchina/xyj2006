#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"剑冢"NOR);
        set("long", @LONG

这里是中山夫子祭剑的地方，听说刺客剑法就是在这里悟出来的！
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/sanxian/sleep",
]));
 set("objects", ([
"/d/sanxian/npc/zhangmen" : 1,
"/d/sanxian/npc/guiguzi" : 1,
  ]) );  
        setup();
  call_other("/obj/board/jian_b", "???");
        replace_program(ROOM);
}
