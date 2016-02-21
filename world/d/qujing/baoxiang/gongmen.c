// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/gongmen.c

inherit ROOM;

void create ()
{
  set ("short", "王宫门");
  set ("long", @LONG

宫门呈双月拱形，由山里运来的玉石筑成，上面雕有细腻的金丝
银线弧形花纹。向里面看去，宫殿林立阁宇重重，祥云笼罩，气
象极度非凡。

LONG);

  set("exits", ([
        "southwest"  : __DIR__"xi4",
        "north"      : __DIR__"bei4",
        "west"      : __DIR__"jitan",
        "east"       : __DIR__"zhendong",
        "south"      : __DIR__"longfeng",
      ]));

  set("objects", ([
         __DIR__"npc/bing" : 2,
       ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "south" &&
      who->query("id")!="huangjia bing" &&
      who->query("id")!="baihua xiu")
    return 0;
  return 1;
}
