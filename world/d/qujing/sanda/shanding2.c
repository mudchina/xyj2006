//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "山顶");
  set ("long", @LONG

山顶上尽是些阴凉，根本就看不到天空，鸟儿在树林中欢快的歌唱
着，似乎根本不知道这世界上存在很多的危险，还有一些小的动物
经常从你的脚边跑过，你不禁童心大发，在你旁边还有一棵大桃树。
你可以试着爬上去看看。

LONG);

  set("exits", ([
        "southwest": "/d/qujing/baoxiang/yelu8",
        "southeast"     : __DIR__"shanding",
      ]));
  set("objects",([
        __DIR__"npc/gonggong":1,
        ]));
  setup();
}
