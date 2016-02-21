// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "中堂");
  set ("long", @LONG

堂内放着一把虎纹虎脚交椅，两边有双狮头石雕神龛，点着昏
暗的兽油灯。堂后滴水嗒嗒有声，雾气缭绕。东边有一廊道通
向剥皮亭，西有一偏堂。

LONG);

  set("exits", ([
        "east"    : __DIR__"bopiting",
        "west"    : __DIR__"pian",
      ]));
  set("objects", ([
        __DIR__"npc/yaowang" : 1,
      ]));
  setup();
}

