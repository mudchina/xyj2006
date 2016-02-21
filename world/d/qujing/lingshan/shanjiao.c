//Cracked by Roath


// create by snowcat.c 12/8/1997


//note, disabled access due to qujing change...weiqi

inherit ROOM;

void create ()
{
  set ("short", "灵山脚");
  set ("long", @LONG

只见山上松临雨过青，花向春来美。远远可见山上祥云瑞瑞，
彩霞如练虹。遍野是各种各样紫芝仙果灵草，黄鹤信步，彩鸾
成双飞。

LONG);

  set("exits", ([
        "north"   : __DIR__"dalu1",
        "westup"   : __DIR__"yang3",
      ]));
  set("objects", ([
        __DIR__"npc/jinding" : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



