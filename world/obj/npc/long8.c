//庐山升龙霸
//lestat for dtxy 2001
//黑龙
 
#include <ansi.h>
inherit NPC;
void create()
{
   set_name(BLK"黑龙"NOR, ({"hei long", "hei", "long"}));
   set("age", 800);
   set("long", "一只模样高大，极有气势的龙。\n");
   set("str", 100);
   set("cor", 40);
   set("con", 40);
   set("cps", 40);
   set("spi", 40);
   set("int", 40);
   set_temp("apply/damage", 150);
   set_temp("apply/armor", 800);
   set("max_kee", 7200);
   set("max_sen", 7200);
   set("force", 18000);
   set("max_force", 10000);
   set("force_factor", 500);
   set("mana", 18000);
   set("max_mana", 10000);
   set("mana_factor", 500);
   set_skill("unarmed", 650+random(50));
   set_skill("parry", 650+random(50));
   set_skill("dragonfight", 650+random(50));
   set_skill("dragonstep", 650);
   map_skill("unarmed", "dragonfight");
   map_skill("dodge", "dragonstep");
   set("combat_exp", 60000000);
   set_weight(900000);
   setup();
}

