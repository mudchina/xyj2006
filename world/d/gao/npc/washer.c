// washer.c

inherit NPC;
void create()
{
       set_name("老妈子", ({"laomaz"}));
       set("long","一个老太婆，正生气的洗着一堆衣服．\n");
       set("gender", "女性");
       set("age",68);
       set("attitude", "friendly");
	set("per", 15);
        set("shen_type", 1);
	set("combat_exp", 500);
        set("chat_chance",4);
        set("chat_msg", ({
                "老妈子嘟囔着：该杀的土匪，抢了我家小姐！\n",
		"老妈子低声道：后面有条近道，土匪就是那儿进来的．\n",
}) );

	setup();
}
