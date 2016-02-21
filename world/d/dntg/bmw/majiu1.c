//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "马厩");
        set("long", @LONG

厩中养着千匹战马，每匹都是日行千里，渡水登山，
如履平地之神驹。一个个，嘶风逐电，攒蹄不息。
令有众多小马驹，虽未长成，却也是神骏异常。几
个力士昼夜不眠，滋养马匹。
LONG );
 
        set("exits", ([
                "north" : __DIR__"majiu2",
                "south" : __DIR__"zhengting",
        ]));
 
        set("objects", ([
               __DIR__"npc/horsebaby": 1,
        ]));
 


        setup();
}
