//malemace.c
//created 5-30-97 pickle
//please do not use, this weapon reserved for /d/jjf/npc/yuchigong.c

#include <weapon.h>
#include <ansi.h>

inherit MACE;
inherit F_UNIQUE;

void create()
{
  set_name(YEL "虎尾鞭" NOR, ({"tiger mace", "mace", "tigermace", "tiger"}));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 18000);
    set("material", "steel");
    set("long", "这是一柄精钢铸成的虎尾鞭，据说是一对雌雄双鞭中的雄鞭。\n");
    set("wield_msg", "$N从肩上取下一个布袋，解了开来，袋中竟然是$n！\n");
    set("unwield_msg", "$N拿起布袋擦了擦$n，又把它小心翼翼地包了起来。\n");
	set("replace_file", "/d/obj/weapon/mace/ironmace");
  }
  
  init_mace(85);
  setup();
}

