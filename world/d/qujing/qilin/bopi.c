// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "剥皮亭");
  set ("long", @LONG

剥皮亭里气氛阴森，亭子四处穿风八面明亮。亭上挂着各式大小不
一的兽皮兽头，中间放有一把戗金的交椅。两边有一些妖怪喽猡手
持兵器分行站立。

LONG);

  set("exits", ([ 
    "west" : __DIR__"dongnei",
    "northwest" : __DIR__"piangong",
  ]));
  set("objects", ([
    __DIR__"npc/nanyao" : 2,
    __DIR__"npc/yaowang" : 1,
  ]));
  setup();
}
