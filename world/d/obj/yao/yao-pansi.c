
// ÅÌË¿¶´Ñı¹Ö
//lestat 2001
inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"
#include <ansi.h>
// here should be this NPC specific skills.


void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;
        me->set("title",MAG"ÁùÖ¸ÇÙÄ§"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("whip",j); 
		me->set_skill("sword",j); 
        
        me->set_skill("yinsuo-jinling", j+random(5));
	me->set_skill("qingxia-jian", j+random(5));        
        me->set_skill("spells",j+random(5));
        me->set_skill("yueying-wubu",j+random(5));
        me->set_skill("pansi-dafa", j+random(5));
        me->set_skill("unarmed", j+random(5));        
        me->set_skill("lanhua-shou", j+random(5));
        me->set_skill("jiuyin-xinjing", j+random(5)); 

        me->map_skill("force", "jiuyin-xinjing");
        me->map_skill("whip", "yinsuo-jinling");  
		me->map_skill("sword", "qingxia-jian");
        me->map_skill("parry", "qingxia-jian");
        me->map_skill("spells", "pansi-dafa");
        me->map_skill("dodge", "yueying-wubu");
        me->map_skill("unarmed", "lahua-shou");
        create_family("ÅÌË¿¶´", 3, "ºì");
        exp=query("combat_exp");
    if(exp>1000000){
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"whip", "wang" :),
        (: cast_spell, "wuzhishan" :),
        }) );}        
        weapon=new("/d/sea/obj/dragonwhip");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
