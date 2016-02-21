
#include <ansi.h>
#include <combat.h>

inherit NPC;
#include <flowers.h>

int DEBUG=1;
string name;
int score;
int query_score() {return score;}

void set_skills(object);
void hurt(object,object);
void reward(object me, object victim, object weapon,int damage);

void create()
{
  name=flowers[random(sizeof(flowers))];
  set_name(name+"仙子", ({ "hua xianzi","xianzi","xian" }) );
  set("long",@LONG
一位品貌秀丽，气质高雅的花仙子，浑身散发出一股异香，
既非冰麝，又非旎檀，似花香而非花香，时刻变换，竟有百
种香气。
LONG);
  set("gender", "女性");
  set("age", 20);
  set("str", 10+random(21));
  set("dex", 10+random(21));
  set("int", 10+random(21));
  set("cor", 10+random(21));
  set("spi", 10+random(21));
  set("con", 10+random(21));  
  set("per", 10+random(21));

  set("combat_exp", 10000);
  set("daoxing", 10000);

  set_skill("unarmed", 80);
  set_skill("baihua-zhang",180);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("moondance",80);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("moonshentong",180);
  map_skill("spells","moonshentong");
  map_skill("dodge","moondance");
  map_skill("unarmed","baihua-zhang");
  set("max_kee", 1000);
  set("max_sen", 1000);
        set("chat_msg_combat", ({
                (: cast_spell, "shiyue" :),
        }) );
  set("mana", 4000);
  set("max_mana", 4000);
  set("mana_factor", 100);
  set("force", 2000);
  set("max_force", 1000);
  set("inquiry",([
    "花" : "你陪我打架玩(fight)，把我哄高兴了，自然有你的好处。\n",
    "仙花" : "你陪我打架玩(fight)，把我哄高兴了，自然有你的好处。\n",
    "flower" : "你陪我打架玩(fight)，把我哄高兴了，自然有你的好处。\n",
    "hua" : "你陪我打架玩(fight)，把我哄高兴了，自然有你的好处。\n",
  ]));
  setup();
  if (clonep())  carry_object("/obj/loginload/skirt")->wear();
  if (clonep())  carry_object("/obj/loginload/shoes")->wear();

}
void unconcious() { die(); }
void die() {
  command("drop all");
  message_vision(MAG"$N"+MAG"化作一缕幽香，消失在红尘之中。\n"NOR,this_object());
  destruct(this_object());
}
int accept_object(object me, object ob) {
  object weapon=query_temp("weapon");
  string msg="$N";
  return 1; // reduce reward
  if (!mapp(ob->query("weapon_prop"))) return 0;
  message_vision("$N给$n一"+ob->query("unit")+ob->query("name")+"。\n",me,this_object());
  command("nod");
  if (weapon) {
     msg+="放下"+weapon->query("name")+"，";
     destruct(weapon);
  }
  msg+="装备"+ob->query("name")+"。\n";
  ob->move(this_object());
  ob->wield();
  message_vision(msg,this_object());
  return 2;
}  

void equip() {
  object weapon,me=this_object();
  string msg;

  switch (random(6)) {
    case 0: weapon=new("/d/obj/weapon/hammer/baiyuban");msg="$N从怀中掏出了一面白玉板。\n";break; 
    case 1: weapon=new("/d/obj/weapon/mace/bamboo");msg="$N顺手从身旁的竹林中折下一段短竹。\n";break; 
    case 2: weapon=new("/d/obj/weapon/staff/shugan");msg="$N在地上拣起一根树干。\n";break; 
    case 3: weapon=new("/d/obj/weapon/stick/shuzhi");msg="$N随手从身边的小树上折下一根树枝。\n";break; 
    case 4: weapon=new("/d/obj/weapon/sword/guishuzhi");msg="$N小心翼翼地从桂花树上摘下一段树枝。\n";break; 
    case 5: weapon=new("/d/obj/weapon/whip/wuchou");msg="$N从怀里摸出一条五彩缤纷的绸带。\n";break; 
    default: weapon=new("/d/obj/weapon/");msg="$N\n";break; 
  }
  if (weapon->move(me))
     message_vision(msg,me);
  weapon->wield();
}

int accept_fight(object me)
{
  object ob=this_object(),target=query("target");

  if (me!=target) {
     message_vision("$N瞟了$n一眼，不屑地说：“你这人气质太差，我不和你玩。”\n",ob,me);
     return 0;
  }
  if (is_fighting()) 
    return ::accept_fight(me);
  message_vision("$N对着$n嫣然一笑，说道：“你出手可别太重了。如果打累了，可以随时叫停(stop)。”\n",ob,me);
  set_skills(me);
  set("mode","fighting");
  score=0;
  add_action("do_stop","stop");
  kill_ob(me);
  set("starting_kee",me->query("kee"));
  return 1;
}

