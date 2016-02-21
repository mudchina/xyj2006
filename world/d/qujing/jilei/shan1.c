//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

只见山高路险，岭上或是光秃秃奇岩怪峥嵘一片，或是树木成
森林，大风呼啸地吹过，又听得野猿虎豺远远地长吼，有点令
人胆颤心惊。

LONG);

  set("exits", ([
        "southeast"   : __DIR__"shan2",
        "west"   : "/d/qujing/jisaiguo/to-baoxiang5",
      ]));
  set("outdoors", __DIR__);

  setup();
}



