// Room: /d/qujing/wudidong/houdong
inherit ROOM;

void create ()
{
  set ("short", "后洞");
  set ("long", @LONG

出了甬道，你眼前一亮。原来后洞比前洞还要大得多。方圆数百里都
种满了奇花异草。苍松迎客，碧柳垂腰，四处鸟语，遍地花香。若非
前洞和甬道里处处透出诡异，你真会以为这里是仙境了。北面一座大
殿，东边是座彩楼。西北角上有个石洞，洞门却是紧锁的。
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "dong" : "洞门口用一条粗大的铁链锁了起来。看来没钥匙是进不去了。
",
]));
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"square2",
  "north" : __DIR__"tang-gate",
  "east" : __DIR__"bedroom-gate",
]));
  set("light_up", 1);
  set("no_clean_up", 1);
  setup();
}
void init()
{
  add_action("unlock", "unlock");
  add_action("unlock", "kai");
}
int unlock()
{
  object me=this_player(), here=this_object(), key;
  int mykar=me->query_kar();
  int mystr=me->query("str")+me->query_skill("unarmed",1)/10-2;
  int factor;

  key=present("tie yaoshi", me);
  if(!key)
    return notify_fail("没钥匙怎么开锁？\n");
  if(here->query("lockbroken"))
    return notify_fail("锁孔里有东西，钥匙插不进去。\n");
  if(here->query("locked_from_inside"))
    return notify_fail("门上没锁，但是你就是拉不开。看来被人从里面反锁住了。\n");
  if(mystr<20)
    return notify_fail("你用尽了吃奶的力气，还是拧不动钥匙。\n");
  me->add_temp("mark/wudidong_times", 1);
  if(random(31-mykar)>mykar &&
     me->query_temp("mark/wudidong_times") < 18)
    {
      destruct(key);
      call_out("break_lock", 1);
      message_vision("$N把钥匙插入锁孔，但钥匙被锈住了。\n", me);
      return 1;
    }
  factor=random(mykar);
  if(factor<9 &&
     me->query_temp("mark/wudidong_times") < 18)
    {
      destruct(key);
      call_out("break_lock", 1);
      message_vision("$N把铁钥匙插进锁里，用力一拧。只听啪的一声，半截钥匙断在锁里了。\n", me);
      return 1;
    }
  if(key->query("name_recognized")!="real key" &&
     me->query_temp("mark/wudidong_times") < 18)
    {
      destruct(key);
      call_out("break_lock", 1);
      message_vision("$N把钥匙插入锁孔，但说什么也拧不动。$N一使劲，只听啪的一声，钥匙断了。\n", me);
      return 1;
    }
  destruct(key);
  call_out("lock_from_inside", 1);
  me->set_temp("mark/wudidong_times", 0);
  message_vision("$N把钥匙插在锁孔里拧了半天，终于把锁打开了。\n", me);
  message_vision("$N拉开了铁链，打开门，走了进去。\n", me);
  if (me->query_temp("mark/wudidong_yushu_gave_me_key"))
    {
      me->set_temp("mark/wudidong_opened_door", 1);
      me->delete_temp("mark/wudidong_yushu_gave_me_key");
    }
  me->move(__DIR__"lock");
  message("vision", "只听嘭的一声，洞门又被关上了。\n", this_object());
  message_vision("$N走进来，顺手关上了门，上了锁。\n", me);
  return 1;
}
void break_lock()
{
  this_object()->add("lockbroken", 1);
  call_out("unstuff_lock", 600);
  return;
}
void lock_from_inside()
{
  this_object()->add("locked_from_inside", 1);
  call_out("unstuff_lock", 600);
  return;
}
void unstuff_lock()
{
  this_object()->delete("lockbroken");
  this_object()->delete("locked_from_inside");
  return;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
