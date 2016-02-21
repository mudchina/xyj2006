//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "清凉寺内堂");
set("long", @LONG
    
　　寺内并没有什么陈设，只是几尊佛像，一口
钟而已，正中的蒲团，便是文殊菩萨的位子了。
LONG );


set("exits", ([
  "out"   : __DIR__"qlsi_yuan",
 
]));


set("objects", ([
     __DIR__"npc/wenshu" : 1,
]));




setup();
}
