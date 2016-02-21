// parrybook2.c,level 100-140
// by pickle
inherit ITEM;

void create()
{
  set_name("〖少林拆招秘诀〗", ({"mi jue", "parry book", "mijue", "book", "shu", "jue","parry"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("long", "
少林僧人在唐初战争中立下了不少战功，也有不少阵亡。
战乱中，不少少林的武功密笈也因此流失在外。这本拆招
秘诀听说是尉迟恭所救的一位少林高僧赠给他的。\n");
    set("material", "paper");
    set("value", 0);
  }
}

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
    set("no_drop",1);
    set("no_sell",1);
    set("no_give",1);
  }
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,lev,exp;

  if( !book->id(arg) ) return notify_fail("你要读什么？\n");
  if( environment(book)!=me ) return notify_fail("书要拿起来读。\n");
  if(me->is_busy()) return notify_fail("你现在忙着呢，还是等静下心来再读书吧！\n");
  if(me->is_fighting()) return notify_fail("临阵磨枪可来不及啦！\n");
  if( (int)me->query_skill("parry",1)<100 )
    return notify_fail("你拿起书仔细读了半天，但怎么也读不懂。\n");
  if( (int)me->query_skill("parry",1)>140 )
    return notify_fail("你在这方面已经很有造诣，这本书不会让你长进多少。\n");
  exp=(int)me->query("combat_exp");
  lev=(int)me->query_skill("parry", 1);
  if(exp*10 < lev*lev*lev)
    return notify_fail("你的道行不够，再怎么读也没用。\n");
  sen_cost=10+(40-(int)me->query_int())+(35-(int)me->query_kar())+(int)lev/5;
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate",1)/5;
  gain -= random(me->query_int());
  gain +=random(me->query_kar());
  if(gain < 0) gain=0;
  me->improve_skill("parry", gain);

  message_vision("$N正专心地研读"+book->query("name")+"。\n", me);
  tell_object(me, "你研读有关拆招卸力之法的技巧，似乎有点心得。\n");

  return 1;
}





