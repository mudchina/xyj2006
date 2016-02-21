//sgzl

inherit NPC;

void create()
{

  set_name("小金鱼", ({"xiao jin yu", "xiao yu", "fish", "yu"}));
  set("long","一条小金鱼，正在海中自由自在的游着。\n");

  set("title", "引路使者");
  set("age", 2);
  set("race", "野兽");

  set_skill("dodge", 60);
  set("combat_exp", 10);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  setup();
}

void init()
{
  object me=this_object();

  ::init();
  remove_call_out("yinlu");
  call_out("yinlu", 10, me);
}

void yinlu (object me)
{
  me->command("west");
  call_out("yinlu1", 10, me);
}

void yinlu1 (object me)
{
  me->command("east");
  call_out("yinlu2", 10, me);
}

void yinlu2 (object me)
{
  me->command("north");
  call_out("yinlu3", 10, me);
}

void yinlu3 (object me)
{
  me->command("east");
  call_out("yinlu4", 10, me);
}

void yinlu4 (object me)
{
  me->command("south");
  call_out("yinlu5", 10, me);
}

void yinlu5 (object me)
{
  me->command("west");
  call_out("yinlu6", 10, me);
}

void yinlu6 (object me)
{
  me->command("south");
  message_vision("小金鱼一摆尾巴不知游到哪里去了。\n",me);
  me->move("/d/dntg/donghai/mazee");
}


