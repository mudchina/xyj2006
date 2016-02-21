//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "峨嵋山脚");
set("long", @LONG
    
　　走到这里，我们已经可以看到雄秀壮丽的峨嵋山了，上山
进香的人络绎不绝，磨肩接踵。
LONG );


set("exits", ([
  "westup"   : __DIR__"shanlu1",
  "east"   : __DIR__"guandao1",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
