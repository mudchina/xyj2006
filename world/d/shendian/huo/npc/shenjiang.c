inherit NPC;
#include <ansi.h>
void copy_status(object me, object ob);
void copy_weapon(object me, object ob);
void create()
{
   set_name(HIW"八部"+HIR"神将"NOR, ({"shen jiang","jiang"}));
        setup();
        carry_object("/d/obj/weapon/hammer/bahammer")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
void init()
{
   object me = this_object();
   object ob =this_player();
     if (ob->query_temp("shendian/huomigong")=="begin")
   {
     me->reset_me(me);
   copy_status(me,ob);
   copy_weapon(me,ob);
//     me->setup();
  //      me->command("kill "+ob->query("id"));
     }
}
void reset_me (object me)
{
   int i;
   object *inv;
   mapping skill_status, map_status;
   string *skillnames, *mapnames;
   reset_eval_cost();
   if ( mapp(map_status = me->query_skill_map()) )
   {
     mapnames = keys(map_status);
     for(i=0; i<sizeof(mapnames); i++)
     {
        me->map_skill(mapnames[i]);
     }
   }
   if ( mapp(skill_status = me->query_skills()) )
   {
     skillnames = keys(skill_status);
     for(i=0; i<sizeof(skillnames); i++)
     {
        me->delete_skill(skillnames[i]);
     }
   }
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
     destruct (inv[i]);
   }
    set_name(HIW"八部"+HIR"神将"NOR, ({"shen jiang","jiang"}));
        me->set("title", HIB"八部天龙"NOR);
        me->set("long", "他就是八部神将。\n");
        me->set("gender", "男性");
        me->set("age",31);
        me->set("attitude", "heroism");
        me->set("str", 28);
        me->set("mana", 3000);
        me->set("max_mana", 3000);
        me->set("force", 4500);
        me->set("max_force", 4500);
        me->set("combat_exp", 1500000);
    me->set("daoxing",3000000);
        me->set_skill("force", 300);
        me->set_skill("dodge", 300);
        me->set_skill("unarmed", 300);
        me->set_skill("parry", 300);
        me->set_skill("hammer", 300);
        me->set_skill("kaishan-chui", 300);
        me->set_skill("dao", 300);
        me->set_skill("spells", 300);
        me->map_skill("spells", "dao");
        me->map_skill("hammer", "kaishan-chui");
        me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
//      me->setup();
        reset_eval_cost();
        carry_object("/d/obj/weapon/hammer/bahammer")->wield();
    carry_object("/d/obj/armor/jinjia")->wear();
}
void copy_status(object me, object ob)
{
//   object *inv;
   mapping hp_status, skill_status, map_status;
   string *sname, *mname,killme,killmeid;
   int i,j;//, weapon_cnt, armor_cnt;
   reset_eval_cost();
   hp_status = ob->query_entire_dbase();
   me->set("str", hp_status["str"]);
   me->set("per", hp_status["per"]);
   me->set("int", hp_status["int"]);
   me->set("age", hp_status["age"]);
   me->set("gender",    hp_status["gender"]);
   me->set("combat_exp",hp_status["combat_exp"]+hp_status["combat_exp"]/3);
  me->set("daoxing",hp_status["daoxing"]+hp_status["daoxing"]/3);
   me->set("chat_chance_combat",40);
   me->set("chat_msg_combat", ({
        (: cast_spell, "bighammer" :),
        (: cast_spell, "jingang" :),
        (: cast_spell, "yinshen" :),
        (: cast_spell, "light" :),
        (: cast_spell, "fenshen" :),
        (: cast_spell, "dingshen" :),
        (: cast_spell, "invocation" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "arrow" :),
        (: cast_spell, "mihun" :),
        (: cast_spell, "gouhun" :),
        (: cast_spell, "freez" :),
        (: cast_spell, "hufa" :),
        (: cast_spell, "miwu" :),
        (: cast_spell, "huanying" :),
        (: cast_spell, "tudun" :),
        (: cast_spell, "suliao" :),
        (: cast_spell, "gouhun" :),
        (: cast_spell, "escape" :),
        (: cast_spell, "jieti" :),
        }) );//增加难度
   me->set("max_gin",     hp_status["max_gin"]);
  me->set("max_kee",     hp_status["max_kee"]*2);
   me->set("max_sen",     hp_status["max_sen"]);
   me->set("max_force",   hp_status["max_force"]);
   me->set("max_mana",    hp_status["max_mana"]);
   me->set("eff_gin", me->query("max_gin"));
   me->set("gin",     me->query("max_gin"));
   me->set("eff_kee", me->query("max_kee"));
    me->set("kee",     me->query("max_kee"));
   me->set("eff_sen", me->query("max_sen"));
   me->set("sen",     me->query("max_sen"));
    me->set("eff_dx", me->query("combat_exp"));
   me->set("force",   me->query("max_force")+me->query("max_force")*4/3);
   me->set("mana",    me->query("max_mana")+me->query("max_mana")*4/3);
   if(skill_status = me->query_skills()) {// delete old skills.
      sname  = keys(skill_status);
      j=sizeof(skill_status);
           for(i=0; i<j; i++) {me->delete_skill(sname[i]);}
   }
   if (skill_status = ob->query_skills() ) {//copy new skills.
      sname  = keys(skill_status);
      for(i=0; i<sizeof(skill_status); i++) {me->set_skill(sname[i], skill_status[sname[i]]);}
   }
   me->set("force_factor",me->query_skill("force")*4/3);
   me->set("mana_factor", me->query_skill("spells")*4/3);
   me->add_temp("apply/armor",(me->query_skill("spells")+me->query_skill("force"))/8);
   me->add_temp("apply/dodge",(me->query_skill("spells")+me->query_skill("force"))/8);
   me->add_temp("apply/damage",(me->query_skill("spells")+me->query_skill("force"))/10);
   reset_eval_cost();
   //delete old skill mappings.
   if(map_status = me->query_skill_map()) {
     mname  = keys(map_status);
     j=sizeof(map_status);
     for(i=0; i<j; i++) {
       me->map_skill(mname[i]);
   }}
   //add new skill mappings.
   if (map_status = ob->query_skill_map()) {
     mname  = keys(map_status);
     for(i=0; i<sizeof(map_status); i++) {
     me->map_skill(mname[i], map_status[mname[i]]);
   }}
   copy_weapon(me,ob);//复制装备
//   me->setup();
   me->save();
   reset_eval_cost(); //   return 1;
}
void copy_weapon(object me, object ob)
{
   object *inv;
   int i,j, weapon_cnt, armor_cnt;
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
     destruct(inv[i]);
   }
   // save once here, an external bug might stop the following
  // me->setup();
   me->save();
   weapon_cnt = 0;
   armor_cnt = 0;
   inv = all_inventory(ob);
   for(i=0; i<sizeof(inv); i++)
   {
     if ( !inv[i]->query_unique() &&
     inv[i]->query("skill_type") &&
     inv[i]->query("equipped") && !weapon_cnt )
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me))
          obj->wield();
        }
        me->set("weapon", base_name(inv[i]));
        weapon_cnt = 1;
     }
     else if ( !inv[i]->query_unique() &&
     !inv[i]->query("skill_type") &&
     inv[i]->query("equipped") && !armor_cnt )
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me))
          obj->wear();
        }
        me->set("armor", base_name(inv[i]));
        armor_cnt = 1;
     }
     else if( weapon_cnt && armor_cnt )
        break;
   }
}
void kill_ob (object ob)
{
        object me = this_object();
        message_vision (CYN"$N嘿嘿一笑：放马过来！\n\n"NOR,me);
  //     me->reset_me(me);
  //    copy_status(me,ob);
        copy_weapon(me,ob);
        set_temp("my_killer",ob);
  ::kill_ob(me);
}
void unconcious()
{
        int i;
        object me = this_object();
        object ob = query_temp("my_killer");
        if( environment() ) {
                message("sound", HIY"\n"+me->query("name")+"化成一股清烟冲上天去。。。\n\n"NOR, environment());
        }
        ob->add_temp("shendian/huomigong_kill",1);
   destruct(me);
}
void die()
{
        unconcious();
}