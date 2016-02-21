//created by vikee
//2000.10

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("火鸦", ({ "huo ya","ya","huoya" }) );
   set("race", "野兽");
   set("age", 500);
   set("long", "太上老君的火部神兵之火鸦.\n");   
   set("str", 40);
   set("per", 400);
   set("cor", 26);   
   set("combat_exp",500000);
   set("daoxing",1500000);
   set("max_force",800);
   set("force",800);
   set("max_mana",2000);
   set("mana",2000);
   set("max_kee",800);
   set("max_sen",800);
   set("attitude", "aggressive");
   set_skill("dodge",140);
   set_skill("dragonstep",40);
   set_skill("dragonfight",80);
   set_skill("parry",180);
   set_skill("unarmed",180);
   map_skill("unarmed","dragonfight");
   map_skill("parry","dragonfight");
   map_skill("dodge","dragonstep");
   set("limbs", ({ "头部", "身体", "脚爪", "尾巴","翅膀"}) );   
   setup();
   set("chat_msg_combat", ({
                (: cast_spell, "zhenhuo" :),

   }) );

}


void die()
{
            if( environment() ) 
        message("sound", ""HIY"火鸦消失在火光之中。"NOR"\n", environment());        
                destruct(this_object());
}

