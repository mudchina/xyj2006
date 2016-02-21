// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("阿布罗狄", ({"aphrodite", "shuang yu"}));
        set("long", "号称最美丽的圣斗士，并以玫瑰为武器。也是比较邪恶的黄金圣
斗士，但在冥界之战中仍为雅典娜献身。 守护着双鱼座.\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",60);
        set("per",32);
        set("str",80);
        set("int",80);
        set("combat_exp",10000000);
        set("daoxing",10000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "阿布罗狄说道：究竟谁能闯过黄金十二宫拿到黄金圣衣呢?\n"   
        }));
        set_skill("dodge", 300);
        set("cant_be_smashed",1);
        set("attitude", "friendly");
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("unarmed", 300);
        set_skill("sword", 300);
        set_skill("westsword",300);
        set_skill("boxing",300);
        set_skill("balei",300);
        set_skill("spells",300);
        set_skill("shuangyu", 300);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangyu");
        map_skill("dodge","balei");
        set("max_force", 4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",80);
        set("force_factor", 50);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        setup();
        carry_object(__DIR__"obj/sy_cloth")->wear();
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
		message_vision("$N冷笑一声：在守护雅典娜女神最后的黄金宫殿里,你想耍什么花样？\n",me);
        return 1;
} 
void check()
{
        object ob=this_object();
        object rose;
        object me2=new("/d/12gong/npc/shuangyu2.c");
		object me=query_temp("my_killer");

        if( ! me ) return ;
  
    if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     switch(random(6))
     {        
        case 0:
        {
       
         message_vision(HIC"$N念了一声：#$%^%!，变成一只双头怪鱼！\n",ob);

        if(random(2)==0)
                {
              message_vision(HIM"怪鱼张开大嘴，对着$N一阵狂撕！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIG"$N一个急转，夺开这夺命一击！\n"NOR,me);
         }
        break;

        case 2:
        {
       
         if( present("aphrodite two",environment())) return;
      message_vision(HIW"$N摇身一变，分出另外一个自己来！\n",ob);
      me2->move(environment());
      me2->kill_ob(me);
          
		 }
        
        break;

        case 3:
        {
        rose=new("/d/12gong/npc/obj/rose.c");
        message_vision(HIC"$N嘴里衔着一只红玫瑰，只见$N嘴唇微动，红玫瑰如离弦的箭刺向$n！\n"NOR,ob,me);
        rose->move(environment(this_object()));

         if(random(3)==0)
                {
              message_vision(HIM"$N被红玫瑰的毒刺刺伤了身体！\n");
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
              rose->move(environment());
                }
        else
        
        message_vision(HIG"$N看准红玫瑰飞来的方向，顺势接住了红玫瑰！\n"NOR,me);
        rose->move(me);

         }
        break;

  }
        if( random(3) == 1 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/baoping")=="done") && (ob&&ob->query("12gong/shuangyu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "终于闯完了黄金十二宫！\n"NOR,users());
        ob->set("12gong/shuangyu","done");
        ob->add("12gong/number",1);
     ob->add("daoxing", 10000);
        tell_object(ob,"你赢得了十年道行");
        }
       ::die();
}
