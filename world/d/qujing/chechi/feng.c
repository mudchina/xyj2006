// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/feng.c

inherit ROOM;

void create ()
{
  set ("short", "凤阁");
  set ("long", @LONG

凤阁里挤满了小姐少奶奶，阁檐上绘有两个银羽飞凤，展翅欲飞。
阁内一排花莲长椅，配有紫花茶几。一些无事小姐少奶奶们饭后
在此叽叽喳喳，品茶消食。

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi10",
      ]));
  set("objects", ([
        __DIR__"npc/feng"     : 5,
     ]));
  set("valid_startroom", 1);
  setup();
}

