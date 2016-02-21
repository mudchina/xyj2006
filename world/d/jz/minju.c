//Cracked by Roath

inherit ROOM;
void create ()
{
  set ("short", "民居");
  set ("long", @LONG

    不大不小的一间房子，正对你是一块发黄的门板，门是虚掩着的，
三块台阶已经上青绿了。门前只有一位老者，好象这家主人出门远行
了。
LONG);

  set("exits", ([
        "east"         : __DIR__"dingan-2",
      ]));
  set("objects", ([
      __DIR__"npc/laozhe"  : 1,
      ]));
  setup();
}
