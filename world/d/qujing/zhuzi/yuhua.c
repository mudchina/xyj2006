// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "御花园");
  set ("long", @LONG

这里朱栏紫槛，奇花异草满园生长与丽日争艳。园中有一圆池流水
潺潺于小桥下穿过，更有一长短亭造型精美，亭外垂柳飘然，修篁
依依。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zheng",
    "northeast" : __DIR__"qian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}


