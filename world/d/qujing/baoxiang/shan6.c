// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shan6.c

inherit ROOM;

void create ()
{
  set ("short", "碗子山");
  set ("long", @LONG

山上黄土龟裂岩石层层，参差不奇地长着一些树林灌木。路从岩
石周围绕道铺设盘山而行，迂回曲折。四处风吹草动，空谷回音。
令人恍然不知所处。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"shan4",
        "southdown"  : __DIR__"shanwan3",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

