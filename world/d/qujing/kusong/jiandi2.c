//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "涧底小路");
  set ("long", @LONG

耳畔隐隐传来泉水的流声，夹杂着些鸟儿的鸣叫。周围长着密
密麻麻的青草，草中现出点点的野花。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"jiandi",
  "northeast" : __DIR__"wangyue", 
  "southwest" : __DIR__"qingcao0",
]));
  set("outdoors",1);


  setup();
}

