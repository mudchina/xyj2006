// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shutang.c

inherit ROOM;

void create ()
{
  set ("short", "书堂");
  set ("long", @LONG

书堂中间有一方桌，上有两卷摊开的绢书。墙上贴有几幅长长的
字画，灯龛里烛光闪闪。四周放满了布面毡底圆蒲团，供客人们
闲座。地上隔不远就置一个矮脚几，放有铜壶陶碗。

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi6",
      ]));
  set("objects", ([
        __DIR__"npc/shulao"   : 1,
      ]));

  setup();
}

