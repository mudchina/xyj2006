#include <ansi.h>
// creat by canoe 
// 打鸟不中的惩罚
inherit NPC;
void create()
{
  set_name("草头神", ({"caotou shen","shen"}));
  set("gender", "男性");
  set("age", 20+random(20));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "他是专管这个园林的草头神中的一个。\n");
  set("attitude", "peaceful");
  set("combat_exp", 30000);
   set_skill("dodge", 25+random(30));
    set_skill("unarmed", 25+random(30));
    set_skill("parry", 25+random(30));
    set("max_gin", 300);
    set("max_kee", 300);
    set("max_sen", 300);
  set("force", 200);
  set("max_force", 100);
    set("force_factor", 30);
  set("mana", 200);
  set("max_mana", 100);
  set("mana_factor", 10);
  set_weight(300000);
  setup();

}
void init()
{
call_out("dest", 120);
}

int dest()
{
remove_call_out("dest");
message_vision(HIB"$N吐了口唾沫说道:奶奶的,别让我看到你!转身隐入草丛。\n"NOR,this_object());
destruct (this_object());
}
void die ()
{
        object me = this_object();
        message_vision ("\n$N嗖的一声,逃回树林了......\n",me);
        destruct (me);
        return ;
  
}


void unconcious()
{
   die();
 }

