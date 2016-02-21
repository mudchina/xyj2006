#include <ansi.h>
inherit NPC;

string *list=({"玫瑰仙子","茉莉仙子","月季仙子","芙蓉仙子", });
        
void create()
{
        set_name(list[random(sizeof(list))],({ "baicao xian", "baicao xianzi" }));
        set("title",MAG"百花仙子"NOR);
        set("per",random(5)+35);
        set("rank_info/respect", "百花仙子");
        set("long", "美丽的花仙子。\n");
        set("gender", "女性");
       set("family/family_name","月宫");
        set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
        (: cast_spell, "arrow" :),
      (: cast_spell, "mihun" :),
        }) );
        setup();
}

void init()
{    if(!query("canoe")) { 
    set("canoe",1);
    remove_call_out("leave");
    call_out("leave",300);
         }
}

void leave()
{
        message("vision",
		 name() + "喃喃地说道:得饶人处且饶人,我先走了！\n\n"
		+ name() + "诡异地对你一挥衣袖,消失在一阵狂风当中。\n" , environment(),this_object() );
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

{      
        int i, eff_dx, ski;
        ski=me->query_skill("spells",1)*1.2;
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
        ob->set_skill("snowsword",ski);
        ob->set_skill("parry",ski);
        ob->set_skill("sword",ski);
        ob->set_skill("force",ski);
        ob->set_skill("whip",ski);
        ob->set_skill("baihua-zhang",ski);
        ob->set_skill("moonforce",ski);
        ob->set_skill("jueqingbian",ski);
        ob->set_skill("moonshentong",ski);
        ob->set_skill("moondance",ski);
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("whip","jueqingbian");
        map_skill("parry", "jueqingbian");
        map_skill("spells","moonshentong");
        map_skill("dodge", "moondance");
        if (random(2))
          new("/d/obj/weapon/whip/longsuo")->move(ob);
        else
          new("/d/obj/weapon/sword/qingfeng")->move(ob);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}