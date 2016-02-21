//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/in3.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

高台上放着两把太师椅，椅子是用人皮裹起来的。椅子的前面还升
着一盆火，火光把整个山洞照个通明，里面的妖精个个显的红光满
面，还有两个小妖在旁边服侍着老妖．
LONG);
  set("exits", ([
        "south": __DIR__"in2",
      ]));
      set("objects",([
        __DIR__"npc/laoguai":1,
      ]));
  setup();
}

       
