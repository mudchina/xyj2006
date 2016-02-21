// Room: /u/mimi/zhuziguo/qiyutan.c
inherit ROOM;

void create ()
{
  set ("short", "祈雨坛");
  set ("long", @LONG

此处乃国王祈雨的祭坛。祭坛四角各放着一鼎香炉，中央立着一鼎巨
大的石碑，写着一些蝌蚪形的文字。乌鸡国六年前曾招大旱，国王曾
在此昼夜焚香祷告，终于感动了圣明，请到一位会呼风唤雨的道士，
解除了旱情。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"jxt",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 1,
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}

