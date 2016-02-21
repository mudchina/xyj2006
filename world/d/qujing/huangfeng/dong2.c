// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong2.c


inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞内光线昏暗，且有阵阵腥臭扑鼻。妖狐狡兔在你身边蹿
来跳去。好在没有人注意你，还是快些离开吧。

LONG);

  set("exits", ([
        "east" : __DIR__"dong1",
      ]));
       
     set("objects", ([
                __DIR__"npc/huxianfeng": 1 ]) );

  setup();
}
