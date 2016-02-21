//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "万年寺");
set("long", @LONG
    
　　峨嵋山的众寺庙中，要数万年寺名气最大。这是
一座供奉普贤的寺庙。前殿正中一个浑身洁白的大象，
驮了一尊菩萨。这就是有名的普贤。
LONG );


set("exits", ([
  "north"   : __DIR__"daochang",
 
]));


set("objects", ([
]));




setup();
}
