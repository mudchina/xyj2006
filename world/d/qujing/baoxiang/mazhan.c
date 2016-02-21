// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/mazhan.c

inherit ROOM;

void create ()
{
  set ("short", "马栈");
  set ("long", @LONG

这里是个简易的客栈，放着一排木板斜靠椅，对面是一排长长的床
榻。客人们远道而来可以将车马托交给栈后老板，然后上榻休息一
番。

LONG);

  set("exits", ([
        "west"       : __DIR__"bei4",
      ]));

  set("sleep_room",1);
  set("if_bed",1);
  set("valid_startroom", 1);
  setup();
}

