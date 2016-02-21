// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong5.c


inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞内光线昏暗，且有阵阵腥臭扑鼻。妖狐狡兔在你身边蹿
来跳去。好在没有人注意你，还是快些离开吧。

LONG);

  set("exits", ([
	"north" : __DIR__"chang",
        "south" : __DIR__"dong6",
        "east" : __DIR__"dong4",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));
      
  setup();
}