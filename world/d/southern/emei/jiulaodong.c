//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "九老洞");
set("long", @LONG
    
　　传说黄帝为访天皇真人，来到峨嵋山腰的仙峰寺侧的一
山洞，他在洞外见一老者，问道：「仅翁一人乎？」老者答：
「九老居此」。後人於是把此洞称为九老洞。
LONG );


set("exits", ([
  "north"   : __DIR__"shanyao",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
