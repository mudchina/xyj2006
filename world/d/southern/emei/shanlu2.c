//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "山路");
set("long", @LONG
    
　　「蜀国多仙山，峨嵋世难匹。」，名诗人范成大曾在峨嵋山游了
十九天。後来他在《叁峨》一诗中赞道：「大峨两山相对开，小峨中
峨迤逦来；叁峨秀色甲天下，何须涉海寻蓬莱。」从此，峨嵋天下秀
的美名扬名开来。

LONG );


set("exits", ([
  "westup"   : __DIR__"shanyao",
  "eastdown"   : __DIR__"shanlu1",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
