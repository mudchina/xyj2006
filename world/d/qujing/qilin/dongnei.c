// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "洞内");
  set ("long", @LONG

洞内十分宽敞，悬崖石壁霞光升顶，左右有琪花瑶草，前后是古柏
乔松，洞壁上燃着盏盏吊油灯，烟熏火燎。两侧站着些大小妖怪森
森罗列。

LONG);

  set("exits", ([ 
    "east" : __DIR__"bopi",
    "southwest" : __DIR__"dongkou",
    "northwest" : __DIR__"dinglu",
    "northeast" : __DIR__"piangong",
  ]));
  set("objects", ([
    __DIR__"npc/nanyao" : 6,
  ]));
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "southwest")
    return 0;
  return ::valid_leave(who,dir);
}
