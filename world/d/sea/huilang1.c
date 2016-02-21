// Room: /u/rainy/sea/huilang1.c
inherit ROOM;

void create ()
{
  set ("short", "回廊");
  set ("long", @LONG

细细的回廊环绕着水晶宫，回廊两侧有着淡淡薄雾，看不甚清。栏　　　
上雕着各种水兽鱼虫，似乎在随着水波轻轻游动。头顶上有彩色的　　　
珊瑚成伞状。前后偶有巡视的兵将走过。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huilang2.c",
  "north" : __DIR__"yujie1",
]));
//      
        set("water", 1);
//  
  setup();
}
