//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "山崖");
set("long", @LONG
    
沿着秀丽的花果山一路走来，只感到这里的一草一木都令人
耳目一新。由此，上山的路通向一座瀑布，西面是花果山的
猴子们的叫军场，猴子们蹿来跳去，不时传来雄壮的号角声。
LONG );


set("exits", ([
"east"   : __DIR__"pubu",
"west"   : __DIR__"jiaojunchang",
"southdown"   : __DIR__"tongfeng",
]));


set("objects", ([
__DIR__"npc/ba" : 1,
__DIR__"npc/maque" : 1,
]));



set("outdoors", 1);
setup();
}
