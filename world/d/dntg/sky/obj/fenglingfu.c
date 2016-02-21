// sgzl

inherit ITEM;

void create()
{
  set_name("风灵符", ({"feng ling fu","fu"}));
  set("unit", "张" );
  set_weight(10);
  set("long", @LONG
一张风婆给的的灵符，需要起风时，不妨试试看祭(ji)它。
LONG);
  set("no_give","这种玩艺怎能随便给人？\n");
  set("no_sell","掌柜的摇摇头说：这宝贝小店不敢收。\n");
  setup();
}


