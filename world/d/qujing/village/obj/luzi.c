//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/obj/luzi.c

 
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
  set_name(YEL"古铜兽炉"NOR, ({ "shou lu","luzi"}) );
  set_weight(500);
  set_max_encumbrance(20000);
  set_max_items(20);
  if( clonep() ){
    object ash;
    seteuid(getuid());
   if( ash=new("/u/city/obj/ash") )
      ash->move(this_object());
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是个很别致的炉子。\n");
    set("value", 2000);
    set("no_get",1);
  }
  init_hammer(1);
}

int is_container() { return 1; }
