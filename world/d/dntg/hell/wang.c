#include <ansi.h>

inherit NPC;
string *wang=({"qingguang","songdi","chujiang","chuguan","pingdeng",
              "dushi","taishan","lunzhuan","biancheng","yanluo",
             });
mapping name=(["qingguang":"秦广王","songdi":"宋帝王","chujiang":"楚江王",
  "chuguan":"仵官王","pingdeng":"平等王","dushi":"都市王","taishan":"泰山王",
  "lunzhuan":"轮转王","biancheng":"卞城王","yanluo":"阎罗王" ]);

string get_next(object);

void init() {
  object me=this_object();
  add_action("do_complain","complain");
  add_action("do_kill","kill");

  if (query_temp("target")==this_player()) {
    me->set("eff_kee",1000);
    me->set("kee",1000);
    me->set("sen",1000);
    me->set("eff_sen",1000);
  me->set("daoxing",2000000);
  me->set("combat_exp",2000000);
  me->set("force",2000);
  me->set("max_force",2000);
  me->set("max_mana",2000);
  me->set("mana",4000);
  me->set("force_factor",120);

}
  ::init();
}

int do_complain(string arg) {
  object ob=this_player();
  object me=this_object();
  string complainee=ob->query_temp("dntg_hell/next");
  if (!arg) return notify_fail("你要找谁申诉？\n");
  if (me!=present(arg,environment(me)) ) return 0;
  
  
  message_vision("$N对着$n叫道：“"+RANK_D->query_self_rude(ob)+
    "早已超出三界之外，不在五行之中，已不归阴司管辖，怎么又来勾我？”\n"NOR,ob,me);
  ob->command("bug "+me->query("id"));

  if (!complainee) {
    message_vision("\n$N皱了皱眉头，对$n说道：“你我阴阳殊途，"+
      "我不治你私闯幽冥之罪，也就是了。还不快快退下！”\n\n",me,ob);
    return 1;
  }
  if (name[complainee]!=me->name()) {
    message_vision("\n$N皱了皱眉头，对$n说道：“此事非我经手，"+
      "冤有头，债有主，哪个遣人勾你，你去找哪个吧。”\n\n",me,ob);
    ob->set_temp("dntg_hell/next",get_next(me));
    return 1;
  }
  ob->delete_temp("dntg_hell/ready");  
  message_vision("\n$N恼羞成怒道：“本王叫你三更死，谁敢留你到五更。"+
        "待我亲自送你去见崔判官！”\n",me);
  me->set_temp("target",ob);
  me->kill_ob(ob);
  return 1;
}

string get_next(object me) {
  string who=wang[random(10)];
  while (name[who]==me->query("name"))
     who=wang[random(10)];
  return who;
}

void kill_ob(object ob) {
  object target=query_temp("target");
  if (target!=ob) delete_temp("target");
  ::kill_ob(ob);
}  
void unconcious() {die();}
void die() {
  object me=this_object();
  object ob=me->query_temp("target");
  string next;

  if (!objectp(ob)) {
    ::die();
    return;
  }
  ob->set_temp("dntg_hell/"+me->name(),1);
  message_vision(HIW"\n$N说道：「不打了，不打了，我投降....。」\n\n"NOR,me);
  me->remove_killer(ob);
  me->remove_enemy(ob);
  ob->remove_killer(me);
  ob->remove_enemy(me);
  me->set("kee",(int)me->query("max_kee"));
  me->set("eff_kee",(int)me->query("max_kee"));
  me->set("sen",(int)me->query("max_sen"));
  me->set("eff_sen",(int)me->query("max_sen"));
  me->clear_condition();
  
  me->command("say "+ob->name()+RANK_D->query_respect(ob)+
       "神通广大，小王甘拜下风。");
  next=get_next(me);
  ob->set_temp("dntg_hell/next",next);
  message_vision("$N翻了翻案上的文书，对$n说道：“此事乃"+name[next]+
   "传文至此，要小王勾拿"+RANK_D->query_respect(ob)+"，"+RANK_D->query_respect(ob)
   +"还是去找他理论吧。\n\n",me,ob);

  if (ob->query_temp("dntg_hell/"+name[next]) ) 
      ob->set_temp("dntg_hell/ready",me);      
}

int do_kill(string arg) {
  object me=this_object();
  object ob=this_player();
  string next=ob->query_temp("dntg_hell/next");

   if(!environment(me)) return 0;
  if (me!=present(arg,environment(me))) return 0;
  if (ob->query_temp("dntg_hell/ready")!=me) return 0;
  if (ob->query("dntg/hell")=="done") return 0;
  if (!next) return 0;

   message_vision("$N拍案大叫：“怎么又是"+name[next]+
        "？！你这奸王竟敢耍弄于我！拿命来！”\n\n",ob);

   message_vision("$N吓得魂飞魄散，颤身说：“罢了罢了，依你，都依你。”\n",me);
   message_vision("$N从案上拿出生死簿，提起朱笔，饱蘸浓墨，将$n的名字划去。\n\n",me,ob);

   ob->set("dntg/hell","done");
   me->command("chat "+ob->name()+"这"+RANK_D->query_rude(ob)+
     "逞强行凶，不服拘唤，大闹罗森，强销名号，待我上天禀明玉帝，再来拿你！");
   me->delete_temp("target");
  ob->set("life/no_death_decrease",1);
   ob->delete_temp("dntg_hell");
   
   return 1;
}
