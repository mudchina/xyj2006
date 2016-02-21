// Room: /d/changan/tmppawn.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "三喜当铺临时办事处");
	set("long", @LONG

三喜当铺在长安算是最大的当铺了。因长安南门暂闭，所以在
泾水河边临时开了个办事处。门口有一块牌子(paizi)。你揭
开门帘进来后才发现里面很暗。掌柜的见你进来，象防贼似的
赶紧把柜台上的几小块碎银收到柜台底下。
LONG
	);
	set("item_desc", ([
		"paizi": @TEXT
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客官可以在这里估价(value)，典当(pawn)，卖断(sell)，
赎回(retrieve stamp)，购买(buy)(用list查看)
各种货物，铜钱、银两、黄金、银票一概通用。
TEXT
	]) );
	set("exits", ([
		"south" : __DIR__"eside2",
	]));

	setup();
}
