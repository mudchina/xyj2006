// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name(HIB "鱼" NOR, ({ "fish"})); 
  set_weight(100);
  set("long","一条鱼。\n");
  set("unit", "条");
  set("value",100);
  setup();
  call_out ("start_jump",1+random(1));
}

void init ()
{
  add_action ("do_get", "get");
}

int do_get (string arg)
{
  object who = this_player();
  object fish = this_object();

  if (arg != "fish" &&
      arg != "all")
    return 0;
  if (random(2) < 1){
      fish->move(who);
      message_vision("$N伸出手去捉鱼，哈哈，捉到了!\n", who);
      remove_call_out("do_jump");
	}
  else
      message_vision("$N伸出手去捉鱼，鱼儿一摆从$N手中滑走了。\n",who);
  return 1;
}


int start_jump ()
{
  object fish = this_object();
  message_vision ("鱼儿从水里跳了出来。\n",fish);
  call_out("do_jump",5+random(5));
  return 1;
}

int do_jump ()
{
  object fish = this_object();
  string *msgs = ({
    "啪地一声，鱼儿跳了起来。\n",
    "鱼儿跳了跳。\n",
    "鱼儿啪地一跳。\n",
    "鱼儿一挺，跃在空中。\n",
    "鱼儿轻轻一跃。\n",
    "鱼儿动了动。\n",
  });

  if (random(4) == 0)
  {
    call_out("jump_back",4);
    return 1;
  }

  message_vision (msgs[random(sizeof(msgs))],fish);
  call_out("do_jump",3+random(15));
  return 1;
}

int jump_back ()
{
  object fish = this_object();
  message_vision ("鱼儿跳入水中不见了。\n",fish);
  destruct (fish);
  return 1;
}
