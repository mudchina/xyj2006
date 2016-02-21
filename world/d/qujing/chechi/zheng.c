// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zheng.c

inherit ROOM;

void create ()
{
  set ("short", "正殿");
  set ("long", @LONG

正殿雕梁画栋，佛祖在中间的宝座上高供，两边是无数阿罗，揭
谛。香炉青烟袅袅，殿堂虽是旧了些，倒也打扫一净。往东便是
后殿，西边通向金刚殿。

LONG);

  set("exits", ([
        "west"          : __DIR__"jingang",
        "east"          : __DIR__"hou",
      ]));

  set("objects", ([
         __DIR__"npc/heshang"    : 2,
      ]));
  setup();
}

