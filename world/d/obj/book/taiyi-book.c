//taiyi, 1-50, weiqi
// taiyi-book.c

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("【太乙真经】", ({"taiyi zhenjing","taiyi","zhenjing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long",
	"一本小册子，封面上【太乙真经】几个字写得妙境无穷。\n");
        set("material", "paper");
        set("value", 500);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");

	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_book");
		call_out ("destroy_book", 18000);//5 hours

	}
}

void destroy_book()
{
	message_vision("天空中翻出一只大袖，将" + (string)this_object()->query("name") + "轻轻一卷，消失在云端。\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("书要拿起来读。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有可能静心研读...\n");
   	if( me->is_fighting() )
        		return notify_fail("现在才想到精研太乙仙法，太晚了吧？\n");
	if( (int)me->query_skill("literate", 1) < 150 ) 
		return notify_fail("你看了半天，里面不少字都是它认得你你不认得它。\n");
	if( (int)me->query_skill("taiyi",1)>250 )
		return notify_fail("你在太乙仙法方面已经很有造诣，这本书不会让你长进多少。\n");

	sen_cost = 25 + random((30-(int)me->query("int")));
	if( sen_cost < 10 ) sen_cost = 10;
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
	me->improve_skill("taiyi", gain);

	message_vision("$N哼哼叽叽地翻看着一本小册子。\n", me);
		
	return 1;
}

