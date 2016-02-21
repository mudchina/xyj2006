//Cracked by Roath
// created by snowcat on 12/9/1997

inherit NPC;

void do_kill(object obs);

string *names1 = ({
  "獭",
  "鹿",
  "獾",
  "狗",
  "猪",
  "猴",
  "狒",
  "蟒",
});

string *names2 = ({
  "头",
  "尾",
  "脚",
  "爪",
  "嘴",
  "牙",
});

string *names3 = ({
  "虎",
  "狮",
  "豹",
  "熊",
  "罴",
  "狼",
  "狈",
  "豺",
});

int eff_dx;
int already_setup=0;

int random_action();
void set_data();

void create()
{

  string str;
  str = names1[random(sizeof(names1))]+names2[random(sizeof(names2))]+names3[random(sizeof(names3))];
  set_name(str, ({"yao mo", "yao", "mo"}));
  set("gender", "男性");
  set("attitude", "aggressive");
  set("chat_chance", 10);
  set("chat_msg", ({
      (: random_action :)
   }));

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  already_setup=0;
}

void init()
{
    if(!already_setup)
	set_data();
    ::init();
    if(this_player()) do_kill(this_player());
}

void set_data()
{
  string long;
  int i,k,m;
  int j, dx, year;
  object env=environment(this_object());

  if(!env) return;
  year=env->query_year();
  if(!year) return;
  
  already_setup=1;
  k=year/2;
  m=11*year/10;
  i=k+random((m-k)/10+1)*10;
  if(i>20000) i=20000;

  set("age", i*2);
  dx=1000*i;
  set("combat_exp", dx);
  set("daoxing", dx);
  
  for(j=7;j<60;j=j+4)
      if(j*j*j/10>i) break;

  //j=j*5; // skills is half of the full levels exp permits.
  //j=j*15; // skills is 150% of the full levels exp permits.
  j=j*10; // skills is 100% of the full levels exp permits.

  set("per", 10+random(30));
  set_skill("parry", j);
  set_skill("unarmed", j);
  set_skill("dodge", j);
  set_skill("blade", j);
  set_skill("fork", j);
  set_skill("mace", j);
  set_skill("spear", j);
  set_skill("sword", j);
  set_skill("whip", j);
  set_skill("axe", j);
  set_skill("hammer", j);
  set_skill("rake", j);
  set_skill("stick", j);
  set_skill("staff", j);
  set_skill("dagger", j);
  
  j=j/2+1;
  //j=j/3+1;
  set("force_factor",j/2);
  set("mana_factor",j);
  //j=j*5;
  j=j*10;
  set("max_sen",j);
  set("max_kee",j);
  set("max_gin",j);
  set("eff_sen",j);
  set("eff_kee",j);
  set("eff_gin",j);
  set("force",4*j);
  set("max_force",2*j);
  set("mana",4*j);
  set("max_mana",2*j);
  j=j/2;
  set("sen",j);
  set("kee",j);
  set("gin",j);

  // mon 9/25/98
  j=(random(2)==0)?1:-1;
  eff_dx=dx*j;
  set("eff_dx",eff_dx);
  set("nkgain",600);
  long="一头"+name()+"，修练了有"+
      chinese_number((dx/1000/10)*10)+
      "多年道行。它";
  if(j==1) {
      set("long",long+"通体透出一丝仙气。\n");
  } else {
      set("long",long+"混身上下妖气逼人。\n");
  }
  if(random(10)<3) set("env/wimpy",30);

}

void do_kill(object obs)
{
    int exp;
    if(!obs || !userp(obs)) return;

    exp=(obs->query("combat_exp")
        +obs->query("daoxing"))/2;

    if (eff_dx>exp) {
	kill_ob(obs);
	if(!random(5))
	    set_leader(obs);
	else if(!random(5))
	    set_leader(0);
    }
}

int random_action()
{
  object env = environment(this_object());
  object *obs;
  int i;

  if (! is_fighting() &&
      living(this_object()) &&
      env) {
    random_move();
    env = environment(this_object()); // notice: new env
    obs = all_inventory(env);
    i = sizeof(obs);
    while (i--) {
	do_kill(obs[i]);
    }
  }
  return 0;
}

// this function is called by combat_d after NK.
// mon 12/24/99
int nk_reward(object killer, int reward)
{
   string str, msg;

   if(!reward) return 0;
   if(!killer || !userp(killer)) return 0;

   str=COMBAT_D->chinese_daoxing(reward); 
   tell_object(killer,"\n你得到了"+str+"道行！\n");
   killer->add("kill/nkgain",reward);
   killer->add("daoxing",reward);

   msg=sprintf("%s(%d)杀死了%s(%d)，得到%d点道行。",
      killer->query("id"),(killer->query("daoxing")+
      killer->query("combat_exp"))/2,
      this_object()->query("id"),(this_object()->query("daoxing")+
      this_object()->query("combat_exp"))/2,reward);
   log_file("npc_kill","["+ctime(time())+"] "+msg+"\n");

   killer->add_temp("ymdh/yaomokilled",1);
   __DIR__"ye.c"->announce(killer->query("name")+
	   "打死了"+this_object()->query("name")+
	   "，得到"+str+"道行！\n");
	   
   return 1;
}
