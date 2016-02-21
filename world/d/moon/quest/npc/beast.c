//Cracked by Roath


inherit NPC;

void create()
{

string* name=({"貔貅","鳖齿","九婴","大风","巴蛇","封蹊"});
string* desc=({"人面马足，龙头虎爪，身如巨牛，遍体通红。\n",
               "兽头人身的怪物，嘴里长着一支长五六尺的锋利牙齿。\n",
               "长着九只脑袋的怪兽，嚎叫起来有如婴儿啼哭。\n",
               "大风恶鸟，性情凶悍，以人畜为食，风过之处，伐树倒屋，伤人无数。\n",
               "一条巨蟒，青头乌身，身长百丈，张开大口，可以吞象。\n",
               "一头硕大无比的野猪，生得毛长爪利，力大无穷。\n"});
int r=random(6);
  set_name(name[r],({"monster"}));
  set("long",desc[r]);
  set("age", random(900)+100);

  set("daoxing", 1200000);
  set("combat_exp", 10000);
  set("attitude", "friendly");
  set_weight(1000000000);
  set("per",9);
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
  }));


    setup();
}
varargs int receive_damage(string type, int damage, object who) {
  if (type=="kee") return 1;
  return ::receive_damage(type,damage,who);
}
varargs int receive_wound(string type,int damage,object who) {
  if (type=="kee") return 1;
  return ::receive_damage(type,damage,who);
}
  



