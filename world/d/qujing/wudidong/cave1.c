inherit ROOM;

int do_leap();
void reset();

void create ()
{
  set ("short", "秘洞");
  set ("long", @LONG

这里是无底洞的一条秘道，寻常小妖不准进出。正待迈步，突然发现
脚下竟是万丈深渊，黑漆漆的，望不见底。黑暗之中你极目远眺，只
见模模糊糊的似乎是另一处悬崖。看上去两峰之间不过一纵之遥，但
一失足。。。
LONG);
  set("outdoors", 0);
  setup();
}
void init()
{
  add_action("do_leap", "leap");
  add_action("do_leap", "jump");
  add_action("do_leap", "tiao");
  add_action("do_push", "push");
  add_action("do_push", "tui");
}
int do_leap()
{
  object me, corpse;
  int mydodge,mykar,factor,mypot,mylp,mynewpot;

  me=this_player();
  mydodge=(int)me->query_skill("dodge");
  mykar=(int)me->query_kar();
  factor=mydodge+mykar*4;
//  if ( random(factor) < random(mydodge) )
   if (me->query("family/master_id") != "yu shu")
    {
      message_vision("$N一个没站稳，掉下绝崖，粉身碎骨，西天去了！\n", me);
      me->delete_temp("last_damage_from");
      me->set_temp("death_msg", "摔死了。\n");
      me->die();
      me->save();
      corpse=present("corpse");
      if (corpse) destruct(corpse);
      return 1;
    }
  else
    {
      message_vision("$N腾空纵起，跳到对崖去了。\n", me);
      me->move(__DIR__"cave2");
      return 1;
    }
}

int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query_skill("unarmed",1)/10-2+me->query("str");
  int mystr=me->query_str();
  int myforce=me->query("maximum_force");

  if ( !arg || ((arg !="men") ))
    return notify_fail("你要推什么？ \n");
  if ( mystr <50 || myeffstr<20) 
    return notify_fail("你力气太小了，推不动！ \n");
  if (random(myforce)>1000)
    {
      message_vision("$N推石门时用力过猛，似乎受了内伤。\n", me);
      me->add_maximum_force(-myforce/100);
    }
  message_vision("$N一推石门，突然间，一阵阴风把$N推到了另一间房间去了。\n", me);
  me->move(__DIR__"inner-bedroom");
  message_vision("石门翻转处，$N走了过来。\n", me);
  return 1;
}
