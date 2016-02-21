// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/hou.c

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里气氛宁静，灵台高筑，依次摆列着八菩萨的佛象。这里香
火也是不断，地上铺着一些旧蒲团。西边殿门通向正殿，往北向
上通往方丈楼。

LONG);

  set("exits", ([
        "northup"       : __DIR__"fang",
        "west"          : __DIR__"zheng",
      ]));

  set("objects", ([
        __DIR__"npc/heshang"    : 2,
      ]));
  setup();
}

