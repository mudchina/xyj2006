
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name(HIM "变"+ HIR "色" + HIC "龙"NOR, ({ "bianse long","long"})); 
  set_weight(100);
  set("long","一只可爱伶俐的蜥蜴，也叫变色龙。这么乖巧的小动物，都喜欢看看的(kan).\n");
  set("unit", "只");
  set("value",100);
  setup();
}

int init ()
{
  remove_call_out ("start_jump");
  call_out ("start_jump",20+random(10));
  add_action ("do_get", "get");
  add_action ("do_look", "kan");
  return 1;
}

int do_get (string arg)
{
  object who = this_player();
  object bslong = this_object();

  if (arg != "bianse long" && arg != "long" && arg != "all")
    return 0;

  message_vision("$N伸出手去捉$n，$n一摆尾巴从$N手中游走了。\n",who,bslong);
  return 1;
}


int start_jump ()
{
  object bslong = this_object();
  string str = bslong->query("name")+"爬了爬，四只小爪子特别可爱。\n";
  tell_room (environment(bslong),str);
  call_out("do_jump",5+random(5));
  return 1;
}

int do_jump ()
{
  object bslong = this_object();
  string *msgs = ({
    "嗖地一声，$N迅速窜了几步。\n",
    "$N扭了扭尾巴。\n",
    "$N潜伏不动。\n",
    "$N的头往四周张望。\n",
    "$N轻轻一跃，咬住了一只蚊子。\n",
    "$N动了动。\n",
  });
  string str;

  if (random(4) == 0)
  {
    call_out("jump_back",4);
    return 1;
  }

  str = replace_string (msgs[random(sizeof(msgs))],
                        "$N",bslong->query("name"));
  tell_room (environment(bslong),str);
  call_out("do_jump",3+random(15));
  return 1;
}

int jump_back ()
{
  object bslong = this_object();
  string str = bslong->query("name")+"居然凭空消失了。\n";
  tell_room (environment(bslong),str);
  destruct (bslong);
  return 1;
}

int do_look (string arg)
{
  object who = this_player();
  object bslong = this_object();

  if (arg != "bianse long" && arg != "long" && arg != "all")
    return notify_fail("你要看什么？\n");
        if(!who->query("m_success/变色龙")){
  message_vision("$N仔细地看着$n，心里一闪灵光，好象悟出了什么。\n",who,bslong);
  who->set("m_success/变色龙",1);
                return 1;
                }
  return 1;
}
