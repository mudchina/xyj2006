// Room: /d/qujing/wudidong/tang-gate.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "殿门");
  set ("long", @LONG

已到了殿门口，依稀可以听到里面人声喧哗，杯盏叮当。只是守门的
这两个小妖看来不好对付。殿里定是这无底洞的洞主了，近在咫尺，
难道要缘悭一面？你不禁心痒难搔。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hudian" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houdong",
  "north" : __DIR__"inner-tang",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "north" && 
      member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1 &&
      me->query("family/family_name") != "陷空山无底洞" &&
      objectp(present("hudian yao", environment(me))))
    {
      message_vision(CYN"护殿妖喝道：呔！何方妖人，胆敢擅闯禁地！\n"NOR, me);
      return notify_fail("");
    }
  return ::valid_leave(me, dir);
}
