// modified by vikee
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int begin_go();
int ask_me();
int recruit_apprentice(object ob);
int attempt_apprentice(object me);
int do_report();

void create()
{
        set_name("李逍遥", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","蜀山剑派入门弟子");
        set("long", 
"李逍遥身材较瘦，长的浓眉阔眼，气宇暄昂。\n");
        set("gender", "男性");
        set("age", 18);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2800);
        set("max_kee", 2800);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 4800);
        set("max_force", 2400);
        set("mana", 4800);
        set("max_mana", 2400);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("spells", 180);
        set_skill("parry", 140);
        set_skill("sword", 180);
        set_skill("canxin-jian", 200);
        set_skill("zixia-shengong", 130);
set_skill("sevensteps",160);
//        set_skill("jingya-sword", 130);
        set_skill("literate", 80);
        set_skill("taoism",120);
        map_skill("spells", "taoism");
        map_skill("force", "zixia-shengong");
map_skill("dodge", "sevensteps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword","xiangsi" :),
                (: exert_function, "powerup" :),
        }) );

        set("inquiry", ([
                "灵台观礼": (: begin_go :),
            	"赵灵儿" : "你能帮我去救灵儿？我可会报答你的！\n",
                "醉道士" : "好久没见师父了！\n",
                "去镇妖塔"     : (: ask_me :),
                "任务完成"     : (: do_report :),
		        "done"    : (: do_report :),
        ]));
        setup();
        create_family("蜀山派", 5, "入门弟子");
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

int attempt_apprentice(object me)
{
me =this_player();
//  if (me->query("family/family_name") != "蜀山剑派" || me->query("myj/shushan") != "done")
   if (me->query("family/family_name") != "蜀山派" || me->query("nyj/shushan") != "done")
  {
   command("say 只有蜀山弟子，去救回了灵儿，我才会收的。");
   return 0;
  }
//  if( (string)me->query("family/family_name")!="蜀山派" )
//	  return 0;
  command("pat "+me->query("id"));
  command("say 那我收下你吧．");
  command("recruit " + me->query("id") );
  return 1;
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
        add_action("do_nod", "nod");

}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "李逍遥说道：这位" + RANK_D->query_respect(ob) +
"，能不能帮我救出灵儿！她被关进镇妖塔里了！\n");
}

int do_report()
{
        int i=random(500)+1;
        object who = this_player();
        object me = this_object();
        if(who->query("nyj/shushan") == "done"){
        command("shake "+who->query("id"));
        return 1;
        }
//        if (objectp(present("zhao linger", environment(me)))) 
//        {       
        if (who->query_temp("shushan/linger_daying") == 1){
        command("thank "+who->query("id"));
        command("u&me "+who->query("id"));
        command("chat "+who->name()+"成功打破镇妖塔，救出灵儿，打破了数百年来没人能在镇妖塔出来的记录！\n");
//        who->set("myj/shushan","done")
        who->set("nyj/shushan","done");
        who->add("daoxing",3000+i);
        tell_object(who,"你赢得了"+chinese_number(3)+"年"+chinese_number(i/4)+"天"+chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
        who->set("title","仙剑奇侠");
        who->save();
        return 1;
        }
//        }
        command("? "+who->query("id"));
        return 1;
}

int ask_me()
{
        object ob=this_player();
        if(ob->query("nyj/shushan") == "done")
        {
        command("say 谢谢你！不能再麻烦你啦！");
        return 1;
        }
        command("wa");
        command("say 好吧，拜托你啦，成功救出灵儿的话，一定要告诉我！");        
        return 1;
}

int begin_go()
{
	object me;
    me=this_player();
	
	if(me->query_temp("save_linger"))
	{
        command("say " + RANK_D->query_respect(me) + "见到灵儿了吗？");
		return 1;
	}

	command("say 好吧，既然是菩提大师叫你来的,信物可以给你.只是灵儿被关在镇妖塔中受苦,不知" + RANK_D->query_respect(me) + "能否前去
	    与我一起把灵儿救出来？(nod)");        
    me->set_temp("save_choose",1);
   return 1;
}

int do_nod()
{       
        object me,pass,ob;
        me=this_player();
        ob=this_object(); 
        if(!me->query_temp("save_choose"))
			return 0;
		me->delete_temp("save_choose");
        me->set_temp("save_linger",1);
        command("say 既然" + RANK_D->query_respect(me) + "答应相助,李逍遥这里谢过了！");        
		pass=new("/d/shushan/obj/lixiaoyao-pass");
		pass->move(me);
        message_vision("\n\n"NOR,me);
		command("bow");
        message_vision("\n\n"NOR,me);
		command("say " + RANK_D->query_respect(me) + "此去虽危险重重,但以" + RANK_D->query_respect(me) + "的武功应该没有问题,只是遇到了镇狱明王
    千万不要跟他交手,切记切记！！！");        
        message_vision("\n李逍遥给你一条蓝布头巾,便先行进入镇妖塔去了\n\n"NOR,me);
        me->set("fangcun/panlong_nowayshushan",1);
		destruct (ob);
		return 1;

}

