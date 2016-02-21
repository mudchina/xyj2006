// key.c
// created by smile 12/13/1998

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIY "金钥匙" NOR, ({ "jin yaoshi","key","golden key","yaoshi" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把纯金打制而成的钥匙. \n");
    set("unit", "把");
    set("material", "gold");
    set("no_give", 1);
//    set("name_recognized", "golden key");
  }
  setup();
}

void init ()
{
  call_out ("destruct_me",600,this_object());
}

void destruct_me (object me)
{
  message_vision(HIY "只见一道金光闪过，金钥匙突然不见了!\n" NOR,me);
  destruct (me);
}

