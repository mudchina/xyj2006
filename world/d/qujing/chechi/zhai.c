// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhai.c

inherit ROOM;

void create ()
{
  set ("short", "斋房");
  set ("long", @LONG

三清观的斋房设在殿前，斋房宽大，设有一大红木斋桌。房内
无灶无锅。因车迟国内文武官员爱道成风，大小男女前来拜请
奉斋络绎不觉，这里善斋不断。

LONG);

  set("exits", ([
        "east"         : __DIR__"dianmen",
      ]));
  set("objects", ([
         __DIR__"obj/gongguo"    : 1,
         __DIR__"obj/guo"    : 2,
      ]));
  setup();
}

