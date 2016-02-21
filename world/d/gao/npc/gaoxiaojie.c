// gao.c

inherit NPC;
int leave_here();

void create()
{
       set_name("高小姐", ({"gao xiaojie", "xiaojie", "gao"}));
       set("long","高庄主的女儿，天生丽姿．\n");
       set("gender", "女性");
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("per", 30);
	set("combat_exp", 7400);
        set_skill("unarmed", 10);
	set_skill("dodge", 50);
	set_skill("parry", 20);
	setup();
//       add_money("gold", 1);
        carry_object("/d/gao/obj/pink_cloth")->wear();

set("inquiry", ([
"离开" : (: leave_here :),
"leave" : (: leave_here :),
]) );

}

int leave_here()
{
 object me=this_player();
 object ob=this_object();
 object obp;
 if (me->query_temp("obstacle/yuanwai")==1)
 {
 	say("那就有劳大仙了！\n");
 	say("高小姐转身从小门出去了！\n");
 	me->set_temp("obstacle/gao_asked",1);
	destruct(ob);
 }
 else
 {
 	say("高显然不知道你在说什么！\n");
 }
 return 1;
}
