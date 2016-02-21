//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "刑房");
  set ("long", @LONG

刑房中特别的昏暗，北边竖着个铁柱子，上面搭着几条带血的铁
链。地下扔着几条皮鞭。东边有一扇铁门，上有小口，里面是间
囚室。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yongdao8", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 1,    
  __DIR__"npc/xing" : 1,
]));


  setup();
}

