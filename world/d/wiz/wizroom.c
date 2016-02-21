// Room: /d/wiz/wizroom.c

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","巫师会议厅");
  set ("long", @LONG

这里是巫师聊天讨论的地方，如果巫师们要开会的话，也多半会选在这
里举行。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "north" : __DIR__"jobroom",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "jail":__DIR__"punish",
  "kz": "/d/city/kezhan",
"up":"/d/wiz/newsroom",
 ]));
set("objects", 
 ([ //sizeof() == 1
"/d/wiz/npc/welcome": 1,
 ]));
  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}

