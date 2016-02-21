inherit NPC;
#include "star.h"
 
void create()
{
        set_name("迪斯马斯克", ({"death mask","mask","ju xie"}));
        set("long", "巨蟹座黄金圣斗士。最卑鄙无耻的黄金圣斗士，杀人无数。曾刺杀
童虎不成，并和紫龙结怨，最后在自己制造的集尸气冥界波中被紫龙打败。但在冥界之战
中仍为雅典娜献身。\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",30);
        set("spi",40);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",8000000);
        set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "迪斯马斯克说道：不知何时能再见到雅典娜！\n"   
        }));
       set("attitude", "aggressive");
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("jinniu", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        setup();
        carry_object(__DIR__"obj/jx_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               
 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }

     switch(random(6))

     {        
        case 0:
        {
        message_vision(HIR"$N高举双手，$n的面前忽然出现了冥界黄泉路！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIR"$N被迪斯马斯克击中，差点摔进冥界洞穴中！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIR"你一声轻笑，躲开了这死亡之洞穴。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N眼望天空，使出[集尸气冥界波]$n被$N的小宇宙带进了黄泉入口！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIR"被$N杀死的冤魂蜂拥扑向你，你的身上被划了几处大血口！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"你强运全身内力,冲散了[集尸气冥界波]。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N口念咒语，一只巨蟹从天而降，落在$n的面前。\n",ob,me);
                              
        if(random(3)==0)

                {
              message_vision(HIR"巨蟹伸出一双大铁钳，夹住了你！\n"NOR,me);
              me->start_busy(3);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N定睛一看，原来是个幻象！\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/shuangzi")=="done") &&(ob&&ob->query("12gong/juxie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "闯过了第四宫巨蟹座，继续向黄金战士前进。\n"NOR,users());
        ob->set("12gong/juxie","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 10000);
        tell_object(ob,"你赢得了十年道行");

        }
       message_vision(HIC"\n\n\n随着迪斯马斯克的死亡, 那些无数被他杀害的亡魂渐渐离开了巨蟹宫.\n"NOR,ob);
	   ::die();
}

void unconcious()
{
  die();
}