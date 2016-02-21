//

#include <ansi.h>

inherit ITEM;


void create()
{
  set_name("公案", ({ "table"}));
  set_weight(30000);
  set("long", "一张长长的公案，上面堆的公文已被弄得乱七八糟，
只有中间一大本文簿(book)看来还算完好。\n" );


  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("material", "stone");
    set("value", 2000);
    set("no_get", 1);
    set("no_sell", 1);
  }
  setup();
}

