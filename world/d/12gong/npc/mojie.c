inherit NPC;
#include "star.h"
 
void create()
{
        set_name("修罗", ({"shura", "mo jie"}));
        set("long", "号称对雅典娜最忠诚的圣斗士，十二宫之战中，为救紫龙而献身。
拥有雅典娜赐予的艾斯卡利巴圣剑。 守护着山羊座.\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("attitude", "friendly");
        set("age",37);
        set("con",45);
        set("per",30);
        set("str",63);
        set("int",64);
        set("combat_exp",10000000);
        set("daoxing",10000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "修罗说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 400);
        set("attitude", "friendly");
        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("unarmed", 400);
        set_skill("sword", 400);
        set_skill("westsword",400);
        set_skill("boxing",400);
        set_skill("balei",400);
        set_skill("spells",400);
        set_skill("renma", 400);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_force",6000);
        set("force", 12000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",50);
        set("force_factor",250);
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);

        setup();
        carry_object(__DIR__"obj/mj_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N冷笑一声：在我$N面前，你想耍什么花样？\n",me);
        return 1;
} 
void check()
{
        object ob=this_object();
        object ghost;
        object me2=new("/d/12gong/npc/mojie2.c");
        object me=query_temp("my_killer");

        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     switch(random(4))
     {        
        case 0:
        {
        message_vision(HIY"$N跪在地上，大地剧烈的震撼着！\n",ob);

        if(random(2)==0)
                {
              message_vision(HIY"$N被震的东倒西歪，失去了平衡！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIW"$N站稳脚跟，和$n继续搏斗着。\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N举起右手,小宇宙随之爆发,就像一把[圣剑]向你斩来!\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIM"$N一个不小心，被[圣剑]刺了个血窟窿！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N轻身跃起，[圣剑]从$N的身下划过。\n"NOR,me);
        }
        break;

   //     case 2:
   //     {

  //      message_vision(HIW"$N摇身一变，分出另外一个自己来！\n",ob);
//        if( present("kelowooz two",environment()));
  //      return;
 //       me2->move(environment());
 //       me2->kill_ob(me);
  //      }
   //     break;
                    

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/renma")=="done") && (ob&&ob->query("12gong/mojie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "闯过了第十宫山羊宫，继续向黄金十二宫前进！\n"NOR,users());
        ob->set("12gong/mojie","done");
        ob->add("12gong/number",1);
     ob->add("daoxing", 10000);
        tell_object(ob,"你赢得了十年道行");

        }
       ::die();
}

void unconcious()
{
  die();
}
