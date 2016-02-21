//sgzl 

#include <ansi.h>
inherit NPC;
#include "huoyannpc2.h"
 
void create()
{
        set_name("魔礼红", ({ "moli hong", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "男性" );
	set("long",
		"魔家四将之一，使一杆方天画戟，秘授一把伞。名曰：「混元伞。」\n"
                "伞皆明珠穿成，有祖母绿，祖母碧，夜明珠，辟尘珠，辟火珠，辟水\n"
                "珠，消凉珠，九曲珠，定颜珠，定风珠。还有珍珠穿成「装载乾坤」\n"
                "四字，这把伞不敢撑，撑开时天昏地暗，日月无光，转一转乾坤晃动。\n"
	);
	set("age",50);
	set("title", "广目天王");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",1100);
	set("kee",1100);
	set("max_sen",1100);
	set("sen",1100);
	set("combat_exp",2000000);
    set("daoxing",1500000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 80);
	set("mana_factor",80);
	
        set("eff_dx", 450000);
        set("nkgain", 500);

	set_skill("unarmed",150);
	set_skill("yingzhaogong", 200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("spear",200);
	set_skill("bawang-qiang",200);
	set_skill("force",200);
	set_skill("spells", 200);
	set_skill("moshenbu", 200);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "在下广目天王魔礼红，奉圣谕把守东天门。",
		"here" : "这里就是东天门, 入内就是天界了。",
	]) );

	setup();
	carry_object("/d/obj/weapon/spear/huaji")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

void hurting(object me, object ob)
{
   int n;
   
   remove_call_out("hurting");
   
   if(environment(me)!=environment(ob) || !me->is_fighting()) return;
   if(me->is_busy()) {
      call_out("hurting",6+random(5),me,ob);
      return;
   }
   
   message_vision(HIY"$n从怀中抽出混元伞，低声念了几声咒语，混元伞如天罗地网般向$N罩来！\n"NOR,ob,me);
   n = 10 - (int)ob->query("daoxing")/(1 + (int)me->query("daoxing") ) -
      (int)ob->query("combat_exp")/(1+(int)me->query("combat_exp") );
   if(random(n)){
      me->start_busy( 60/ ((int)me->query_kar()+1));
      ob->start_busy(60/((int)ob->query_kar()+1) +1);
      message_vision("结果$N被罩住，顿时行动不得！\n",ob);
   }
   else {
      me->start_busy( 30/ ( (int)me->query_kar()+1) );
      message_vision("$N纵身跃到混元伞顶，闪过了这一击。\n",ob);
   }
   call_out("hurting",6+random(5),me,ob);
}

