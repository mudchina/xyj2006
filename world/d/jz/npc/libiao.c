//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("李彪", ({"li biao","libiao","li"}));
        set("gender", "男性");
        set("age", 38);
        set("title","江州知爷");
        set("long","一个身强力壮的男人，怎么看也不象知爷。");
        set("attitude", "friendly");
        set("per", 10);
        set("str", 40);
        set("combat_exp",50000);
	set("daoxing",50000);		
        set("max_force",1000);
        set("force",1000);
        set("force_factor",40);
        set("max_kee",300);
        set("max_sen",300);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",70);
        set_skill("changquan",80);
        map_skill("unarmed","changqaun");
        map_skill("parry","houquan");

        setup();
}
void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/jz_libiao_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("李彪死了。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/jz/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}

void unconcious ()
{
  die ();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


