// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/wufeng.c

inherit ROOM;

void create ()
{
  set ("short", "五凤楼");
  set ("long", @LONG

楼里设有五凤，各为赤橙青绿紫色。神态栩栩如生，欲飞欲留。
楼上传来丝竹之声，香云缭绕，气氛极为祥和无比。北面通往金
銮殿，南面通向坛场。

LONG);

  set("exits", ([
        "north"        : __DIR__"jinluan",
        "south"        : __DIR__"tan",
      ]));
  set("objects",([
        __DIR__"npc/girl"     : 5,
      ]));

  setup();
}

