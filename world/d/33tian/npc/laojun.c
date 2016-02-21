// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("太上老君", ({"taishang laojun","laojun"}));
       set("long", "红尘一笑牵青牛,世人皆浊我独清.\n");
       set("title", MAG"紫气东来"NOR);
       set("gender", "男性");
       set("age", 100);
   set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       create_family("五庄观", 1, "祖师");
   set("rank_info/respect", "老君");
   set_skill("unarmed", 300);
   set_skill("wuxing-quan", 300);
   set_skill("dodge", 300);
   set_skill("baguazhen", 300);
   set_skill("parry", 300);
   set_skill("sword", 300);
   set_skill("sanqing-jian", 300);
   set_skill("staff", 300);
   set_skill("fumo-zhang", 300);
   set_skill("hammer", 300);
   set_skill("kaishan-chui", 300);
   set_skill("blade", 300);
   set_skill("yange-blade", 300);
   set_skill("force", 300);   
   set_skill("zhenyuan-force", 300);
   set_skill("literate", 300);
   set_skill("spells", 300);
   set_skill("taiyi", 300);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");
   map_skill("blade", "yange-blade");
   map_skill("hammer", "kaishan-chui");

  set("str",100);
  set("per",100);
  set("max_kee", 10000);
  set("max_gin", 10000);
  set("max_sen", 10000);
  set("force", 10000);
  set("max_force", 10000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);
  set("combat_exp", 4000000);
  set("daoxing", 10000000);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
   set("chat_chance_combat", 90);
   set("chat_msg_combat", 
   ({
     (: cast_spell, "zhenhuo" :),
     (: cast_spell, "qiankun" :),
    }) );

setup();

        carry_object("/d/obj/cloth/baguapao")->wear();
//        carry_object("/d/sky/obj/yunxue")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
void init ()
{
  add_action("do_back", "back");
}
int accept_object(object who, object ob)
{
 if((string)ob->query("id") !="baiyu-ling"){
 command("say 你没有玉帝的信物,怎么能给你紫玉葫芦.");
 return 0;
}
else {  
 command("smile");
 command("say 不过这紫玉葫芦非同小可,若在路上被人抢了去,我怎生向玉帝交侍.");
 command("say 除非你胜了我,这才能放心得把它交给你!");
 this_player()->set_temp("laojun_fight", 1);
 return 1;
}
}
int accept_fight(object who)
{
 object me;
 me = this_object();
     if (!who->query_temp("laojun_fight")){
     command("say 修道之人不宜妄动无明!!\n");
         return 0;
   }

 say("太上老君笑道:今日老道就拼了这身老骨头,陪你过几招吧!\n");
  me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));
     who->set_temp("laojun_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}
void player_win(object me, object who)
{
       object hulu;

      hulu=new("/d/33tian/obj/hulu");
      command("sigh");
      say("太上老君叹道:小神仙果然是法力高强,看来我是真的老了!!\n");
      hulu->move(who);
message_vision("太上老君道:这紫玉葫芦今日就交给$N了,路上可得小心了.\n",who);
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);

   command("jump");
   say("太上老君笑道:"+msg+"看来还要再练几年,才有资格拿这紫玉葫芦!\n");
}
void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;
   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

void die()
{

        if( environment() ) {
message("sound", "\n\n太上老君怒道,你这厮怎地这生无礼！\n\n", environment());
message("sound", "\n说罢起身上了青牛,架云朝瑶池而去。。。\n\n", environment());

        }

        destruct(this_object());
}
int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("lingshan/from");

  message_vision("$N请求$n送$N回返。\n",who,me);
  //if (!there)
  //  there = "/d/city/kezhan";
  there = "/d/city/kezhan";

  who->set_temp("accept",0);
  message_vision("$N抬手对$n一拍……\n",me,who);
  who->move(there);
  message_vision("……一团紫气升起，只见$N从里面跳出来。\n",who);
  
  return 1;
}
void attempt_apprentice(object ob)
{
if ( (string)ob->query("family/family_name")=="五庄观") {
if (ob->query("obstacle/number") < 26) {
command("say 这位" + RANK_D->query_respect(ob) + "你还是先出去闯荡一番吧！\n");
command("shrug");
return;
        }
  if (((int)ob->query("daoxing") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，我就收下你了。\n");
command("recruit " + ob->query("id") );
        return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"恕老朽眼拙,这位是.....\n");
        return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "xian");
    ob->set("title", HIW"兜率宫道法真传"NOR);
}
