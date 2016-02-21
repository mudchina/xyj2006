inherit NPC;

string *names = ({
  "火龙",
  "火马",
  "火鸦",
  "火鼠",
});


void create()
{
        set_name(names[random(sizeof(names))], ({"huo bing", "bing"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "天宫火部战将，久精沙场。\n");
        set("class", "xian");
        set("combat_exp", 35000);
        set("daoxing", 1500000);

        set("attitude", "aggressive");
        set_skill("unarmed", 80);
        set_skill("yingzhaogong", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spear", 80);
        set_skill("huoyun-qiang", 80);
        set_skill("spells", 100);
        set_skill("taiyi", 100);
        set_skill("moshenbu", 80);
        set_skill("force", 80);   
        set_skill("huomoforce", 80);
        map_skill("force", "huomoforce");
        map_skill("spear", "huoyun-qiang");
        map_skill("dodge", "moshenbu");
        map_skill("unarmed", "yingzhaogong");
        map_skill("spells", "taiyi");

        set("max_kee", 800);
        set("max_sen", 800);
        set("mana", 2000);
        set("max_mana", 2000);
        set("mana_factor", 50);
        set("force", 800);
	 set("max_force", 800);
        set("force_factor", 5);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
          (: cast_spell, "zhenhuo" :),
           }) );

        setup();
        carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/qujing/pingding/obj/weapon11")->wield();
}

void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


void die ()
{


  object me = this_object();
  object ob = query_temp("my_killer");
  ob->add_temp("dntg/laojunlu_day",1);
  message_vision ("$N消失在火光之中。\n",me);
  destruct (this_object());
  return ;
}
