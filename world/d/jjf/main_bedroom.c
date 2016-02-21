// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/main_bedroom.c

inherit ROOM;

void create()
{
  set("short", "卧房");
  set("long", @LONG
这是一间什麽也没有的空房间。
LONG
      );
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"main_cabinet2",
]));
  set("if_bed", 1);
  set("sleep_room",1);
  set("outdoors", 0);
  set("no_clean_up", 0);

  setup();
  replace_program(ROOM);
}
