
inherit NPC;

void heart_beat() {
       
   if (!query("on_job")) {
     set("eff_kee", query("max_kee"));
     set("eff_sen", query("max_sen"));
     set("kee",query("max_kee"));
     set("sen",query("max_sen"));
     set("mana",query("max_mana"));
     set("force",query("max_force"));
   }
   ::heart_beat();
}

int valid_killer(object killer) {
   object target=query("master")->target();
   object me=this_object();

   if (!target) return 1;

   if (target!=killer && environment(me)==environment(target)) {
     command("sneer");
     command("say 倚多取胜？"+target->query("name")+
        "好大的名头，原来不过如此！还好意思叫什么齐天大圣？！");
     command("bye");
     target->delete_temp("lijing");
     query("master")->go_home();
     return 0;
   }
   return 1;
}

void kill_ob(object ob) {
  object me=this_object();
  object target=query("master")->target();

  if (!target) ::kill_ob(ob);
  if (valid_killer(ob)) ::kill_ob(ob);
}

void unconcious() {die();}
void die() {
   object me=this_object();
   object target=query("master")->target();

   if (!target) {
     ::die();
     return;
   }
   command("over");
   command("drop all");
   message_vision("$N被$n杀得大败，丢盔弃甲，狼狈不堪地逃了回去。\n",me,target);

   me->remove_killer(target);
   me->remove_enemy(target);
   target->remove_killer(me);
   target->remove_enemy(me);
   me->delete("on_job");

   query("master")->lose(me);

}


