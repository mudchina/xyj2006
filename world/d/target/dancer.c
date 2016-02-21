//captor.c

inherit NPC;
#include <ansi.h>
#include <auto_move.h>
int msg();

void create()
{
	mapping name;
	
	name=NAME_D->random_name("female");
	set_name(name["name"], name["id"]);
	set("title", name["title"]);
	set("age", 20+random(10));
	set("per", 20+random(10));
	set("gender", "女性");
	set("long", "长安大明宫的歌女。\n");
	
        set("combat_exp", 1000+random(1000));
        set("wuxue_exp", 5000+random(5000));
        set_skill("unarmed", 10+random(10));
        set_skill("dodge", 10+random(10));
        set_skill("parry", 10+random(10));
        set("max_kee", 100+random(100));
        set("max_sen", 100+random(100));
        set("max_force", 100+random(100));
        set("force", 30);
        set("force_factor",2);
        set("mana_factor", 2);
        set("max_mana", 50+random(50));
        set("mana", 20);

	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :),
		(: msg :),
	}));

	set("move_msg/out", "$N轻移莲步慢慢上了一辆马车。\n");
	set("move_msg/int", "$N轻移莲步从马车上走了下来。\n");
	set("move_msg/dis", "$N轻移莲步慢慢上了一辆马车。\n");
	
	setup();
        carry_object("/d/obj/cloth/xiuhuaxie")->wear();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
	
	call_out("auto_disapper", AUTO_DEST_TIME);
	call_out("auto_move", AUTO_MOVE_TIME*3/2);
}

int msg()
{
	string *msg=({	
        "$N拿起玉笛，轻声吹出几音。\n",
        "$N随乐轻歌慢舞起来。\n",
        "$N轻拨琵琶，划出一曲流水。\n",
        "$N轻舒纤腰，随音而舞起来。\n",
        "$N咯咯一笑，露出两个小酒窝。\n",
        "$N纤手轻拨琴弦，发出如柳润风般的乐声。\n",
        "$N轻音而唱，如雀鸣莺歌。\n",
                });
        message_vision(msg[random(sizeof(msg))] , this_object());
        return 1;
}
