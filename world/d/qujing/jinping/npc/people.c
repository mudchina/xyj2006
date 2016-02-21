// by snowcat  11/22/1997

inherit NPC;

string *names = ({
  "居民",
  "街人",
  "妇人",
  "路人",
  "挑灯夫",
  "送油客",
  "和尚",
  "道士",
});

string *ids = ({
  "ju min",
  "jie ren",
  "fu ren",
  "lu ren",
  "tiaodeng fu",
  "songyou ke",
  "he shang",
  "dao shi",
});

string *genders = ({
  "男性",
  "男性",
  "女性",
  "男性",
  "男性",
  "男性",
  "男性",
  "男性",
});

void create()
{
  string str;
  
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", genders[i]);
  set("combat_exp", 1000+random(1000));
  set("age", 20+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",300);
  set("max_mana",300);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  set("chat_chance", 2);
  set("chat_msg", ({ (: random_move :) }));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  str = "/d/qujing/jinping/obj/denglong34";
  str[strlen(str)-1] = '0'+random(5);  
  carry_object(str);
  
  
}

void init ()
{
    remove_call_out ("initing");

    if(userp(this_player())) {
      call_out ("initing",2+random(60));
    }
}

void initing ()
{
  switch (random(2))
  {
    case 0: 
    {
      command ("wear deng long");
      break;
    }
    case 1:
    {
      command ("remove deng long");
      break;
    }
  }    
}



