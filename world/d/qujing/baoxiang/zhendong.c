// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zhendong.c

inherit ROOM;

void create ()
{
  set ("short", "镇东场");
  set ("long", @LONG

镇东场由石墙圈起，场角有一口大石井。场的东面驻有王家卫兵，
西南方向更是高墙筑起，里面宫殿林立，阁宇重重，那里便是宝
象国王宫。

LONG);

  set("exits", ([
        "west"       : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/bing" : 4,
      ]));

  set("resource", ([ 
    "water" : 1,
    ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

