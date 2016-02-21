// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "卧王室");
  set ("long", @LONG

屋子里几盏酥香油灯照得四周通明，靠里面的洞壁放着一青花
木嵌银柜，一张镂花兽腿仙桌，上有透明玉雕大肚坛子，里面
盛着酥香油。

LONG);

  set("exits", ([
        "west"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi2"  : 1,
      ]));

  setup();
}



