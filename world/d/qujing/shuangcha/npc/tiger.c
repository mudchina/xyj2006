//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("斑斓虎", ({ "lao hu","tiger","hu" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "一只样子很凶狠的老虎。\n");
   
   set("str", 32);
   set("max_kee",400);
   set("kee",400);

   set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
   set("verbs", ({ "bite"})); 
   set_skill("unarmed",50);
   set_skill("parry",50);
   set("combat_exp",60000);
   set_temp("apply/attack", 20);
   set_temp("apply/armor", 10);

   setup();
}
void destruct_me (object me)
{
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
        object ob=this_object()->query_temp("my_killer");
        object corpse;
        object me=this_object();
        if(ob) {
        ob->set_temp("tiger_kill","yes");
        }
        message_vision ("$N惨叫一声，倒在血泊中。\n",me);
        corpse = CHAR_D->make_corpse(me,ob);
        corpse->move(environment(me));
        load_object("/obj/empty");
        me->move("/obj/empty");
        call_out ("destruct_me",3,me);
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
