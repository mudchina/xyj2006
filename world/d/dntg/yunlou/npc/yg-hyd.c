//modified by vikee
//2000-12-9 23:34



inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        set("title",RED"»ðÔÆÐ°Éñ"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("spear", j+random(15));
        me->set_skill("huoyun-qiang", j+random(15));
        me->set_skill("moyun-shou",j+random(15));
        me->set_skill("moshenbu",j+random(15));
        me->set_skill("huomoforce", j+random(15));
        me->set_skill("pingtian-dafa", j+random(15));
        me->set_skill("dali-bang", j+random(15));
        me->set_skill("stick", j+random(15));

        me->map_skill("force", "huomoforce");
        me->map_skill("spear", "huoyun-qiang");
        me->map_skill("stick","dali-bang");
        me->map_skill("parry", "dali-bang");
        me->map_skill("spells", "pingtian-dafa");
        me->map_skill("dodge", "moshenbu");
        me->map_skill("unarmed", "moyun-shou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (: cast_spell, "sanmei" :),
//(: perform_action,"stick", "baiyun" :),
    //    (: cast_spell, "zhuang" :), this spells is to dangerous to player :P vikee 2000-12-9 23:35
        }) );

//        if (random(2))
//           weapon=new("/d/obj/weapon/stick/xiangmo");
//        else
           weapon=new("/d/obj/weapon/stick/xiangmo");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
