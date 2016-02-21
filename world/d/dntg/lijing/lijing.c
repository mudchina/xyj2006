
#include <ansi.h>

inherit NPC;

object bing1() {return query("bing1");}
object bing2() {return query("bing2");}
object juling() {return query("juling");}
object nezha() {return query("nezha");}
object target() {return query("target");}

int do_jifabao() {
   return command("ji fabao on "+target()->query("id"));
}

int die() {return 1;}
int unconcious() {return 1;}
int valid_killer(object);
void time_up();
void go_home();
 
void call_juling();
void call_nezha();
void retreat();

void create()
{
    
        set_name("李靖", ({ "li jing","li", "jing" }) );
        set("gender", "男性" );
        set("long", "托塔李天王乃是天界元帅，麾下十万天兵天将，法力无边。\n");
        set("age",40);
        set("title", "托塔天王");
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("spi", 30);
        set("per", 30);
        set("class", "xian");
        set("attitude", "friendly");
        set("combat_exp", 2000000);
  set("daoxing", 2000000);

        set("max_kee", 1800);
        set("max_sen", 1800);
        set("force",3000);
        set("max_force",2000);
        set("force_factor", 100);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 0);

        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("changquan", 200);
        set_skill("liangyi-sword", 200);
        set_skill("baguazhou", 200);
        set_skill("moshenbu", 200);
        set_skill("lengquan-force", 200);
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("sword", "liangyi-sword");
        map_skill("parry", "liangyi-sword");
        map_skill("dodge", "moshenbu");
        setup();
        carry_object("/d/obj/fabao/huangjin-baota");
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/sky/obj/zhanyaojian")->wield();

    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
     (: do_jifabao :),
  }) );

        call_out("time_up",1800);        
}
 
void time_up() {
   if (target()) {
     command("say "+target()->name()+"果然有些神通！");
     command("say 今日不分胜负，明日再战！");
     target()->delete_temp("lijing");
   }
   go_home();
}

void heart_beat() {
   object target=target();
       
   set("eff_kee", 2000);
   set("eff_sen", 2000);
   set("kee",2000);
   set("sen",2000);
   set("force",4000);
   set("mana",4000);
   
   if (target && target->is_ghost()) {
      message_vision(HIY"$N哈哈大笑：“如此手段，也敢妄称大圣？”\n"NOR,this_object());
      command("kick corpse");
      go_home();
      return;
   }
   if (!target || environment(this_object())!=environment(target)) {
       message_vision(HIY"$N哈哈大笑：“无胆匪类，逃之夭夭了。”\n"NOR,this_object());
       go_home();
       return;
   }
   ::heart_beat();
}

int valid_killer(object killer) {
   object target=target();
   object me=this_object();

   if (target!=killer && environment(me)==environment(target)) {
     command("sneer");
     command("say 倚多取胜？"+target->query("name")+
        "好大的名头，原来不过如此！还好意思叫什么齐天大圣？！");
     command("bye");
     target->delete_temp("lijing");
     go_home();
     return 0;
   }
   return 1;
}

void kill_ob(object ob) {
  object me=this_object();
  object target=me->query("target");

  if (!target) ::kill_ob(ob);
  if (valid_killer(ob)) ::kill_ob(ob);
}
        
void go_home() {
   object me=this_object();

   message_vision(HIY"$N手一挥，带着手下敲锣打鼓班师回朝。\n"NOR,me);          
   if (environment())  environment()->delete("host");
   remove_call_out("call_juling");
   remove_call_out("call_nezha");
   remove_call_out("retreat");

   destruct(bing1());
   destruct(bing2());
   destruct(juling());
   destruct(nezha());
   destruct(me);
}

void start() {
  object me=this_object();
  object target=target();
  object bing1=new(__DIR__"tianbing");
  object bing2=new(__DIR__"tianbing");
  object nezha=new(__DIR__"nezha");
  object juling=new(__DIR__"juling");

  set("bing1",bing1);
  set("bing2",bing2);
  set("nezha",nezha);
  nezha->set("master",me);
  set("juling",juling);
  juling->set("master",me);
  bing1->move(environment(me));
  bing2->move(environment(me));
  nezha->move(environment(me));
  juling->move(environment(me));

  message_vision(HIY"突然间狂风大做，飞沙走石，吹得你几乎睁不开眼。\n"NOR,me);
  message_vision(HIY"只见远处飘来一大团乌云，遮天蔽日，大有山雨欲来风满楼之势。\n"NOR,me);
  message_vision(HIY"须臾，鼓声震天，乌云中现出天兵天将，为首之人正是托塔天王李靖！\n"NOR,me);
  message_vision(HIY"李天王左有先锋巨灵神，右有哪吒三太子，威风凛凛，不可一世。\n"NOR,me);
  call_out("call_juling",5);
  
}

void call_juling() {
  object me=this_object();
  object juling=me->juling();
  object target=me->target();

  if (!target || !juling) return;
  
  tell_object(target,"李靖正盯着你看，不知道打些什么主意。\n\n");
  message_vision(HIY"$N朗声道：“奉旨捉拿反贼。"+target->query("name")+
         "，还不速降，免伤性命！\n"NOR,me);
  message_vision(HIY"$N手一挥，先锋官巨灵神率兵向$n杀来。\n\n"NOR,me,target);
  message_vision(HIY"$N冷笑三声道：“"+RANK_D->query_rude(target)+
    "，这等不知人事，辄敢无状，你就要做齐天大圣！好好的吃吾一斧！”\n"NOR,juling());

  juling->kill_ob(target);
  juling->set("on_job",1);
  bing1()->kill_ob(target);
  bing2()->kill_ob(target);
}

void lose(object loser) {
  object me=this_object();

  command("kick "+loser->query("id"));
  if (loser==juling()) call_out("call_nezha",5);
  if (loser==nezha()) call_out("retreat",5);
}

void call_nezha() {

  message_vision(HIY"$N令旗一挥，身后杀出哪吒三太子，手执火尖枪，杀气腾腾地向$n冲来。\n"NOR,this_object(),target());
  nezha()->kill_ob(target());
  nezha()->set("on_job",1);

}

void retreat() {
  object announcer=new(__DIR__"announcer");
  command("hmm");
  command("sigh");
  command("say 既然如此，不必与他相持，且去上界，多遣天兵，围捉这厮，未为迟也。");


  announcer->announce(target(),environment());
  go_home();
}



