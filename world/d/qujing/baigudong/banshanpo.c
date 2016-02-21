// Room: come to baigudong.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "半山坡");
  set ("long", @LONG

    再往西就通往白骨洞了。据说洞里有吃人妖精，厉害异
常，不知吃了多少寻常百姓、过往行人。曾有几位英雄仗
义除妖，进洞后未曾见他们出来。
  这里百花枯萎，蔓藤长生，野草茂盛，四周腾腾的冒着
白雾气，萧杀之意愈浓。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"broad",
  "southwest" : __DIR__"guangchang",
  "northeast" : __DIR__"shanlu1",
  "westup"       : __DIR__"shanlu9", 
]));
   set("objects", ([
        __DIR__"npc/xiaoyao"   : 2,
      ]));
  setup();
}






