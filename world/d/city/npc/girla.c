#include <ansi.h>

inherit NPC;

void create()
{
        set_name("花钿", ({ "ban niang","niang", "girl"}) );
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
            "花钿拿起玉笛，轻声吹出几音。\n",
	    "花钿对你微微一笑。\n",
	    "花钿随乐轻歌慢舞起来。\n",

        }) );
}

