//lestat,2001
#include <ansi.h>
inherit NPC;

string *names = ({
  "玉石琵琶精",
  "九头雉鸡精",
  "黑山老妖",
  "九尾狐狸精",
  "火灵圣母",
  "龟灵圣母",
  "石矶娘娘",
});
void create()
{
   string str;
   set_name(HIB+names[random(sizeof(names))]+NOR, ({"lao yao", "lao", "yao"}));
   set("long", "深山修炼多年得道的妖精。\n");
//   set("title", HIR"食人兽"NOR);
   set("race", "野兽");
   set("age", 100+random(201));
   set("combat_exp", 5000000+random(500001));
   set("daoxing", 5000000+random(500001));
   set("limbs", ({ "头部", "身体", "前爪", "尾巴", "肚皮", "后爪"}) );
   set("verbs", ({ "bite", "claw"}) );
   set("attitude", "aggressive");
   set("per", 10);
   set("bdt", 1);
   set("max_kee", 6000);
   set("kee", 6000);
   set("sen", 6000);
   set("max_sen", 6000);
   set("force", 2000);
   set("mana", 8000);
   set("max_mana", 8000);
   set("max_force", 2000);
   set("force_factor", 75);
   set("mana_factor", 75);
   set_skill("parry", 200);
   set_skill("unarmed", 200);
   set_skill("dodge", 200);
   set_skill("blade", 200);
   set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
   add_temp("apply/damage", 50);
   setup();
   carry_object("/d/obj/cloth/shoupiqun")->wear();
   carry_object("/d/qujing/jilei/obj/armor")->wear();
   carry_object( __DIR__ "lingzhi");
   	add_money("silver", random(50));

}
/*
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		 name() + "说道：我先去把大唐皇帝杀了！\n\n"
		+ name() + "念念口诀，一阵狂风不见了。\n" , environment(),
		this_object() );
	destruct(this_object());
}*/
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$N大叫一声,天绝我也!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if(!me) { destruct(ob); return; }
        else{
        if((int)me->query("combat_exp") < 10000000)   {//有点问题
        message("vision", me->name() + "杀死食人妖怪,修为又有所增长。\n", me);
        me->add("combat_exp",1000);
        me->add("potential",1000);
        destruct(ob);
        }
        message("vision", me->name() + "修为增加了。\n", me);
//        me->add("score",2);
//        me->add("shen",10);
        destruct(ob);
        return;
             }
}

