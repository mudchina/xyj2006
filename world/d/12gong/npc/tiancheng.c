inherit NPC;
#include "star.h"
 
void create()
{
        set_name("童虎", ({"dohko", "tian chen"}));
        set("long", "传说中在庐山五老峰静坐243年的中国神秘老人,天平座。上一代的
黄金圣斗士，负责看管被雅典娜封印的一百零八名冥斗士，并被雅
典娜赐予返老还童术。 \n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",300);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",4000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "童虎说道：只有东方才有最好的功夫。\n",
        }));
        set_skill("dodge", 300);
        set("attitude", "friendly");
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("unarmed", 300);
//        set_skill("staff", 300);
//        set_skill("lunhui-zhang",300);
        set_skill("dragonfight",300);
        set_skill("dragonstep",300);
        set_skill("spells",300);
        set_skill("seashentong", 300);
//        map_skill("staff","lunhui-zhnag");
        map_skill("unarmed","dragonfight");
        map_skill("spells","seashentong");
        map_skill("dodge","dragonstep");
        map_skill("parry","dragonfight");

		set("max_force", 6000);
        set("force", 13000);
        set("max_mana",7000);
        set("mana",14000);
        set("mana_factor",100);
        set("force_factor",0);
        set("max_kee", 3500);
        set("max_gin", 3500);
        set("max_sen", 3500);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
   //     carry_object("/d/obj/weapon/staff/tc_staff")->wield();
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

     switch(random(5))
     {        
        case 0:
        {
        message_vision(HIC"$N大喊一声『庐山升龙霸』一条居龙自九天而起，直飞$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"$N被巨龙在空中顶得翻了几十个跟头！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else        message_vision(HIG"$N身型急转，不知道绕了多少圈才夺过巨龙的攻击！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N高喊一声：『庐山亢龙霸』，一条恶龙自溅底而出，尾巴向$n扫去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(GRN"$N被恶龙的尾巴甩了个正着，$N顿时眼冒金星！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIY"$N用尽全身力气，飞升而气，恶龙的尾巴正从$N的脚底板扫过！\n"NOR,me);
        } 
        break;

        case 2:
        {

        message_vision(HIR"$N高喊一声：『庐山百龙霸』，无数只巨龙向$n冲过来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIR"$N如一个球一样，被无数只巨龙在空中戏弄着！\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N看准了巨龙之间的空隙，左转右转，才勉强离难！\n"NOR,me,ob);
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

       
		if (ob->query_temp("12gong/cike") != "done")
	{
		
        message("chat",HIY+"【黄金十二宫】雅典娜(Athena):"+ob->name()+
        "闯过了第七宫：天秤宫!\n"NOR,users());
        
       message("say","\n童虎对你说道:你能打败我证明你的力量强大,以后的战斗会更加艰难,我传你一个绝招(tianlong),
不到最危险的时候切忌乱用！\n"NOR,ob);
       ob->set_temp("12gong/tianlong","done");
	   message_vision(HIY"\n\n童虎说完就消失了,你身上渐渐泛起了一条巨龙的身影,又渐渐隐去了.\n"NOR,ob);
    }

 if((ob&&ob->query("12gong/shinu")=="done") && (ob&&ob->query("12gong/tiancheng")!="done"))
{
     ob->start_busy(3);
              ob->set("12gong/tiancheng","done");
     ob->add("12gong/number",1);
      ob->add("daoxing", 10000);
       tell_object(ob,"你赢得了十年道行");
}
        if (ob->query_temp("12gong/cike") == "done")
    {
        message("chat",HIY+"【黄金十二宫】童虎(Dohko):"+ob->name()+
        "已经闯过我天秤宫!\n"NOR,users());
		::die();
		}

      destruct(this_object());
}

void unconcious()
{
  die();
}
