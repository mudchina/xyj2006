//庐山升龙霸
//lestat for dtxy 2001
//黄龙
 
#include <ansi.h>
inherit NPC;
void create()
{
   set_name(HIY"黄龙"NOR, ({"huang long", "huang", "long"}));
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
   set("max_kee", 3200);
   set("max_sen", 3200);
   set("force", 9000);
   set("max_force", 4500);
   set("force_factor", 225);
   set("mana", 9000);
   set("max_mana", 4500);
   set("mana_factor", 225);
   set_skill("unarmed", 250+random(50));
   set_skill("parry", 250+random(50));
   set_skill("dragonfight", 250+random(50));
   set_skill("dragonstep", 250);
   map_skill("unarmed", "dragonfight");
   map_skill("dodge", "dragonstep");
   set("combat_exp", 10000000);
   set_weight(700000);
   setup();
}