void heart_beat() {
  object me=this_object(),target=query("target");

  if (!target || environment(target)!=environment(me) ||
      !living(target)) {
    message_vision("$N幽幽地叹了口气，转身走了。\n",me);
    destruct(me);
    return;
  }
  if (is_fighting() && !query_temp("weapon")) equip();

  ::heart_beat();
}

void set_skills(object me) {
  mapping skill=me->query_skills();
  int max_value=10;
  string *skillnames=keys(skill);
  for (int i=0;i<sizeof(skillnames);i++) 
     if(skill[skillnames[i]]>max_value)
        max_value=skill[skillnames[i]];
  
  set("max_force",me->query("max_force"));
  set("daoxing",me->query("daoxing"));
  set("combat_exp",me->query("combat_exp"));
  set("force",query("max_force"));
  set_skill("unarmed",max_value);
  set_skill("baihua-zhang",max_value);
  set_skill("parry", random(max_value));
  set_skill("dodge",random(max_value)/3);
  set_skill("moondance",random(max_value)/3);
  map_skill("dodge","moondance");
  set_skill("axe",random(max_value));
  set_skill("blade",random(max_value));
  set_skill("dagger",random(max_value));
  set_skill("fork",random(max_value));
  set_skill("hammer",random(max_value));
  set_skill("mace",random(max_value));
  set_skill("rake",random(max_value));
  set_skill("spear",random(max_value));
  set_skill("staff",random(max_value));
  set_skill("stick",random(max_value));
  set_skill("sword",random(max_value));
  set_skill("whip",random(max_value));
}

varargs int receive_damage(string type, int damage, object who) {
  
  score-=damage;
  if (type!="kee" || who!=query("target")) 
     return ::receive_damage(type,damage,who);
   call_out("hurt",1,this_object(),who);
  return ::receive_damage(type,damage,who);
}
void hurt(object ob,object me) {
  if (DEBUG && me->query("id")=="xlb" && me->query("name")=="小萝卜") return;
  if (!ob || !me) return;
  if (!random(10)) {
    ob->command("surrender");
    ob->command("say 玩玩而已，干嘛下手这么重？算你厉害行不行？不和你打了！");
    message_vision("$N狠狠地白了$n一眼，一转身，径自走了。\n\n",ob,me);
    remove_call_out("hurt");
    destruct(ob);
    return;
  }
  switch (random(6)) {
    case 0: ob->command("pain");break;
    case 1: ob->command("pain "+me->query("id"));break;
    case 2: ob->command("angry");break;
    case 3: ob->command("kick");break;
    case 4: ob->command("slogan "+me->query("id"));break;  
    case 5: ob->command("sign2");break;
  }
} 

void reset_action() {
  object me=this_object();
  mapping action;
  mapping new_act=([]);

  ::reset_action();
  if (!action=query("actions")) return;
  new_act=copy(action);
  if (new_act["post_action"]) 
    new_act["post_action"]= (: reward :);
  else new_act+=(["post_action" : (: reward :) ]);
  set("actions",new_act);
}

void reward(object me, object victim, object weapon,int damage) {
  int ammount=0;
  if (damage<=0) return;
  if (victim!=query("target")) return;
  score+=damage;
  victim->delete_temp("no_move");
}
int do_stop() {
  object me=this_object(),target=this_player();
  object flower;

  if (target!=query("target")) return 0;
  if (!target->is_fighting(me)) 
    return notify_fail("你们没在打架。\n");

  message_vision("$N跳出圈外，说道：“今天就玩到这里吧。”\n",target);
  me->remove_killer(target);
  target->remove_killer(me);
  me->remove_enemy(target);
  target->remove_enemy(me);
  command("ok");
  command("say 谢谢你陪我玩，我有朵仙花，你喜欢的话就送给你吧。");

  flower=new(__DIR__"obj/hua");
  flower->set("name",name);
  if (score>10000) score=10000; //add by beeby
  flower->set("score",random(score));
  flower->set("target",target);
  if (flower->move(target)) {
     message_vision("$N送$n一朵"+name+"。\n",me,target);
     command("smile");
   } else {
      target->command("norose");
      me->command(":P");
   }
   message_vision("$N说了声“后会有期”，飘然而去。\n",me);
   destruct(me);    
   return 1;
}
  
