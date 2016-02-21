//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "凌云渡");
  set ("long", @LONG

雾气中，一道山涧冲下来，滚浪飞流。山涧下是万丈飞虹，水
面宽阔翻滚着千条白练。渡口岸见不到其它的路可走，上面架
着一根独木桥。

LONG);

  set("exits", ([
        "southeast"   : __DIR__"dumuqiao",
        "westup"   : __DIR__"shandian",
      ]));
  set("outdoors", __DIR__);

  setup();
}



