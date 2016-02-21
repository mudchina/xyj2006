// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞穴内昏昏暗暗，珠丝如藤条一般盘绕在洞壁，洞顶有水珠渗
出，沿洞壁纷纷落下，嘀嗒有声。一丝微弱的光线自东北方向
漫射进来。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"shidong",
      ]));
  set("objects", ([
        __DIR__"npc/son1"    : 1,
        __DIR__"npc/son2"    : 1,
        __DIR__"npc/son3"    : 1,
        __DIR__"npc/son4"    : 1,
        __DIR__"npc/son5"    : 1,
        __DIR__"npc/son6"    : 1,
        __DIR__"npc/son7"    : 1,
      ]));
  setup();
}

