// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dongwai.c

inherit ROOM;

void create ()
{
  set ("short", "黑松林");
  set ("long", @LONG

山路崎岖，松林丛簇藤攀葛绕，边上是一带林丘，柏翠松青。林
子内长满野草山花，幽幽暗暗，看起来这里草深路小，不知能通
向何处。

LONG);

  set("exits", ([
        "north"      : __DIR__"shan5",
        "southeast"  : __DIR__"dongwai",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

