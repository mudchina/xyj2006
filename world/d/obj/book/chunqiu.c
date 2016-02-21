// chunqiu, level 61-100

inherit ITEM;
void init();

void create()
{
  set_name("〖春秋〗", ({"chunqiu", "book","shu"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("long", "一本古香古色的小册子，记载着：春秋战国，诸侯争霸．侠客列转。\n");
    set("material", "cloth");
    set("value", 125);
  }
}

void init()
{
  if (!wizardp(this_player())) {
    set("no_drop",1);
    set("no_sell",1);
    set("no_give",1);
  }
  add_action("do_read", "read");
//  call_out ("destroy_book", 10800);
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,forcelev,exp;

  if( !book->id(arg) ) return notify_fail("你要读什么？\n");
  if( environment(book)!=me ) return notify_fail("书要拿起来读。\n");
  if(me->is_busy()) return notify_fail("你现在忙着呢，还是等静下心来再读书吧！\n");
  if(me->is_fighting()) return notify_fail("临阵磨枪可来不及啦！\n");
  if( (int)me->query_skill("literate",1)<60 )
    return notify_fail("你拿起书仔细读了半天，但怎么也读不懂。\n");
  if( (int)me->query_skill("literate",1)>100 )
    return notify_fail("你在这方面已经很有造诣，这本书不会让你长进多少。\n");
  sen_cost=10+(40-(int)me->query_int())+(35-(int)me->query_kar());
if ( sen_cost < 10 ) sen_cost = 10 ;
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/5;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("literate", gain);

  message_vision("$N正专心地研读"+book->query("name")+"。\n", me);
  tell_object(me, "你研读有关读书识字的技巧，似乎有点心得。\n");

  return 1;
}

void destroy_book()
{
	message_vision("一阵风吹来，" + (string)this_object()->query("name") + "片片碎落，随风而去了。\n", environment(this_object()));
	destruct(this_object());
}
