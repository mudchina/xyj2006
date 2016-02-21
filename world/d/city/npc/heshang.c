// bonze.c 和尚?
// By Dream Dec. 20, 1996

inherit NPC;

int test_player (object me);
void create()
{
            set_name("不知和尚", ({ "buzhi heshang" , "heshang", "bonze" }));
	set("gender", "男性");
          set("age", 100);
	set("attitude", "peaceful");
	set("class", "bonze");
          set("max_kee", 2000);
            set("per", 30);
          set("max_gin", 2000);
          set("max_sen", 2000);
          set("force", 2400);
          set("max_force", 2400);
          set("force_factor", 120);
          set("max_mana", 2400);
          set("mana", 2400);
          set("mana_factor", 100);
          set("combat_exp", 1000000);
          set("daoxing", 2000000);
          set_skill("literate", 100);
          set_skill("spells", 160);
          set_skill("buddhism", 160);
          set_skill("dodge", 160);
          set_skill("lotusmove", 160);
          set_skill("parry", 160);
          set_skill("unarmed", 160);
          set_skill("jienan-zhi", 160);
          set_skill("force", 160);
          set_skill("lotusforce", 160);
          set_skill("staff", 160);
          set_skill("lunhui-zhang", 160);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
         set("inquiry", ([
                "袈裟" : "袈裟是我佛无价之宝,只鱼有缘人,货买3000两\n",
                "这么贵" : "有缘人分文不取！\n",
                "不要钱"     : "只要你肯去我佛如来处,取拿三藏经书普渡众生\n",
//           "取经"     : (: test_player :),
 			]));
      set("chat_chance_combat", 80);
      set("chat_msg_combat", ({
              (: cast_spell, "bighammer" :),
      }) );

	set("chat_chance", 5);
	set("chat_msg", ({
            "不知和尚摇头晃脑地说：佛度有缘人。\n",       
            "不知和尚摇头晃脑地说：我佛慈悲。\n",       
            "不知和尚摇头晃脑地说：南无阿弥陀佛。\n",       
		
	}) );
        
	
	setup();
	carry_object("/d/nanhai/obj/sengpao")->wear();
          carry_object("/d/obj/weapon/staff/budd_staff")->wield();
}



int test_player (object me)
{
//object jiasha = new ("/d/obj/cloth/jiasha2");
  object who = this_player();
  me->command_function("nod");
  carry_object("/d/obj/cloth/jiasha2");
       command("give jia sha to " + who->query("id"));

//jiasha->move(who);
  return 1;
}
