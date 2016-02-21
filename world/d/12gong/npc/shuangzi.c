inherit NPC;
#include "star.h"
 
void create()
{
        set_name("双子座圣斗士", ({"shuang zi"}));
        set("long", "守护双子座的黄金圣斗士,不过看不出他是一个活人。\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
         set("combat_exp",8000000);
          set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "双子座圣斗士死气沉沉的看着你,让人全身不舒服！\n"   
        }));
        set_skill("dodge", 250);
       set("attitude", "aggressive");

        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("shuangzi", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangzi");
        map_skill("dodge","balei");
        set("max_force", 4000);
        set("force", 8000);
        set("max_mana",4500);
        set("mana",9000);
        set("mana_factor",180);
        set("force_factor", 150);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        setup();
        carry_object(__DIR__"obj/sz_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        object me=this_player();
		::init();
		if( !me || !visible(me) || environment(me) != environment() ) return;
		
		message_vision(HIY"\n你只觉得来到了一个神秘的空间,空气中都充满了诡异的力量!\n\n"NOR,me); 
		add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}

void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;

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
        message_vision(HIG"$N释放出小宇宙[黄金异次元]，一阵狂风呼啸而起！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIG"$N被卷进异次元空间，毫无半点力量！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N再次使出[黄金异次元]，一道闪电劈向$n！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N被闪电劈了个正着，直电的头皮发麻！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N早就看清了闪电的方向，轻轻一闪，躲开了。\n"NOR,me);
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
        
		 if((ob&&ob->query("12gong/jinniu")=="done") && (ob&&ob->query("12gong/shuangzi")!="done"))
         {
        
		ob->start_busy(3);
         
        message("chat",HIY+"【黄金十二宫】撒加(Sa ga):竟然有人能强闯过我的双子迷宫。。。。。。\n"NOR,users());
        ob->set("12gong/shuangzi","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 10000);
        tell_object(ob,"你得到了十年道行\n");
		
		}
        ob->move("/d/12gong/sz2jx1"); 
		ob->delete_temp("12gong/szkill");
	//    ob->set_temp("12gong/szgo");
	//	call_other("/d/12gong/szchoose","???");
    //    find_object("/d/12gong/szchoose")

		message_vision("\n\n打倒双子座黄金圣斗士后,神秘的力量随即消失,扭曲的时空也恢复了原状!\n\n"NOR,ob);
        message_vision("\n随着一声巨响,双子宫倒塌了下去.\n\n"NOR,ob);
//	   ::die();
	   destruct(this_object());

}

int do_none()
{
        object me = this_object();

        message_vision("$N发出一阵令人毛骨悚然的冷笑!\n",me);
        return 1;
}

void unconcious()
{
  die();
}
