#include <ansi.h>

inherit NPC;

void create()
{
        set_name("香玉", ({ "ban niang","niang", "girl"}) );
        set("gender", "女性");
        set("age", 18);
	set("per", 20+random(5));
	set("title", "小伴娘");
        set("long","一个漂亮的小伴娘。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        setup();
        carry_object("/d/obj/cloth/xiuhuaxie")->wear();
	carry_object("/d/obj/cloth/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
		"香玉轻拨琵琶，划出一曲流水。\n",
		"香玉轻舒纤腰，随音而舞起来。\n",
		"香玉咯咯一笑，露出两个小酒窝。\n",
        }) );
}

