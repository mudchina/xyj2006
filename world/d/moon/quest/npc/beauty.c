//Cracked by Roath


inherit NPC;

void create()
{

string* name=({"小猫仔","小狗仔","小妖怪","小龙","兔宝宝","小白鼠","小胖猪","小獾","小蚂蚱",
               "小狐狸",});
int r=random(sizeof(name));
  set_name(name[r],({"little elf","goodkid","baobao"}));
  set("age", random(9)+10);

  set("daoxing", 1200000);
  set("combat_exp", 10000);
  set("attitude", "friendly");
  set_weight(1000000000);
  set("per",30);
  if (random(2)) set("gender","女性");
  set("max_kee", 1000);
  set("kee",1000);
  set("sen",2000);
  set("max_sen", 2000);
  set("max_force", 500);
  set("force", 500);
  set("force_factor", 20);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 100);


  set_skill("spells", 180);
  set_skill("dao", 180);
  
  set_skill("dodge", 50);
  set_skill("parry", 50);
  map_skill("spells", "dao");
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
        (: cast_spell, "thunder" :),
        (: cast_spell,"light" :),
        (: cast_spell, "dingshen":),
  }));


    setup();
}
varargs int receive_damage(string type, int damage, object who) {
 return 1;
}
varargs int receive_wound(string type,int damage,object who) {
  return 1;
}
  

int accept_object(object me, object ob)
{
    string unit=ob->query("unit");
    if (!unit) unit="个";
    message_vision("$N给$n一"+unit+ob->name()+"。\n",me,this_object());
    if (ob->move(this_object()))
      call_out("post_accept",1,me,ob);
    return 2;
}

void post_accept(object me,object ob) {

  object who=this_object();

  if (!ob) return;
  if (!me) return;
  if( !ob->query("food_remaining") ) {
     message_vision("$N用毛茸茸的爪子拿起$n看了看，鼻子凑上去嗅了嗅。\n",who,ob);
     message_vision("$N懒洋洋地打了个哈欠，随手把$n扔在了地上。\n\n",who,ob);
     ob->move(environment(me));
  } else {
     message_vision("$N高兴地跳进了$n的怀里，伸出舌头舔了舔$n的脸。\n\n",who,me);
     while (ob && ob->query("food_remaining") && command("eat "+ob->query("id")));
     if (250<=who->query("food")) {
        message_vision("$N心满意足地拍了拍肚皮，钻进草丛里睡觉去了。\n\n",who);
        destruct(who);
     } else message_vision("$N意犹未尽地拍了拍肚子，看着$n馋得直流口水。\n\n",who,me);
   }
   return;
}
