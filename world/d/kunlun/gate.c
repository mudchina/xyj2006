#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "玉虚洞入口");
        set("long", 
"此处乃玉虚洞入口，四周仙境异常，令人把玩不暇。有诗为证：
仙峰险巅，峻岭崔嵬；玻生瑞草，地长灵芝。根连地秀，顶接
天齐；青松绿柳，紫菊红梅。碧桃银杏，火枣交梨；仙翁判画，
隐者围棋。\n"+

"门口一个巨大石壁上写着：\n"+
HIW"    昆    仑    山    玉    虚    门  \n"NOR
);
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shijie1",
  "southdown" : __DIR__"xiaolu3",


]));
    set("objects", ([ // sizeof() == 1 //
  __DIR__"npc/xiaotong" : 2,
]));
        setup();
  call_other("/obj/board/yubi_b", "???");
        replace_program(ROOM);
}
