// Room: /u/dragon/kaifengadd/qinglianggu.c

inherit ROOM;

void create()
{
	set("short", "清凉谷");
	set("long", @LONG
        

　　走到谷口，一股清风吹来，令人心情为之一畅。这里就
是四季如春的清凉谷了。

LONG);
  set("exits", ([
        "southdown" : __DIR__"wutx",
        "northup" : __DIR__"shanlu1",
      ]));

  set("outdoors", __DIR__);

  setup();
  
}


