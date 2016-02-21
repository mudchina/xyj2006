// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//

#include <ansi.h>

inherit ITEM;

string *prefixs = ({
  "大",
  "小",
  "黑",
});

string *names = ({
    "石",
    "木",
    "方",
});

string *suffixs = ({
  "案台",
  "桌",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({ "table" }));
  set_weight(30000);
  set("long", "这是一张桌子。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("material", "stone");
    set("value", 2000);
    set("no_sell", 1);
  }
  setup();
}

void init ()
{
  object me = this_object();
  object where = environment(me);
  
  if (where && userp(where))
  {
    remove_call_out ("destruct_me");
    call_out ("destruct_me",900+random(900),me);
  }  
}

void destruct_me (object me)
{
  destruct (me);
}