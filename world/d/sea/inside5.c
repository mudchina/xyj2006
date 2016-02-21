inherit ROOM;

void create ()
{
  set ("short", "慎言堂");
  set ("long", @LONG

大殿里龙柱凤檐富丽堂皇，南边是鹅黄落地绒，上面用珍珠绣有碧
海波涛，北面是一排白玉窗，窗檐上雕着金龟如意图。往北有铺花
道通往宝殿。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gui" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qingxin.c",
  "north" : __DIR__"yujie2.c",
]));
//      
        set("water", 1);
//  
        setup();
}

