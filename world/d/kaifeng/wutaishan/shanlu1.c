// Room: /u/dragon/kaifengadd/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
                

　　沿着山路前行，望着那披着青松与白杨的冈峦，那映着
鲜花与绿草的山泉，那阵阵松涛和悠悠的钟声，那绿茸茸的
草地映衬着古庙琉璃瓦上的夕阳，不禁令人心旷神怡。

LONG);
  set("exits", ([
        "southdown" : __DIR__"qinglg",
        "northup" : __DIR__"shanlu2",
        "west" : __DIR__"shanlu3",
      ]));

  set("outdoors", __DIR__);

  setup();
  
}


