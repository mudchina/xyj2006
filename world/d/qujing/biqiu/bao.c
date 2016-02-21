// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "宝殿");
  set ("long", @LONG

宝殿里万盏烛火通明，镀金紫香炉两边排开，股股青烟祥瑞地
慢慢缥缈升起。殿中间是狮虎豹狼熊狐狸百兽皮地毯，上面有
一琉璃座牙雕绣珠宝座。

LONG);

  set("exits", ([
        "east"    : __DIR__"da",
        "south"    : __DIR__"yu",
      ]));
  set("objects", ([
        __DIR__"npc/guozhang"    : 1,
        __DIR__"npc/king"    : 1,
        __DIR__"npc/taijian"    : 1,
      ]));
  setup();
}

