//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "舍身岩");
set("long", @LONG
    
    金顶岩下．是一个纵深七百二十米的断岩绝壁。这断岩峭削方棱
、嵯峨峥嵘，有人身贴岩石，匍匐下窥，莫不咋舌而回。人们又称它
为舍身岩。自古以来，不知有多少轻生者来此纵身一跳了结一生。

LONG );


set("exits", ([
  "east"   : __DIR__"jinding",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
