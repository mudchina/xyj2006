// tmpbank.c
//cglaem...12/19/96.

inherit BANK;

void create()
{
	set("short", "相氏钱庄临时办事处");
	set("long", @LONG

因为长安城暂闭数日，相老板为顾客方便计，在泾水河边临
时开设了一个办事处，并派出他最得力掌柜铁算盘在此坐阵。
办事处只是一间简陋的小木棚，门口挂有一块牌子(paizi)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"eside1",
	]));

	set("item_desc", ([
		"paizi": @TEXT
这里是钱庄，目前我们提供的服务有：

check		查帐。
deposit		存款。
withdraw	取款。
convert		兑换钱币。

TEXT
	]) );

set("objects",([
  __DIR__"npc/tiesp" : 1,
 ]));
    
	setup();
}
