// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shanwan1.c

inherit ROOM;

void create ()
{
  set ("short", "山湾");
  set ("long", @LONG

山湾地带有一些缓缓急急的水流，溪水哗哗作响。岸边是松
松的沼泽地，堆着枯枝烂叶。四处见山峦，路在这里显得宽
畅一些，地面较平坦。

LONG);

  set("exits", ([
        "westup"     : __DIR__"shan2",
        "east"       : "/d/qujing/baigudong/yelu4",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if (who->query("combat_exp") < 2000  && dir == "westup")
  {
    message_vision ("一阵腥风吹来，$N顿时头重脚轻。\n",who);
    call_out ("fall_down",1,who,environment(who));
    who->start_busy(1,1);
    return notify_fail("你禁不住踉跄了几下，两腿突然一软。\n");
  }
  return 1;
}

void fall_down (object who, object where)
{
  who->move(where);
  who->unconcious();
}

