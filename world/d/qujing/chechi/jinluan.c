// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jinluan.c

inherit ROOM;

void create ()
{
  set ("short", "金銮殿");
  set ("long", @LONG

大殿里灯火通明，金莲御座高高在上。御座前后各有一对玉麒麟
守候，两边是缀珠紫红绒帘，华贵之极。殿顶龙飞凤舞，碎玉堆
金，紫气浩荡。

LONG);

  set("exits", ([
        "north"        : __DIR__"hougong2",
        "south"        : __DIR__"wufeng",
        "west"         : __DIR__"fengyun",
        "east"         : __DIR__"leiyu",
      ]));

  set("objects",([
         __DIR__"npc/taijian" : 1,
         __DIR__"npc/king" : 1,
      ]));
  setup();
}

