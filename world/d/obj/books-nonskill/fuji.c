// xiyouxiji.c
// created 4-26-97 pickle

#include "book.h";
inherit ITEM;
inherit BOOK;

int do_read(string arg);
void create()
{
	set_name("〖扶乩真伪〗", ({"fuji",}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "

※※※※※※※※※
※　　　　　　　※
※"+HIY+"　 扶乩真伪 　"+NOR+"※
※　　　　　　　※
※作者: 不祥　　※
※转录: 明空　　※
※书价: 十两白银※
※※※※※※※※※
\n\n
");
		set("material", "paper");
		set("value", 1000);   
	}
}

void init()
{
    add_action("do_read","read");
}

int do_read(string arg)
{
    if (!this_object()->id(arg))
      return notify_fail("你要读什么？\n");
    read_book(this_player(), this_object()->query("id"));
    return 1;
}
