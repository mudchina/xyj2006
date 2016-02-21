//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "卧室");
  set ("long", @LONG

这里是一间圆圆的石室，室中有一堆炭火，把屋内烘的暖暖的。
四周横七竖八的铺着十来张兽皮，时不时有小妖跑来睡觉。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhongdong",
]));
        set("sleep_room",1);
        set("if_bed",1);



  setup();
}

