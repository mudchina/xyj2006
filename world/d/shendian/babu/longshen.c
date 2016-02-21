// repoo
#include <ansi.h>
inherit NPC;
string ask_tianshen();
void create()
{
     set_name(HIR"龙神"NOR, ({ "long shen", "long", "dragon" }) );
        set("gender", "男性" );
     set("long",HIB
              "八部天龙\n"NOR);
 
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
      set("daoxing",4500000);
        set("force",5000);
        set("max_force",3000);
        set("mana",5000);
        set("max_mana",3000);
   set("force_factor",150);
        set("mana_factor",120);
        set("eff_dx", 4500000);
        set("nkgain", 1500);
        set_skill("unarmed",250);
        set_skill("dragonfight", 250);
         set_skill("parry",250);
        set_skill("dodge",250);
            set_skill("dragonstep",230);
        set_skill("fork",250);
        set_skill("fengbo-cha",180);
        set_skill("force",250);
            set_skill("dragonforce",220);
        set_skill("spells", 250);
        set_skill("seashentong", 250);
            map_skill("force","dragonforce");
              map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("parry", "fengbo-cha");
        map_skill("fork","fengbo-cha");
        map_skill("unarmed", "dragonfight");
        set("inquiry", ([
             "name" : "在下沙竭罗龙王,乃八部天龙龙神。",
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                        ]) );
    set("chat_chance_combat", 80);
             set("chat_msg_combat", ({
       //         (: perform_action,"unarmed","sheshen" :),
            (: cast_spell, "dragonfire" :),   
       }) );
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
   if ((arg == "qiankun") || (arg == "qiankun on long shen") || (arg == "qiankun on long") || (arg == "qiankun on dragon"))
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
  call_out ("xue",8+random(8),me,ob);  
  ::kill_ob(ob);
}
void xue (object me, object ob)
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
  message_vision ("$N"HIW"张开大嘴，低声念了几声咒语，顿时风起云涌，一片冰雪向$n罩来！\n"NOR,me,ob);
  if ( ((int)ob->query_skill("dodge", 1)+ random(100)) > 240 )
     message_vision (HIC"$N纵身跃到半空中，闪过了这一击。\n"NOR,ob);
 else 
    {
     message_vision (HIW"结果$N被冻住不能行动！\n"NOR,ob,me);
     ob->start_busy(3+random(5));
    } 
  remove_call_out ("xue");  
  call_out ("xue",random(10)+10,me,ob);  
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object yi;
  string longyi_given;
  longyi_given = "/d/shendian/babu/obj/longyi.c";
  if(!ob)
{
  message_vision ("$N"HIY"化作一股清风......\n"NOR,me);
  destruct (this_object());
  return ;

}

  ob->set_temp("babu/longshen","done");
   if (!longyi_given->in_mud())
         {
   yi = new("/d/shendian/babu/obj/longyi");
  yi->move(ob);
   message_vision ("$N"HIY"惊慌逃窜，连翅膀都忘记带走....\n"+HIM"一对翅膀掉在了$n身上。\n"NOR,me,ob);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+ob->query("name")+"拿到"+HIY"龙神"+HIB"之翼"NOR+YEL"了！\n\n"+NOR,users() );
  destruct (this_object());
  return ;
       }
    else
       {
  message_vision ("$N"HIY"化作一股清风......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/longshen") == "done")
                return "别杀我，别杀我！\n";

  command("say 你想知道众神之殿在哪里？\n");
   command("say 这容易，杀了我吧！\n");
   kill_ob(me);
  return "叫你知道本神的厉害！\n";
}
