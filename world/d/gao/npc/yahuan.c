// yahuan1.c

inherit NPC;
void create()
{
       set_name("丫环", ({"yahuan"}));

set("long","一个小丫环，正打扫着饭桌．\n还时不时看看衣服，似乎不大高兴．\n");
       set("gender", "女性");
       set("age", 16);
       set("attitude", "friendly");
	set("per", 25);
        set("shen_type", 1);
	set("combat_exp", 500);
set("inquiry", ([
"衣服": "衣服上的扣子找不到了．．．\n",
"剩饭": "吃，吃，吃个没完，羞也不羞！\n",
"剩菜": "吃，吃，吃个没完，羞也不羞！\n",
"food": "吃，吃，吃个没完，羞也不羞！\n",
]) );

	setup();
        carry_object("/d/gao/obj/pink_cloth")->wear();
}
int accept_object(object who,object ob)
{
        object m;
	if (ob->query("id")=="kouzi") {
message_vision("小丫环对$N说：咦，你哪里找到的，真是谢谢你了！\n", who);
message_vision("小丫环从桌上拿了一只烤鸡，递到$N的手中．\n", who);
		command("smile");
		m=new("/d/gao/obj/kaoji");
		m->move(who);
		return(1);
         }
	else return(0);
}
