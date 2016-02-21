//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "五台山脚下");
set("long", @LONG
    

　　从此以北的方圆五百余里，就都是五台山了，共有五座山峰，
五峰拱卫连绵，从山谷吹来的习习凉风使这块小盆地的沟沟洼洼
里，到处都有美的色彩与施律。

LONG );


set("exits", ([
  "northup"   : __DIR__"qinglianggu",
  "south"   : __DIR__"guandao1",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
