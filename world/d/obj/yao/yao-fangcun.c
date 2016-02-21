inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"
#include <ansi.h>
// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;
        int exp;

        set("class","taoist");
        set("family/family_name","方寸山三星洞");
        me->set("title",HIG"乾坤一击"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("stick", j+random(5));
        me->set_skill("qianjun-bang", j+random(5));
        me->set_skill("jindouyun", j+random(5));
        me->set_skill("wuxiangforce", j+random(5));
        me->set_skill("puti-zhi", j+random(5));
        me->set_skill("dao", j+random(5));

        me->map_skill("force", "wuxiangforce");
        me->map_skill("stick","qianjun-bang");
        me->map_skill("parry", "qianjun-bang");
        me->map_skill("spells", "dao");
        me->map_skill("dodge", "jindouyun");
        me->map_skill("unarmed", "puti-zhi");

	exp=query("combat_exp");
	
      if(exp>1000000){	
	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"stick.pili" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "light" :),
        (: cast_spell, "dingshen" :),
        }) );

	if(exp<10000000){
          weapon=new("/d/obj/weapon/stick/mugun");
          set("weapon_","/d/obj/weapon/stick/mugun");
          weapon->move(me);
          command("wield all");
	}else{
          weapon=new("/d/obj/weapon/stick/xiangmo");
          set("weapon_","/d/obj/weapon/stick/xiangmo");
          weapon->move(me);
          command("wield all");
        }
      } 
}

