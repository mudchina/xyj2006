// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/chaoxing.c

inherit ROOM;

void create ()
{
  set ("short", "潮星谷");
  set ("long", @LONG

周围是略隆起的山坡，中心下凹地面柔软，行如谷状。大小岩石
呈暗红色，长满绿色苔藓。东边有一些半人高的灌木，爬有粗粗
的藤状植物。

LONG);

  set("exits", ([
        "west"       : __DIR__"luochi2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  set("objects", ([ 
          __DIR__"npc/shanyao" : 6,
       ]));

  setup();
}

int init ()
{
  add_action ("do_sink", "sink");
  add_action ("do_down", "down");
}

int do_sink(string arg)
{
  object who = this_player();

  if (arg)
    return 0;
  message_vision("$N脚下一软！\n",who);

  who->move(__DIR__"shanc");
  return 1;
}

int do_down(string arg)
{
  object who = this_player();

  if (arg)
    return 0;

  message_vision("$N脚下一软！\n",who);
  if (random(2))
    who->move(__DIR__"shana");
  else  
    who->move(__DIR__"shanb");
  return 1;
}
