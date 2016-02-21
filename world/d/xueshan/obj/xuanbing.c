//Cracked by Roath
inherit ITEM;

#include <ansi.h>

void create() 
  {
   set_name("玄冰",({"xuan bing"}));
        set ("long", @LONG
一块玄冰，冒着丝丝白气，不知到底有多冷。
LONG);
   set_weight(10);
   set("unit","块");
   set("cook/allow",1);
   set("cook/value",5);
   set("cook/type","shui");
   setup();
  }

