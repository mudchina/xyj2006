#include <ansi.h>

inherit NPC;

void create()
{
        set_name("珠怜", ({ "ban niang","niang", "girl"}) );
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
