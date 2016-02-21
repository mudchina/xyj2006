// feizei.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"飞贼"NOR,({ "fei zei","fei" }) );
	set("title",HIY"飞天遁地"NOR);
        set("gender", "男性" );
        set("age", 33);
        set("long", 
"这是无恶不做的飞贼，背上有一个小小包裹，看样子是才偷了什么东西在手。\n");

  set("age", 34);
  set("str", 50);
  set("cor", 50);
  set("cps", 50);
  set("spi", 30);
  set("per", 30);
  set("con", 50);
  set("int", 30);
  set("kar", 15);
//        set("attitude", "aggressive");
//        set("shen_type", -1);

	set("kee", 5000);
	set("max_kee", 5000);
	set("sen", 5000);
	set("max_sen", 5000);
	set("force", 800);
	set("max_force", 1000);
   set("mana", 8000);
   set("max_mana", 8000);
	set("force_factor", 20);
	set("combat_exp", 500000);
//	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("staff", 100);
	set_skill("literate", 80);
	set_skill("wuxing-quan", 60);
	set_skill("ghost-steps",80);
	set_skill("zhuihun-sword", 90);
	set_skill("zixia-shengong", 80);
//	set_skill("jiuyin-xinjing", 90);
	set_skill("wuxiangforce", 90);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "wuxing-quan");
	map_skill("dodge", "ghost-steps");
	map_skill("parry", "zhuihun-sword");
	map_skill("sword", "zhuihun-sword");
	
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        setup();
        carry_object( __DIR__ "changjian")->wield();
        carry_object( __DIR__ "lingzhi");
	add_money("gold",1);

}
