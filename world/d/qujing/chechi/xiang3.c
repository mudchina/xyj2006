// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xiang3.c

inherit ROOM;

void create ()
{
  set ("short", "厢房");
  set ("long", @LONG

厢房里整整齐齐，南北各有一红砖大炕，铺着锦花棉被。炕上
有硬木炕桌，放有茶锺瓷碗。墙上有一些字画，写着：“罗天
大醮，彻夜看经。”

LONG);

  set("exits", ([
        "west"         : __DIR__"xiang2",
      ]));

  set("objects", ([
         __DIR__"npc/daoshi"    : 2,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

void init ()
{
  object shi1 = present ("dao shi 1", this_object());
  object shi2 = present ("dao shi 2", this_object());

  remove_call_out ("sleeping");
  if (random(2))
    call_out ("sleeping",1+random(3),shi1);
  else
    call_out ("sleeping",1+random(3),shi2);
}

void sleeping (object shi)
{
  if (! shi)
    return;
  if (interactive(shi))
    return;
  shi->command_function("sleep");
}
