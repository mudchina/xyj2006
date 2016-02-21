// by snowcat

inherit ROOM;

void create()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里庄严肃穆，墙上绘有金龙戏珠，殿顶上画着紫色祥云朵朵缭
绕，瑞气朦胧。殿墙边是凤尾屏风，地上铺着银花绣绒毯，殿里一
阵阵丝竹乐声轻缓地飘来。

LONG);
  set("exits", ([ 
    "south" : __DIR__"dadian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  setup();
}

