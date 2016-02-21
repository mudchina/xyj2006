 //sgzl
#include <ansi.h>

inherit NPC;

void create()
{
          set_name(HIW"沙和尚"NOR,({"sha heshang","sha","heshang"}));
          set("gender", "男性");
          set("title", HIY"三徒弟"NOR);
          set("age", 23);
          set("per",30);        
          set("combat_exp", 1800000);
	  set("daoxing",1500000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 2200);
          set("kee",2200);
          set("force_factor",20);
          set("max_sen", 1800);
          set("sen",1800);
          set("force", 6000);
          set("max_force", 3000);
          set("max_mana", 3000);
          set("mana", 6000);
          set_skill("unarmed", 180+random(50));
          set_skill("dodge", 180+random(50));
          set_skill("force", 180+random(50));
          set_skill("parry", 180+random(50));
          set_skill("staff", 180+random(50));
          set_skill("spells", 180+random(50));
          set_skill("buddhism",180+random(50));
          set_skill("jienan-zhi", 180+random(50));
          set_skill("lotusforce", 180+random(50));
          set_skill("lotusmove", 180+random(50));
          set_skill("lunhui-zhang", 180+random(50));
          map_skill("spells", "buddhism");
          map_skill("unarmed", "jienan-zhi");
          map_skill("force", "lotusforce");
          map_skill("staff", "lunhui-zhang");
          map_skill("parry", "lunhui-zhang");
          map_skill("dodge", "lotusmove");
          set_temp("apply/attack", 200); 
	  set_temp("apply/defense", 200);
	  set_temp("apply/armor", 200);
	  set_temp("apply/damage", 200);
          set("force_factor",300);
          set("mana_factor",300);
          set("bellicosity",300);
          set("nk_gain", 100+random(50));
          set("nk_factor", 12);
  
         setup();
         carry_object("/d/qujing/liusha/obj/staff")->wield();

        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
}

void init()
{
  ::init();
  add_action("do_no", "fight");
  add_action("do_no", "kill");
  add_action("do_no", "steal");
  add_action("do_no", "cast");
  add_action("do_no","ji");
  add_action("do_no","throw");
  call_out("leave",5);  
  add_action("do_block","",1);
}

void leave()
{
          object me = this_object(); 
      object where = environment (me);
      object ts = present ("tang sanzhang", where);
      object ts2 = find_living("tang sanzhang");
  
      
      if (!ts2)
       {   
        command("say 师傅都没了，我还是回流沙河当妖怪去了。。。");
        message("vision",HIB + name() + "一溜烟的跑了。\n" NOR,environment());
        remove_call_out("leave");
        destruct(this_object());
        return ;
       }else{
       
        if(!ts) 
         {  command("say 我得找我师傅去了。。。");
            message("vision",HIB + name() + "一溜烟的跑了。\n" NOR,environment());
            if (environment(ts2))
               { 
               	   me->move(environment(ts2));
               }else{
                   remove_call_out("leave");
                   destruct(this_object());
                   return ;
                }   
                   
          }  
       	}
       
   remove_call_out("leave");
   call_out("leave",20); 
   return;

}
int do_no(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg!="tang sanzhang"&&who->query_temp("qujing_kill")!=1)
     {
        message_vision("$N鬼鬼遂遂不知想干什么，$n警惕的盯着$N。\n",who,me);
        return 1;
     }  
  return 0;
}



void die ()
{
        object me = this_object();
        message_vision ("\n$N掉头就走,边跑边喊:  我先回流沙河去了......\n",me);
        load_object("/obj/empty");
        me->move("/obj/empty");
        call_out ("destruct_me",3,me);
  
}

void destruct_me (object me)
{
  destruct (me);
}

void unconcious()
{
   die();
 }

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    // wizardp(who) && 
    
    if(!userp(who)) return 0;
       
      
    if(who->query_temp("qujing_kill")==0) return 0;
       
    if(verb!="go" &&
            verb!="fly" &&
            !(environment() && environment()->query("exits/" + verb)))
        return 0;
    
    t= random(3);
   
    if (t==1) {
        
        message_vision("$n乘$N一个不注意，急忙溜了过去。\n",me,who);
        return 0;
    }
   
        message_vision("$N降妖杖一伸拦在$n面前，高声叫道：\n"+
                " 死妖怪，现在想跑来不急了,拿命来吧！\n\n",me,who);
        tell_object(who,me->name()+"一把拦住了你！\n");
         return 1;
}

void kill_ob (object ob)
{
  ob->set_temp("qujing_kill",1);
  ::kill_ob(ob);
}
void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
        set("force",2000);
        }
        if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
        command("eat yao");

        else
        {
                command("surrender");
                call_out("exertheal",1,this_object());
        }
        }


        ::heart_beat();
}
varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
  me->command("exert recover");
}

