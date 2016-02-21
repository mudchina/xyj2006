
// À¥ÂØÑý¹Ö
//lestat 2001

inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

	set("title",HIW"ÌìÍâ·ÉÏÉ"NOR);
	set("gender", "ÄÐÐÔ");
//	set("gender","´ÆÐÔ");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("mace", j+random(15));
        me->set_skill("dashen-bian", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("wugou-jian",j+random(15));
        me->set_skill("lingyunbu", j+random(15));
        me->set_skill("yuxu-spells", j+random(15));
        me->set_skill("kaitian-zhang", j+random(15));
        me->set_skill("xuanzong-force", j+random(15));

        me->map_skill("force", "xuanzong-force");
        me->map_skill("sword", "wugou-jian");
        me->map_skill("mace","dashen-bian");
        me->map_skill("parry", "wugou-jian");
        me->map_skill("spells", "yuxu-spells");
        me->map_skill("dodge", "lingyunbu");
        me->map_skill("unarmed", "kaitian-zhang");
        create_family("À¥ÂØÉ½ÓñÐé¶´",3 , "µÜ×Ó");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "fantian" :),
        (: cast_spell, "huodun" :),
//        (: perform_action,"sword", "feixian" :),
        }) );
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}

