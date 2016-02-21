// Room: /u/rainy/sea/yujie2.c
inherit ROOM;

void create ()
{
  set ("short", "龙宫前厅");
  set ("long", @LONG

四根巨大的盘龙柱子撑出了一个相当大的龙宫前厅，龙宫中若有大　　　
的宴会，一般就在这里举行。厅的四周挂有明珠，将堂前照的通亮　　　
明如白昼。靠墙边有个龙宫通告牌子，围着些龙族水兽指指点点。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"inside5.c",
  "north" : __DIR__"inside6.c",
  "west" : __DIR__"yujie1",
  "east" : __DIR__"yujie3.c",
]));
set("valid_startroom", 1);
//      
        set("water", 1);
//  
  setup();
"obj/board/dragon_b"->foo();

}
