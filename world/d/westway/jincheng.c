// create by snowcat.c 4/8/1997
// room: /d/westway/jincheng.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","金城郡南");
  set ("long", @LONG

金城郡是西北地区的重要城镇。向西看去，茫茫一片远处隐隐
约约有一群山脉。北边是金城郡南门，城门紧闭，城门洞里摆
着一小食摊在卖着什么。往东有一条大官道可以通达大唐国都
长安城。

LONG);

  set("exits", ([
        "west"      : __DIR__"dadao",
        "southeast" : __DIR__"west3",
        "northeast" : "/d/moon/xiaolu3",
      ]));
  set("outdoors", __DIR__);
    set("objects", 
        ([ //sizeof() == 1
                "d/qujing/kusong/npc/jiruhuo" : 1,
                            "/d/westway/npc/tanfan" : 1,
              ]));

         setup();
}





