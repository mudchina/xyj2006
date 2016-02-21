
// bula and mon@xyj

inherit __DIR__"yaoguai.c";
#include <ansi.h>

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        set("title",HIY"天地同寿"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("hammer", j+random(15));
        me->set_skill("kaishan-chui", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("sanqing-jian",j+random(15));
        me->set_skill("baguazhen", j+random(15));
        me->set_skill("taiyi", j+random(15));
        me->set_skill("wuxing-quan", j+random(15));
        me->set_skill("zhenyuan-force", j+random(15));

        me->map_skill("force", "zhenyuan-force");
        me->map_skill("sword", "sanqing-jian");
        me->map_skill("hammer","kaishan-chui");
        me->map_skill("parry", "kaishan-chui");
        me->map_skill("spells", "taiyi");
        me->map_skill("dodge", "baguazhen");
        me->map_skill("unarmed", "wuxing-quan");
        create_family("五庄观", 3, "弟子");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "zhenhuo" :),
(: perform_action,"sword", "sanqing" :),
(: perform_action,"blade", "damoyange" :),
        (: cast_spell, "baxian" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/blade/yanblade");
        else
           weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
