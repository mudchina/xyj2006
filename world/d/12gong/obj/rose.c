// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;


void create()
{
  set_name(HIR "红玫瑰" NOR, ({ "rose", "flower"}));
  set_weight(100);
  set("long","一朵带刺的红玫瑰，散发着一丝丝甜香。\n");
  set("unit", "朵");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("material", "flower");
  setup();
}
