
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_love();
int begin_go();
string ask_mieyao();
string ask_cancel();
void create()
{
       set_name(HIM"紫霞仙子"NOR, ({"zixia xianzi", "zixia", "xianzi","master"}));
       set("long", "她就是盘丝洞的开山祖师,传说她是佛祖的一棵灯芯。随佛祖修道悟
真,后来思凡下界占了花果山一处洞府,开山立派,传授门徒。\n");
       set("title", HIB"盘丝大仙"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class","yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "小姑娘");
       set("cor", 30);
       set("per", 40);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
	   set("daoxing", 4000000);
       set_skill("literate", 180);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 180);
       set_skill("spells", 170);
       set_skill("whip", 180);
   set_skill("pansi-dafa", 170);
   set_skill("lanhua-shou", 180);
   set_skill("jiuyin-xinjing", 180);
   set_skill("chixin-jian", 180);
   set_skill("qin", 180);
   set_skill("yueying-wubu", 180);
   set_skill("yinsuo-jinling", 200);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
        }) );
   set("inquiry", ([
          "爱神" : (: ask_love :),
  	      "灵台观礼" : (: begin_go :),
           "修炼": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
]));
create_family("盘丝洞", 1, "红");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/pansi/obj/ziqing.c")->wield();
         carry_object("/d/pansi/obj/baohe.c");
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="盘丝洞") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，他日帮我杀了那个臭猴子。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "花果山盘丝大仙护法");
           ob->set("class", "yaomo");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

string ask_mieyao()
{
    object who=this_player();
    if((string)who->query("family/family_name")=="盘丝洞") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
int ask_love()
{
        object ob=this_player();
        if(ob->query("family/family_name") != "盘丝洞")
        {
        command("say 你又不是盘丝洞的，学它做什么?");
        return 1;
        }
        if(ob->query("family/master_name")!= this_object()->query("name"))
        {
        command("say 你又不是我的徒弟，谁管你！");
        return 1;
        }
        if(!ob->query("pansi/love_master"))
        {
        ob->set("pansi/love_master",1);
        command("say 这一招爱神，是为师多年修炼所悟，应该可以帮你保命的！");
        ob->set("pansi/ask_zixia_go", 1);
        return 1;
	} else
	{
        command("say 这一招爱神，我不是已经传给你了吗?");
        return 1;
	}
}

int begin_go()
{
	object me,ob,suo;
    me=this_player();
	ob=this_object();
	if (!me->query("fangcun/panlong_visite"))
	return 0;
	if (me->query("guanli/pansi"))
	  return 0;
	if ((me->query("fangcun/panlong_nowaypansi"))||(me->query("fangcun/panlong_pansi")=="done"))
		return 0;

	if (me->query("fangcun/panlong_pansi")!="begin")
    {
   message_vision("\n\n"NOR,me);
  command("say 小女子有幸得菩提祖师看得起让"+me->query("name")+RANK_D->query_respect(me)+ "专程来请，本应立即前往道
  贺，无奈我那青霞姐姐守在洞口，我又不愿跟她拼命相斗．不如"+me->query("name")+RANK_D->query_respect(me)+ "拿着我的
  银索金铃交给她说我们本是同根生，相煎何太急？\n\n\n");
  command("sigh ");
   me->set("fangcun/panlong_pansi","begin");
   message_vision(HIM"\n\n\n紫霞仙子"+NOR"给$N一条银白色的手链．\n"NOR,me);
   suo=new("/d/pansi/obj/yinsuo");
   suo->set_temp("zixia_xianzi",1);
   suo->move(me);
	return 1;
	}
	  message_vision(HIM"\n\n\n紫霞仙子"+NOR"对$N道：我姐姐走了吗？\n"NOR,me);
  return 1;
}

void die()
{
	object qingxia,erlang;
	object me=this_object();
    qingxia=present("qingxia xianzi");
	erlang=present("erlang zhenjun");
   if (!erlang)
	   return ::die();
   if (!qingxia)
	{
	   message_vision(HIY"\n\n\n杨戬从额上第三只眼中射出一道金光，"+HIM"紫霞"+HIY"重伤之下躲避不及被打回原形，化作一根灯芯被杨戬收了去．\n"NOR,me);
	  message_vision(HIY"\n\n\n二郎神哈哈大笑道：区区两根灯芯也敢跟我"+HIR"昭惠灵显王"+HIY"动手，真是不自量力．\n"NOR,me);
	  message_vision("\n\n\n言毕驾一阵狂风大笑而去．\n"NOR,me);
       destruct(erlang);
      if (present("xiaotian quan"))
        {    
            message("sound", "\n\n啸天犬也紧跟着二郎神扬长而去．\n\n", environment());
            destruct(present("xiaotian quan"));
        }
      destruct(me);
	  return;
	}
	   message_vision(HIY"\n\n\n杨戬从额上第三只眼中射出一道金光，"+HIM"紫霞"+HIY"重伤之下躲避不及被打回原形，化作一根灯芯被杨戬收了去．\n\n\n"NOR,me);
      destruct(me);
}

