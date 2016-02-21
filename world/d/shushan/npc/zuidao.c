// modified by vikee 2000.11
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_jiu();
int begin_go();
void attempt_apprentice(object ob);

void create()
{
        set_name(HIC"醉道士"NOR, ({ "zui daoshi", "daoshi", "zui" }));
        set("long", 
"醉道士是掌门人的师弟，因为好酒，所以做不了掌门。\n");

        set("gender", "男性");
set("title","蜀山派");
        set("age", 58);
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 35);
        set("con", 30);
        set("per", 30);
        set("class","swordsman");
        
        set("kee", 2500);
        set("max_kee", 2500);
        set("sen", 3500);
        set("max_sen", 3500);
        set("force", 4000);
        set("max_force", 2000);
        set("max_mana", 3000);
        set("mana", 6000);
        set("force_factor", 80);
        set("mana_factor", 100);

        set("combat_exp", 2500000);
        set("dapxing", 3000000);

        set_skill("spells",180);
        set_skill("force", 180);
        set_skill("dodge", 170);
        set_skill("parry", 150);
        set_skill("sword", 180);
        set_skill("zixia-shengong", 180);
set_skill("sevensteps", 170);
        set_skill("literate", 130);
        set_skill("unarmed", 170);
set_skill("yujianshu",140);
        set_skill("hunyuan-zhang",140);
        set_skill("taoism",180);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
map_skill("parry", "yujianshu");
map_skill("sword", "yujianshu");
        map_skill("unarmed", "hunyuan-zhang");

        create_family("蜀山派", 5, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "recover" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 40);
   set("inquiry", ([
   "去镇妖塔"     : (: ask_me :),
   "灵台观礼": (: begin_go :), 
   "酒神"     : (: ask_jiu :),
]) );
        setup();
        carry_object("d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 30) 
        {
                command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我蜀山剑派武功？");
                return;
        }
        if ( ob->query("daoxing") < 150000) {
                command("say " + RANK_D->query_respect(ob) + "的道行是不是低的点？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
int ask_me()
{
        object ob=this_player();
if(ob->query("family/family_name") != "蜀山派")
        {
        command("say 你又不是蜀山剑派的，谁管你！");
        return 1;
        }
        if(ob->query("nyj/shushan")=="done")
        {
          command("say 你是不是记错了，这个问题你问过的了吧！");
          return 1;
        }
        if(ob->query("family/master_name")!= this_object()->query("name"))
        {
        command("say 你又不是我的徒弟，谁管你！");
        return 1;
        }
        command("sigh");
        if(ob->query("combat_exp",1)< 500000)
        return notify_fail("你的道行太低，还是不要去送死吧！");
        command("say 好吧，看来我是拦不住你了，你去吧！");
        if(!ob->query("shushan/jiushen_master"))
        {
        ob->set("shushan/jiushen_master",1);
        command("say 这一招酒神，是为师唯一能给你的，绝不比任何法术差！它应该可以帮你保命的！");
        }
        ob->set("shushan/ask_zuidao_go", 1);
    return 1;
}

int ask_jiu()
{
        object ob=this_player();
if(ob->query("family/family_name") != "蜀山派")
        {
        command("say 你又不是蜀山剑派的，学它做什么?");
        return 1;
        }
        if(ob->query("family/master_name")!= this_object()->query("name"))
        {
        command("say 你又不是我的徒弟，谁管你！");
        return 1;
        }
        if(!ob->query("shushan/jiushen_master"))
        {
        ob->set("shushan/jiushen_master",1);
        command("say 这一招酒神，是为师唯一能给你的，绝不比任何法术差！它应该可以帮你保命的！");
        ob->set("shushan/ask_zuidao_go", 1);
        return 1;
	} else
	{
        command("say 这一招酒神，我不是已经传给你了吗?");
        return 1;
	}
}

int begin_go()
{
	object me;
    me=this_player();
	if (!me->query("fangcun/panlong_visite"))
	return 0;
	
	if (me->query_temp("fangcun/panlong_shushan_jiujianxian")=="begin")
	{
        message_vision("\n酒剑仙遥望天边道：酒,酒,酒,此酒只应天上有！\n"NOR,me);
		return 1;
    }
    message_vision("\n酒剑仙叹道：酒,酒,酒,美酒穿肠过,笑叹世间情！\n"NOR,me);
    me->set_temp("fangcun/panlong_shushan_jiujianxian","begin");
	return 1;
}

void return_ob (object ob, object who)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void destruct_me (object ob)
{
  destruct (ob);
}

int accept_object (object who, object ob)
{
object jiudai,pass;
string liquid_name;
string liquid_type;
object me = this_object();
liquid_name = YEL"仙酒"NOR;
liquid_type = "alcohol";
  if ((string)ob->query("liquid/type")!="alcohol")
   {
     command ("shake "+ob->query("id"));
	call_out ("return_ob",1,ob,who);
    return 1;
  }
  
  if (ob->query("liquid/remaining") == 0)
  {
    message_vision ("$N摇了一下头，说道：空的,拿来骗人吗?\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if (ob->query("liquid/name") != liquid_name)
  {
    message_vision ("$N摇了一下头，说道：这种酒也称得上好酒?\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
  }
  if(!who->query_temp("yaochi_fill"))
  {
	   message_vision ("$N摇了摇头，说道：这不是凭你自己的本事拿到的酒！\n",me);
    call_out ("return_ob",1,ob,who);
    return 1;
    
  }
 
  message_vision (HIW"$N一口气喝干了仙酒开怀大笑道：好酒,好酒！" + RANK_D->query_respect(ob) + ",这个东西你拿去,哈哈,真是好酒啊！\n"NOR,me);
  message_vision ("$N给你一个空酒葫芦.\n"NOR,me);
  pass=new("/d/shushan/obj/jiujianxian-pass");
  pass->move(who);
  return 1;
  
  
}
