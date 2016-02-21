#include <ansi.h>
inherit NPC;

string *list=({"橄榄仙人","常青藤仙人","柏树仙人","青松仙人", });
        
void create()
{
      
        set_name(list[random(sizeof(list))],({ "baicao xian", "baicao xianzi" }));
        set("title",HIR"百草仙人"NOR);
        set("rank_info/respect", "百草仙人");
        set("long", "威武的花魁。\n");
        set("family/family_name","方寸山三星洞");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"stick", "pili" :),
                (: perform_action,"stick","qiankun" :), 
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) ); 
        setup();
       carry_object("/d/obj/weapon/stick/xiangmo")->wield();
       carry_object("/d/obj/armor/jinjia")->wear();
}

void init()
{   
    if(!query("canoe")) { 
    set("canoe",1);
    remove_call_out("leave");
    call_out("leave",300);
			}
}

void leave()
{
        message("vision",
		 name() + "喃喃地说道:得饶人处且饶人,我先走了！\n\n"
		+ name() + "一挥衣袖,消失在一阵狂风当中。\n" , environment(),this_object() );
	        destruct(this_object());
}

void die()
{
        object me, corpse;
        int i,exp,pot,dao;
        me = query_temp("last_damage_from");
        if(!me) 
        {
        destruct(this_object());
        return;
        }
        else 
        { 
        me->set_temp("killed_zi",1);
        leave();
        }
        
}
void copyskill(object ob,object me)

{        int i, eff_dx, ski;
        ski=me->query_skill("spells",1)*1.4;
        // 取spells最高等级,取巧算法　绝密　不能公布哦
        ob->set("str",me->query("str"));
        ob->set("int",me->query("int"));
        ob->set("con",me->query("con"));
        ob->set("per",me->query("per"));
        ob->set("cor",me->query("cor"));
        ob->set("spi",me->query("spi"));
        ob->set("cps",me->query("cps"));
        ob->set("kar",me->query("kar"));

        ob->set("max_kee",me->query("max_kee")*2);
        ob->set("eff_kee",me->query("max_kee")*2);
        ob->set("kee",me->query("kee")*2);

        ob->set("max_gin",me->query("max_gin")*2);
        ob->set("eff_gin",me->query("max_gin")*2);

        ob->set("gin",me->query("gin")*2);

        ob->set("max_sen",me->query("max_sen")*2);
        ob->set("eff_sen",me->query("max_sen")*2);
        ob->set("sen",me->query("sen")*2);

        ob->set("max_force",me->query("max_force"));
        ob->set("force",me->query("max_force")*2);
        ob->set("force_factor",me->query("max_force")/20); 
        ob->set("max_mana",me->query("max_mana"));
        ob->set("mana",me->query("max_mana")*2);
        ob->set("force_mana",me->query("max_mana")/15); 
        ob->set("daoxing",me->query("daoxing") * 6/5);
        ob->set("combat_exp",me->query("combat_exp") * 6/5);
        ob->set_skill("spells",ski);
        ob->set_skill("unarmed",ski);
        ob->set_skill("dodge",ski);
        ob->set_skill("stick",ski);
        ob->set_skill("qianjun-bang",ski);
        ob->set_skill("jindouyun",ski);
        ob->set_skill("changquan",ski);
        ob->set_skill("parry",ski);
        ob->set_skill("dao",ski);
        ob->set_skill("wuxiangforce",ski);
        map_skill("unarmed", "changquan");
        map_skill("force", "wuxiangforce");
        map_skill("spells", "dao");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
}
