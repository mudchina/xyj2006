// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "毒敌山");
  set ("long", @LONG

毒敌山脉在一望无际的视野里起伏，山峰峻险，不时可见脚下
雾气腾起如生云一般。山上，石岩石崖间开辟出一条小路弯曲
而上，路的西边是万丈深崖，令人胆寒。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"dudi2",
        "southeast"   : __DIR__"dudi4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



