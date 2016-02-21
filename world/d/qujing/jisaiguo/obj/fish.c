// created 11/1/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name("鱼", ({ "fish"})); 
  set_weight(100);
  set("long","一条成精的鱼。\n");
  set("unit", "条");
  set("value",100);
  setup();
}

int init ()
{
  remove_call_out ("start_jump");
  call_out ("start_jump",1+random(3));
  add_action ("do_get", "get");
  return 1;
}

int do_get (string arg)
{
  object who = this_player();
  object fish = this_object();

  if (arg != "fish" &&
      arg != "all")
    return 0;

  message_vision("$N伸出手去捉$n，$n一摆从$N手中滑走了。\n",who,fish);
  return 1;
}


int start_jump ()
{
  object fish = this_object();
  string str = fish->query("name")+"跳了一跳。\n";
  tell_room (environment(fish),str);
  call_out("do_jump",5+random(5));
  return 1;
}

int do_jump ()
{
  object fish = this_object();
  string *msgs = ({
    "啪地一声，$N跳了起来。\n",
    "$N跳了跳。\n",
    "$N啪地一跳。\n",
    "$N一挺，跃在空中。\n",
    "$N轻轻一跃。\n",
    "$N动了动。\n",
  });
  string str;

  if (random(4) == 0)
  {
    call_out("jump_back",4);
    return 1;
  }

  str = replace_string (msgs[random(sizeof(msgs))],
                        "$N",fish->query("name"));
  tell_room (environment(fish),str);
  call_out("do_jump",3+random(15));
  return 1;
}

int jump_back ()
{
  object fish = this_object();
  string str = fish->query("name")+"跳走不见了。\n";
  tell_room (environment(fish),str);
  destruct (fish);
  return 1;
}
