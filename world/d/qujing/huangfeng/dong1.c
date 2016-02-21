// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong1.c


inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞内光线昏暗，且有阵阵腥臭扑鼻。妖狐狡兔在你身边蹿
来跳去。往北通向洞的深处，南边是出洞的洞口。

LONG);

  set("exits", ([
        "south" : __DIR__"dongkou",
        "west" : __DIR__"dong2",
	"north" : __DIR__"dong3",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));
 
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
    return 0;
  return ::valid_leave(who,dir);
}
