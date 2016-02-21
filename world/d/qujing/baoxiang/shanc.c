// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/luochi1.c

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
        "west"       : __DIR__"luochi2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

void init ()
{
  object who = this_player();
  object where = environment(who);

  if (! present("qingpao guai",where))
  {
    object guai = new (__DIR__"npc/qingpao");
    guai->move(where);
  }
}

int valid_leave (object who, string dir)
{
  remove_call_out ("clearing");
  call_out ("clearing",3);
  return ::valid_leave(who, dir);
}

void clearing ()
{
  object guai = present ("guai", this_object());

  if (! guai)
    return;

  guai->disappearing();
  remove_call_out ("clearing");
  call_out ("clearing",3);
}
