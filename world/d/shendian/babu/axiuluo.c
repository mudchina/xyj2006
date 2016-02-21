// repoo
#include <ansi.h>
inherit NPC;
string ask_tianshen();
 
void create()
{
          set_name(HIR"阿修罗"NOR, ({ "axiu luo", "luo" }) );
        set("gender", "男性" );
         set("long",HIB
                "八部天龙阿修罗\n"NOR);
 
        set("age",50);
         set("title", HIB"八部天龙"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",4100);
       set("kee",4100);
        set("max_sen",3100);
        set("sen",3100);
         set("combat_exp",3000000);
         set("daoxing",4000000);
        set("force",5000);
        set("max_force",3000);
        set("mana",5000);
        set("max_mana",3000);
        set("force_factor", 150);
        set("mana_factor",120);
        set("eff_dx", 4500000);
        set("nkgain", 1500);
       set_skill("unarmed",250);
        set_skill("dragonfight", 250);
        set_skill("parry",180);
        set_skill("dodge",180);
              set_skill("dragonstep",180);
        set_skill("fork",180);
        set_skill("fengbo-cha",180);
        set_skill("force",180);
              set_skill("dragonforce",200);
        set_skill("spells", 180);
        set_skill("seashentong", 180);
              map_skill("force","dragonforce");
              map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("parry", "fengbo-cha");
        map_skill("fork","fengbo-cha");
        map_skill("unarmed", "dragonfight");
        set("inquiry", ([
                "name" : "在下阿修罗，乃八部天龙。",
                        ]) );
        set("chat_chance_combat", 50);
              set("chat_msg_combat", ({
                (: perform_action,"unarmed","sheshen" :),
       //         (: cast_spell, "dragonfire" :),                
        }) );
        set("inquiry", ([
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                ]) );
              setup();
        carry_object("/d/sea/obj/longpao")->wear();
   //     carry_object("/d/obj/weapon/hammer/jingua")->wield();
}
void init()
{
        ::init();
        add_action("do_cast", "cast");
}
int do_cast (string arg)
{
  object who = this_player();
   if ((arg == "qiankun") || (arg == "qiankun on luo") || (arg == "qiankun on axiu luo"))
  {
      tell_object(who,"少来这一套！\n");
      return 1;
     }
  else return 0;
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  call_out ("huo",5+random(5),me,ob);  
  ::kill_ob(ob);
}
void huo (object me, object ob)
{
  object huobing;
  int damage;
  if (! me)
    return;
  if( !living(me) )
    return;
  if (! ob)
    return;
  if (environment(ob) != environment(me))
    return;
  message_vision ("$N"HIC"从口中吐出"HIR"三"HIB"味"HIM"真气 "HIC"祭在空中，化作一道"HIW"火墙"
       HIR+"只觉热浪滚滚，向$n扑来！\n"NOR,me,ob);
  if ( (ob->query("force")+random(1000)) > 4000 )
     message_vision (HIY"$N大喝一声：去！\n"
       +HIR"这道火墙"+HIY" 霎时烟消云散。\n"NOR,ob,me);
  else 
    {
     message_vision (HIR"结果$N被火墙完全吞没了！\n"NOR,ob,me);
     damage=(me->query("force"))/2; 
     if ( ob->query("kee") < damage ) ob->unconcious();
     else ob->add("kee",-damage);
    } 
  remove_call_out ("huo");  
  call_out ("huo",random(10)+9,me,ob);  
}
void die ()
{
    object me = this_object();
   object ob = query_temp("my_killer");
  object zhua;
  string zhua_given;
   zhua_given = "/d/shendian/babu/obj/longzhua.c";
    ob->set_temp("babu/axiuluo","done");
   if (!zhua_given->in_mud())
    {
   zhua = new("/d/shendian/babu/obj/longzhua");
  zhua->move(ob);
 message_vision ("\n$N"HIY"刚想逃走，$n从怀中掏出一把马刀，手起刀落，剁下了它的手....\n\n"NOR,me,ob);
message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+ob->query("name")+"拿到"+HIB"修罗"+HIR"之爪"NOR+YEL"了！\n\n"+NOR,users() );
  destruct (this_object());
  return ;
  }
else
  {
  message_vision ("$N"HIY"消失在火光中......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/axiuluo") == "done")
                return "别杀我，别杀我！\n";

  command("say 你想知道众神之殿在哪里？\n");
   command("say 这容易，杀了我吧！\n");
   kill_ob(me);
  return "叫你知道本神的厉害！\n";
}
int accept_object(object me, object ob)
{
  string myname=RANK_D->query_rude(me), thing=(string)ob->query("id");
   if (me->query_temp("babu/mohuluojia") == "begin")
   {
     if (ob->query("id") != "xiuluo mixin")
    {
      command ("say 这是什么破烂？");
      call_out("dropthing", 1, thing);
      return 1;
    }
  else
    {
      command ("nod");
      command ("say "+myname+"干的不错！");
      me->set_temp("mohuluojia/mixin","done");
     me->set_temp("mohuluojia/mixin","done");
      call_out("destroy", 1, ob);
      return 1;
    }
  }
  else
  {
  command ("say 你给我东西干吗？");
  }
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
void dropthing(string thing)
{
  command("drop "+thing);
  return;
}
