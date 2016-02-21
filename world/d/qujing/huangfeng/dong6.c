// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong6.c


inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞内光线昏暗，且有阵阵腥臭扑鼻。妖狐狡兔在你身边蹿
来跳去。你注意到西边墙角有一个小洞，不知道能不能钻
过去。

LONG);

  set("exits", ([
        "north" : __DIR__"dong5",
      ]));
       
  setup();
}

void init ()
{
  add_action ("do_zuan","zuan");
}

int do_zuan (string arg)
{
  object who = this_player();

  if ((! arg)||(arg != "dong" && arg != "小洞" && arg != "洞"))
    return 0;

  tell_object (who,"你蹲下身来，竟从小洞里钻了过去\n");
  who->move(__DIR__"anshi");
  return 1;
}