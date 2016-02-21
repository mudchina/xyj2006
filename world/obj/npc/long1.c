//庐山升龙霸
//lestat for dtxy 2001
//赤龙
 
#include <ansi.h>
inherit NPC;
void create()
{
   set_name(HIR"赤龙"NOR, ({"chi long", "chi", "long"}));
   set("age", 300);
   set("long", "一只模样高大，极有气势的龙。\n");
   set("str", 100);
   set("cor", 40);
   set("con", 40);
   set("cps", 40);
   set("spi", 40);
   set("int", 40);
   set_temp("apply/damage", 150);
   set_temp("apply/armor", 800);
   set("max_kee", 1200);
   set("max_sen", 1200);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 100);
   set("mana", 4000);
   set("max_mana", 2000);
   set("mana_factor", 100);
   set_skill("unarmed", 150+random(50));
   set_skill("parry", 150+random(50));
   set_skill("dragonfight", 150+random(50));
   set_skill("dragonstep", 50);
   map_skill("unarmed", "dragonfight");
   map_skill("dodge", "dragonstep");
   set("combat_exp", 3000000);
   set_weight(500000);
   setup();
}

