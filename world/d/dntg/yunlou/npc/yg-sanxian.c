//created by lestat
inherit __DIR__"yaoguai.c";
#include <ansi.h>
void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        me->set("title",HIB"剑道传人"NOR);
        me->set_skill("unarmed", j);
        set("gender", "男性");
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("whip",j); 
        me->set_skill("sword",j); 
        me->set_skill("wuwei-fuchen", j+random(15));
        me->set_skill("spysword", j+random(15));        
        me->set_skill("binfen-steps",j+random(15));
        me->set_skill("mysticism", j+random(15));
        me->set_skill("butian-force", j+random(15));
        me->set_skill("ice_fire_zhang", j+random(15));
        me->map_skill("parry", "spysword");
        me->map_skill("spells", "mysticism");
        me->map_skill("dodge", "binfen-steps");
        me->map_skill("whip", "wuwei-fuchen");  
        me->map_skill("sword", "spysword");  
        me->map_skill("unarmed", "ice_fire_zhang");
        create_family("三界散仙", 2, "红");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "gold" :),
        (: cast_spell, "shengsi" :),
        }) );
//        if (random(2))
//             weapon=new("/d/obj/weapon/whip/longsuo");
//        else
          weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
