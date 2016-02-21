//Cracked by Roath
inherit ROOM;
void create ()
{
  set ("short", "建议反馈中心");
  set ("long", @LONG

这是巫师为和玩家沟通而专门制作的房间，如果您有什么宝贵的意见
和建议，请发表在建议版上，好的建议如果采纳，将会得到丰厚的奖
励！	

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/city/kezhan",

]));
  set("objects", ([ /* sizeof() == 2 */
]));
  set("no_fight", 1);
  set("no_magic", 1);
  

  setup();
  call_other("/obj/board/advise_b", "???");
}
