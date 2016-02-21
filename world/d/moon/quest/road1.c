//Cracked by Roath

inherit ROOM;
#include <room.h>

int index=1;
void create ()
{
  set ("short", "羊肠小道");
  set ("long", @LONG

一条蜿蜒曲折的小径，两边都是刀削般的峭壁。
路旁长满了一人多高的野草，据说常有妖怪精灵
出没。

LONG);
  set("exits", ([ /* sizeof() == 3 */
  "east": __DIR__"enter",
  "east": __DIR__"enter",
]));

  setup();
}

void init() {
  object me=this_player();

  me->start_busy(random(2)+1);
  call_out("greeting",1);
}

void greeting() {
    object npc;
  if (present("little elf",this_object()) || present("monster",this_object())) return;
  if (random(2))  npc=new(__DIR__"npc/beauty");
  else   npc=new(__DIR__"npc/beast");
  npc->move(this_object());
  message_vision("路旁草丛里“嗖”的一声窜出一只$N。\n",npc);
}

int valid_leave(object me, string dir) {
  object npc;

  if (dir=="east") return 1;

  if (npc=present("monster",this_object())) 
    return notify_fail(npc->name()+"拦在你的身前不让你过。\n");

   if (npc=present("little elf",this_object()))
     return notify_fail(npc->name()+"拉住你的衣角舍不得让你走。\n");
  return 1;
}

