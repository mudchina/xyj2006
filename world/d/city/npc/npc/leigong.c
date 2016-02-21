
//  妖神之争  １。０
//  by happ@YSZZ 2000.04.09
//  /d/sky/npc/leigong.c 雷公

inherit NPC;
#include <ansi.h>

void create()
{
       set_name("雷公", ({"lei gong", "lei", "gong"}));
       set("long", "一个耳朵很长的怪人，手中持一对铁罄。\n");
       set("gender", "男性");
       set("age", 70);
       set("attitude", "friendly");
       set("per", 30);
       set("max_kee",8000);
       set("max_sen", 8000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 20);
       set("combat_exp", 1200000);

        set("eff_dx", 250000);
        set("nkgain", 400);
        set("class","taoist");
       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
   set_skill("stick", 120);
   set_skill("spells", 120);
   set_skill("dao", 120);
   set_skill("puti-zhi", 120);
   set_skill("wuxiangforce", 120);
   set_skill("force", 120);
   set_skill("qianjun-bang", 120);
   set_skill("jindouyun", 120);
   map_skill("spells", "dao");
   map_skill("unarmed", "puti-zhi");
   map_skill("force", "wuxiangforce");
   map_skill("stick", "qianjun-bang");
   map_skill("parry", "qianjun-bang");
   map_skill("dodge", "jindouyun");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "thunder" :),
                "雷公怒道：又是来抢我的雷灵珠的。\n"
        }) );

        set("inquiry", ([
           "雷灵珠" : "此乃我的宝贝．",
]) );

setup();

        carry_object("/d/lingtai/obj/xiangpao")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}


int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

// tomcat mod
void die()
{
        object ob = query_temp("my_killer");
        object zhu ;
        if ("/d/obj/baowu/leizhu"->in_mud())
        {
            message_vision(HIM"$N大喝一声：我去也。\n"NOR,this_object());
         }else{
            message_vision(HIM"只见$N大喊一声，宝贝暂借你玩两天。\n"NOR,this_object());
            message_vision(HIM"$N大喝一声：我去也。\n"NOR,this_object());
            zhu = new("/d/obj/baowu/leizhu");       
            zhu->move(ob);
         }
        destruct(this_object());
}

