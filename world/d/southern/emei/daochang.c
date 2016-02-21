//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "普贤菩萨道场");
set("long", @LONG
    
　　东汉明帝时，一天，有位名叫蒲公的隐士正在山上采药，
突然见一头放金光者，坐骑白象，从空中飞驰而过，遂跟踪
到顶峰，却又渺无人迹。後蒲公被告知这是普贤菩萨显现全
身。於是，蒲公回山舍宅为庙，供奉普贤，以後峨嵋山就成
了普贤道场。
LONG );


set("exits", ([
  "east"   : __DIR__"shanlu5",
  "westup"   : __DIR__"jinding",
  "south"   : __DIR__"wanniansi",
  "north"   : __DIR__"guangxiangsi",
 
]));


set("objects", ([
     __DIR__"npc/puxian" : 1,
]));



set("outdoors", 1);

setup();
}
