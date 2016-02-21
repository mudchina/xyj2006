//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "石廊");
  set ("long", @LONG

石廊里极为宽敞，从洞顶上悬下长藤青蔓，石廊两边有大小石
块宛如自然而成的桌椅。石廊的西北方向有光线从洞外射进来，
石廊的西南面有一个大厅。


LONG);

  set("exits", ([
        "northwest"   : __DIR__"shidong",
        "southwest"   : __DIR__"dating",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
      ]));

  setup();
}



