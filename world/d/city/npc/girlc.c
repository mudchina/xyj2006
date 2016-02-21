#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小真", ({ "ban niang","niang", "girl"}) );
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
		"小真纤手轻拨琴弦，发出如柳润风般的乐声。\n",
		"小真玉臂轻晃，随乐而舞。\n",
		"小真轻音而唱，如雀鸣莺歌。\n",
        }) );
}

