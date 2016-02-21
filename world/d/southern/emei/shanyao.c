//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "山腰");
set("long", @LONG
    
　　被道家称为「第七洞天」的峨嵋山，满载着各种美丽的传说，
向南走去，你就可以找到传说中的九老洞了。
LONG );


set("exits", ([
  "westup"   : __DIR__"shanlu3",
  "eastdown"   : __DIR__"shanlu2",
  "south"   : __DIR__"jiulaodong",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
