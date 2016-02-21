inherit ROOM;

void create ()
{
  set ("short", "潜能股市交易所");
  set ("long", @LONG

这里是刺激非常的潜能股市交易所，你在这里可以用潜能进行股市交
易，大厅上方有个牌子(paizi)教你怎样进行股票交易。由于股市变
幻莫测，入市者要经常到这里查看股市最新情况。

LONG);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kezhan",
    
]));
   
  set("no_fight", 1);
  set("no_magic", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
    查看股票最新价格：check
    卖出股票：sell
    买入股票：buy

"]));
  setup();
  
}

void init()
{
    add_action("do_check", "check");
    add_action("do_buy", "buy");
    add_action("do_sell","sell");
}

int do_check(string name)
{
	string output;
	output = "/adm/daemons/gushid"->gushi_list(name);
	this_player()->start_more(output);
        return 1;
}
        