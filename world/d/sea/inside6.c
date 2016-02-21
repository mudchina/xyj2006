// hill.c

inherit ROOM;

void create ()
{
  set ("short", "明察堂");
  set ("long", @LONG

明察堂是东海龙宫中大将军鲸无敌的办公场所，檀木桌上叉着令旗　　　
和令箭。平常的虾兵蟹将是不敢来这里的，出入的人也小心翼翼，　　　
不敢大声出气，周围一派肃穆的气氛。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yujie2.c",
  "north" : __DIR__"jingxing.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jing" : 1,
]));
//      
        set("water", 1);
//  
        setup();
}

